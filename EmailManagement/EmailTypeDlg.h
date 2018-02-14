#if !defined(AFX_EMAILTYPEDLG_H__0F4A06FC_DC26_46C9_8303_79CE386532CD__INCLUDED_)
#define AFX_EMAILTYPEDLG_H__0F4A06FC_DC26_46C9_8303_79CE386532CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmailTypeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmailTypeDlg dialog

class CEmailTypeDlg : public CDialog
{
// Construction
public:
	CEmailTypeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmailTypeDlg)
	enum { IDD = IDD_DIALOG_TYPE };
	CString	m_strEmailType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailTypeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmailTypeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILTYPEDLG_H__0F4A06FC_DC26_46C9_8303_79CE386532CD__INCLUDED_)
