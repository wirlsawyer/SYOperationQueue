//---------------------------------------------------------------------------

#ifndef SYUSBEventOperationH
#define SYUSBEventOperationH
#include "SYOperationQueue.h"
//---------------------------------------------------------------------------
class SYItemOperation : SYOperation
{
public:
  	SYItemOperation(int i);
    ~SYItemOperation();
    void Main(void);
private:
	int m_ID;
};
#endif

