// EmailManagementDlg.h : header file
//

#if !defined(AFX_EMAILMANAGEMENTDLG_H__2429D409_8721_4F65_B07F_4C74E06DD7AE__INCLUDED_)
#define AFX_EMAILMANAGEMENTDLG_H__2429D409_8721_4F65_B07F_4C74E06DD7AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EmailRecordDlg.h"
#include "afxtempl.h"
/////////////////////////////////////////////////////////////////////////////
// CEmailManagementDlg dialog
const CString userNameTear="@sk.mail.com";


class CEmailManagementDlg : public CDialog
{
// Construction
public:
	void ClearAllListsUnless();
	void SetUserTishi(CString name,CString rank);
	CString GetSuffix(CString strFileName);
	void MyExecuteSQL(CString sql);
	void InitFujianListData(CString sql);
	CString m_strCurUser;
	CString m_strPassword;
	CString m_strUserName;
	CString m_strDBSource;
	void ReadRecycleBinInfo(int id, CString name, CString sendDate, int isFujian, CString type, CString emailTxt,CString fujianName);
	CDatabase* GetDB();
	void ReadFujianInfo(int id,CString fujianName,CString fujianDesc);
	void ReadContactGroupInfo(int id,CString groupName,CString groupDesc);
	CEmailManagementDlg(CWnd* pParent = NULL);	// standard constructor
	void GetCurUserIdInfo();
	void CurUserChangeInit();
	CString GetCurUserRank();
	int GetCurUserID();
// Dialog Data
	//{{AFX_DATA(CEmailManagementDlg)
	enum { IDD = IDD_EMAILMANAGEMENT_DIALOG };
	CListCtrl	m_listBlack;
	CListCtrl	m_listRecycleBin;
	CListCtrl	m_listFujian;
	CListCtrl	m_listGroup;
	CListCtrl	m_listRecord;
	CListCtrl	m_listType;
	CListCtrl	m_listContact;
	CString	m_strUserTishi;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailManagementDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEmailManagementDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAddcon();
	afx_msg void OnBtnDelcon();
	afx_msg void OnBtnModcon();
	afx_msg void OnBtnAddtype();
	afx_msg void OnBtnDeltype();
	afx_msg void OnBtnModtype();
	afx_msg void OnBtnSendred();
	afx_msg void OnBtnQueryred();
	afx_msg void OnBtndelred();
	afx_msg void OnButtonTimequery();
	afx_msg void OnBtnGroupAdd();
	afx_msg void OnBtnGroupQuery();
	afx_msg void OnBtnGroupDel();
	afx_msg void OnBtnReaded();
	afx_msg void OnBtnNotread();
	afx_msg void OnBtnMovetoBin();
	afx_msg void OnBtnRestore();
	afx_msg void OnBtnMovetoBlackList();
	afx_msg void OnBtnReturntoContact();
	afx_msg void OnColumnclickListContact(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListEtype(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListRecord(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListRecycleBin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDb();
	afx_msg void OnChangeSkin();
	afx_msg void OnDestroy();
	afx_msg void OnChangeMySkin();
	afx_msg void OnRemoveSkin();
	afx_msg void OnLogOn();
	afx_msg void OnUserRegist();
	afx_msg void OnAllUsers();
	afx_msg void OnClickListFujian(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnReceiveBin();
	afx_msg void OnBtnSendBin();
	afx_msg void OnBtnBlurFind();
	afx_msg void OnNetSendMail();
	afx_msg void OnBtnDraft();
	afx_msg void OnUserCancellation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	void CancelListHigh(CListCtrl m_list);
	int GetNewContactID();
	void ClearAllLists();
	BOOL isInArr(int a,CArray<int,int> *arr);
	void InitContactGroupData(CString sql);
	void InitBlackListData(CString sql);
	void InitRecycleBinData(CString sql);
	void InitFujianListData();
	void InitEmailRecordInfo(CString sql);
	
	void InitContactListData(CString sql);
	void UnSubclassControls();
	BOOL ParsePathPieces(LPCTSTR szFile, LPTSTR szPath, LPTSTR szSkin);
	void ConnDB();
	void ReadBlackListInfo(int blackID,CString blackName,CString blackEmail);
	void InitBlackListData();
	void InitEmailRecordInfo();
	void InitRecycleBinData();
	void InitContactGroupData();
	void InitContactListData();
	void InitEmailTypeData();
	void ReadRecordInfo(CListCtrl &m_list,int id, CString name, CString sendDate, int isFujian, CString type, CString emailTxt,CString fujianName);
	void ReadReadedOrNotEmail(CString sql);
	void callProcedure(CString sql);
	void ReadRecordInfo(int id,CString name,CString sendDate,int isFujian,CString type,CString emailTxt,CString fujianName);
	void ReadTypeInfo(int id,CString typeName);
	void ReadcontactInfo(int id,CString name,CString email,CString group);
	void InitListData();
	void InitListControl();
	CDatabase m_db;
	CArray<int,int> m_CurContactIdArr;
	CArray<int,int> m_CurRecordIdArr;
	CArray<int,int> m_CurFujianIdArr;
	CArray<int,int> m_CurGroupIdArr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILMANAGEMENTDLG_H__2429D409_8721_4F65_B07F_4C74E06DD7AE__INCLUDED_)
