//---------------------------------------------------------------------------

#ifndef SYOperationQueueH
#define SYOperationQueueH
#include <windows.h>
#include <vector>
//---------------------------------------------------------------------------
class SYOperation
{
public:
	virtual	void Main() = 0;
};
//---------------------------------------------------------------------------
class SYOperationQueue
{
public:
     SYOperationQueue();
     ~SYOperationQueue();
     void Start(int count=1);
     void Stop(void);
     void AddOperation(SYOperation *item);
     SYOperation *GetFirstItem(void);
private:
	HANDLE  m_hProcThread;
    std::vector<SYOperation*>* m_pVecQueue;
    int		m_RunMaxCount;	
public:
	bool	flag_Start;
	
};
#endif

