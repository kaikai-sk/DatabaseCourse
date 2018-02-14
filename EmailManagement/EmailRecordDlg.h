#if !defined(AFX_EMAILRECORDDLG_H__744BDF12_B8A0_41A7_9271_A2FD105CC663__INCLUDED_)
#define AFX_EMAILRECORDDLG_H__744BDF12_B8A0_41A7_9271_A2FD105CC663__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmailRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmailRecordDlg dialog

class CEmailRecordDlg : public CDialog
{
// Construction
public:
	CEmailRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmailRecordDlg)
	enum { IDD = IDD_DIALOG_RECORD };
	CStatic	m_Picture;
	CComboBox	m_cbGroup;
	CComboBox	m_cbEtype;
	CComboBox	m_cbContact;
	CString	m_strContact;
	CString	m_strEtype;
	COleDateTime	m_sendDate;
	CString	m_strEmailInfo;
	BOOL	m_isFujian;
	CString	m_strFileName;
	CString	m_strFujianDesc;
	BOOL	m_isRead;
	CString	m_strGroup;
	BOOL	m_isQunfa;
	CString	m_strReceiverSeq;
	BOOL	m_isDraft;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmailRecordDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckFujian();
	afx_msg void OnSetfocusEditFileName();
	afx_msg void OnSetfocusEditFileDesc();
	afx_msg void OnSelchangeComboContact();
	afx_msg void OnSelchangeComboGroup();
	afx_msg void OnKillfocusEditFileName();
	afx_msg void OnBtnUpload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CStringArray m_strReceiverArr;
	void GetRecordID(int RecordID);
	//联系人字符串数组
	CStringArray m_strContactArray;
	//邮件类型字符串数组
	CStringArray m_strTypeArray;
	//组的字符串数组
	CStringArray m_strGroupArr;
private:
	void LoadPic();
	CString GetSuffix(CString strFileName);
	int m_nRecordID;
	bool flag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILRECORDDLG_H__744BDF12_B8A0_41A7_9271_A2FD105CC663__INCLUDED_)
