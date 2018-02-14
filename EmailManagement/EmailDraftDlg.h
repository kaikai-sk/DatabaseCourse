#if !defined(AFX_EMAILDRAFTDLG_H__CB9B853F_AB62_4DCC_A644_D75EE5810CC8__INCLUDED_)
#define AFX_EMAILDRAFTDLG_H__CB9B853F_AB62_4DCC_A644_D75EE5810CC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmailDraftDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmailDraftDlg dialog

class CEmailDraftDlg : public CDialog
{
// Construction
public:
	void ReadDraftInfo(int recordID,CString strName,CString sendDate,int isFujian,CString strType,CString emailTxt,CString fujianName);
	CEmailDraftDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmailDraftDlg)
	enum { IDD = IDD_DIALOG_DRAFT };
	CListCtrl	m_listDraft;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailDraftDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmailDraftDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitDraftListControl();
	void InitListData();
	void InitListControl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILDRAFTDLG_H__CB9B853F_AB62_4DCC_A644_D75EE5810CC8__INCLUDED_)
