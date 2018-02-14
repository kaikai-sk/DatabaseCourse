#if !defined(AFX_USERREGISTDLG_H__A6BD727B_2E96_4C9D_93CC_07728FD2A5AD__INCLUDED_)
#define AFX_USERREGISTDLG_H__A6BD727B_2E96_4C9D_93CC_07728FD2A5AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserRegistDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserRegistDlg dialog

class CUserRegistDlg : public CDialog
{
// Construction
public:
	CUserRegistDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserRegistDlg)
	enum { IDD = IDD_DIALOG_USER_REGIST };
	CString	m_strOKPassword;
	CString	m_strPassword;
	CString	m_strUserName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserRegistDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserRegistDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERREGISTDLG_H__A6BD727B_2E96_4C9D_93CC_07728FD2A5AD__INCLUDED_)
