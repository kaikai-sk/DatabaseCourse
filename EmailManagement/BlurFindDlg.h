#if !defined(AFX_BLURFINDDLG_H__D7BA69E8_8335_4714_A439_1E27C5A250FA__INCLUDED_)
#define AFX_BLURFINDDLG_H__D7BA69E8_8335_4714_A439_1E27C5A250FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BlurFindDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBlurFindDlg dialog

class CBlurFindDlg : public CDialog
{
// Construction
public:
	CBlurFindDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBlurFindDlg)
	enum { IDD = IDD_DIALOG_BLUR_FIND };
	int		m_nRecordBlurFindOption;
	CString	m_strKeyEmail;
	CString	m_strKeyName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlurFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBlurFindDlg)
	afx_msg void OnRadioBlurName();
	afx_msg void OnRadioBlurEmail();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLURFINDDLG_H__D7BA69E8_8335_4714_A439_1E27C5A250FA__INCLUDED_)
