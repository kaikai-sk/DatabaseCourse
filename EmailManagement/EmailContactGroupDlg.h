#if !defined(AFX_EMAILCONTACTGROUPDLG_H__52B26C63_7C67_4596_8435_1F959CA3E7CA__INCLUDED_)
#define AFX_EMAILCONTACTGROUPDLG_H__52B26C63_7C67_4596_8435_1F959CA3E7CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmailContactGroupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmailContactGroupDlg dialog
#define ADD TRUE
#define LOOK FALSE

class CEmailContactGroupDlg : public CDialog
{
// Construction
public:
	CEmailContactGroupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmailContactGroupDlg)
	enum { IDD = IDD_DIALOG_GROUP };
	CComboBox	m_cbGroupMember;
	CString	m_strGroupName;
	CString	m_strGroupDesc;
	CString	m_strGroupMember;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailContactGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmailContactGroupDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CStringArray m_strGroupMemArr;
	BOOL m_AddOrLook;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILCONTACTGROUPDLG_H__52B26C63_7C67_4596_8435_1F959CA3E7CA__INCLUDED_)
