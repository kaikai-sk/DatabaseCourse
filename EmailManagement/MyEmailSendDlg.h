#if !defined(AFX_MYEMAILSENDDLG_H__638B7AEB_9130_4449_9506_88EB2DDA151F__INCLUDED_)
#define AFX_MYEMAILSENDDLG_H__638B7AEB_9130_4449_9506_88EB2DDA151F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEmailSendDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEmailSendDlg dialog

class CMyEmailSendDlg : public CDialog
{
// Construction
public:
	CMyEmailSendDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyEmailSendDlg)
	enum { IDD = IDD_DIALOG_NET_SEND };
	CString	m_strReceiveAddress;
	CString	m_strMyInfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEmailSendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyEmailSendDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEMAILSENDDLG_H__638B7AEB_9130_4449_9506_88EB2DDA151F__INCLUDED_)
