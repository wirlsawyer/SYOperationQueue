//---------------------------------------------------------------------------
#pragma hdrstop
#include "stdafx.h"
#include "SYItemOperation.h"
//---------------------------------------------------------------------------
SYItemOperation::SYItemOperation(int i)
{
	m_ID = i;
}

SYItemOperation::~SYItemOperation()
{

}

void SYItemOperation::Main(void)
{
    wchar_t wszBuf[256];
    memset(wszBuf, 0, sizeof(wszBuf));

    wsprintf(wszBuf, L"ID=%d\n", m_ID);
    OutputDebugString(wszBuf);
    Sleep(200);
}

