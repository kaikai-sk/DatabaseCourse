#if !defined(AFX_CONTACTMANAGEMENT_H__4118E792_ED74_45F7_8370_95763E0E8EBF__INCLUDED_)
#define AFX_CONTACTMANAGEMENT_H__4118E792_ED74_45F7_8370_95763E0E8EBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContactManagement.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContactManagement dialog

class CContactManagement : public CDialog
{
// Construction
public:
	BOOL m_isGroupShow;
	CString m_strHeadPath;
	CStringArray m_strAllGroupArr;
	CContactManagement(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CContactManagement)
	enum { IDD = IDD_DIALOG_CONTACT };
	CStatic	m_headPic;
	CComboBox	m_cbAllGroup;
	CString	m_strCName;
	CString	m_strCEmail;
	CString	m_strContactGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactManagement)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CContactManagement)
	virtual BOOL OnInitDialog();
	afx_msg void OnStaticHeadpic();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void MyLoadPic(CString path);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTACTMANAGEMENT_H__4118E792_ED74_45F7_8370_95763E0E8EBF__INCLUDED_)
