//---------------------------------------------------------------------------
#pragma hdrstop
#include "stdafx.h"
#include "SYOperationQueue.h"
//#include <process.h>    /* _beginthread, _endthread */

//---------------------------------------------------------------------------
SYOperationQueue::SYOperationQueue()
{
//2013.02.24
	m_hProcThread = NULL;

    m_pVecQueue = new std::vector<SYOperation*>;
    m_RunMaxCount = 0;
    flag_Start    = false;
	
}

SYOperationQueue::~SYOperationQueue()
{
//2013.02.24
	//flag_Start = false;
	this->Stop();
	/*
    LPDWORD ExitCode;

	while (true)
	{
		GetExitCodeThread(m_hProcThread, ExitCode);

		if(ExitCode != STILL_ACTIVE){
			break;
		}
	}
	
*/

	
	

	if (m_pVecQueue)
	{
		//clear
		while(!m_pVecQueue->empty())
		{
			delete m_pVecQueue->back();
			m_pVecQueue->pop_back();
		}
		delete m_pVecQueue;
	}

}

DWORD WINAPI ProcessProcThread(void *pParam)
{
//2013.02.24
	SYOperationQueue *pThis =  (SYOperationQueue*)pParam;
    pThis->flag_Start = true;
	
    while (true)
    {
    	if (pThis->flag_Start == false) break;
    	SYOperation *pOperation = pThis->GetFirstItem();

    	if (pOperation == NULL)
        {
        	Sleep(10);
    	}else{
           pOperation->Main();
           delete pOperation;
        }
    }//end while
    pThis->flag_Start = false;
	//pThis->Stop();//m_hProcThread = NULL;//不這樣會有Memory leak!
    return 0;
}

void SYOperationQueue::Start(int count)
{
//2013.02.24
	m_RunMaxCount = count;

	this->Stop();

    //clear
   	while(!m_pVecQueue->empty())
   	{
   		delete m_pVecQueue->back();
   		m_pVecQueue->pop_back();
   	}

    m_hProcThread = CreateThread(NULL, 0, ProcessProcThread, this, 0, NULL);
	//m_hProcThread = (HANDLE)_beginthreadex( NULL, 0, &ProcessProcThread, this, 0, NULL);


}

void SYOperationQueue::Stop(void)
{
//2013.02.24
	flag_Start = false;
	if (m_hProcThread)
	{
		WaitForSingleObject(m_hProcThread, INFINITE);
		CloseHandle(m_hProcThread);
		m_hProcThread = NULL;
	}
}

void SYOperationQueue::AddOperation(SYOperation *item)
{
//2013.02.24
 	m_pVecQueue->push_back(item);
}

SYOperation *SYOperationQueue::GetFirstItem(void)
{
//2013.02.24
	if (m_pVecQueue->empty()) return NULL;
    SYOperation *pResult;
   	pResult = m_pVecQueue->at(0);
	m_pVecQueue->erase(m_pVecQueue->begin());
    return pResult;
}


