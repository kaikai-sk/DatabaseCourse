#if !defined(AFX_DBCONNDLG_H__8D875DC9_22BB_487A_B46D_0E167141EAEA__INCLUDED_)
#define AFX_DBCONNDLG_H__8D875DC9_22BB_487A_B46D_0E167141EAEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DBConnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDBConnDlg dialog

class CDBConnDlg : public CDialog
{
// Construction
public:
	CDBConnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDBConnDlg)
	enum { IDD = IDD_DIALOG_DB };
	CString	m_strDBSource;
	CString	m_strPassword;
	CString	m_strUserName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBConnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDBConnDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBCONNDLG_H__8D875DC9_22BB_487A_B46D_0E167141EAEA__INCLUDED_)
