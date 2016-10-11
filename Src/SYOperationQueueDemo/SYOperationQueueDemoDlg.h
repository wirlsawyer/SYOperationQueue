// SYOperationQueueDemoDlg.h : header file
//

#pragma once
#include "SYOperationQueue.h"

// CSYOperationQueueDemoDlg dialog
class CSYOperationQueueDemoDlg : public CDialog
{
// Construction
public:
	CSYOperationQueueDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SYOPERATIONQUEUEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

private:
	SYOperationQueue *m_syQueue;

	afx_msg void OnBnClickedButton2();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton3();
};
