#if !defined(AFX_ALLUSERSDLG_H__ECEB2B0B_6946_40EE_815E_C46367EE8F6C__INCLUDED_)
#define AFX_ALLUSERSDLG_H__ECEB2B0B_6946_40EE_815E_C46367EE8F6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllUsersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllUsersDlg dialog

class CAllUsersDlg : public CDialog
{
// Construction
public:
	CAllUsersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllUsersDlg)
	enum { IDD = IDD_DIALOG_ALL_USER };
	CListCtrl	m_listAllUsers;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllUsersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllUsersDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListAllUsers(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ReadAllUserInfo(int userID,CString userName,CString userCode);
	void InitListData();
	void InitListControl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLUSERSDLG_H__ECEB2B0B_6946_40EE_815E_C46367EE8F6C__INCLUDED_)
