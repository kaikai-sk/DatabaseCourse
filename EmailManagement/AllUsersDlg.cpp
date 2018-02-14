// AllUsersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "AllUsersDlg.h"

#include "EmailManagementDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllUsersDlg dialog


CAllUsersDlg::CAllUsersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllUsersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllUsersDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAllUsersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllUsersDlg)
	DDX_Control(pDX, IDC_LIST_ALL_USERS, m_listAllUsers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllUsersDlg, CDialog)
	//{{AFX_MSG_MAP(CAllUsersDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ALL_USERS, OnDblclkListAllUsers)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllUsersDlg message handlers

void CAllUsersDlg::InitListControl()
{
		DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_UNDERLINEHOT;
		m_listAllUsers.SetExtendedStyle(dwExStyle);
		CRect rect;
		GetDlgItem(IDC_LIST_ALL_USERS)->GetWindowRect(&rect);
		//初始化所有用户列表控件
		m_listAllUsers.InsertColumn(0,"用户ID",LVCFMT_CENTER,rect.Width()/3);
	    m_listAllUsers.InsertColumn(1,"用户姓名",LVCFMT_CENTER,rect.Width()/3);
	    m_listAllUsers.InsertColumn(2,"用户密码",LVCFMT_CENTER,rect.Width()/3);
}

void CAllUsersDlg::InitListData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=((CEmailManagementDlg*)(GetParent()))->GetDB();
		CString sql;

		//向附件管理列表中初始化值
		sql="select * from EMAIL_USER";
		rs.Open(CRecordset::dynaset,sql);
		int userID;
		CString userName,userCode;
		while(!rs.IsEOF())
		{
			userID=-1;
			userName="";
			userCode="";

			CDBVariant var;
			//获取附件id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				userID=var.m_iVal;
			var.Clear();
			//获取附件名字段值
			rs.GetFieldValue(1,userName);
			//获取附件备注
			rs.GetFieldValue(2,userCode);
			ReadAllUserInfo(userID,userName,userCode);
			rs.MoveNext();
		}
		rs.Close();		
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CMemoryException,pEx)
	{
		pEx->ReportError();
		AfxMessageBox("memory exception");
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH
}

void CAllUsersDlg::ReadAllUserInfo(int userID, CString userName, CString userCode)
{
	//获得当前的记录数
	int nIndex=m_listAllUsers.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",userID);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_listAllUsers.InsertItem(&lvItem);
	m_listAllUsers.SetItemText(nIndex,1,userName);
	m_listAllUsers.SetItemText(nIndex,2,userCode);
}

BOOL CAllUsersDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitListControl();
	InitListData();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllUsersDlg::OnDblclkListAllUsers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION Pos = m_listAllUsers.GetFirstSelectedItemPosition();
    int nSelect = -1;
    while ( Pos )
    {
        nSelect = m_listAllUsers.GetNextSelectedItem(Pos);    //nSelect能获得第几行
    }
	char szFirstTrunk[60] = { 0 };
    m_listAllUsers.GetItemText(nSelect,1, szFirstTrunk, 60);  //获得想要的列值给szFirstTrunk*/
	((CEmailManagementDlg*)GetParent())->UpdateData(true);
	((CEmailManagementDlg*)GetParent())->m_strCurUser=szFirstTrunk;
	((CEmailManagementDlg*)GetParent())->m_strUserTishi="当前用户："+((CEmailManagementDlg*)GetParent())->m_strCurUser+" ";
	((CEmailManagementDlg*)GetParent())->m_strUserTishi=((CEmailManagementDlg*)GetParent())->m_strUserTishi+"用户等级："+((CEmailManagementDlg*)GetParent())->GetCurUserRank();
	((CEmailManagementDlg*)GetParent())->GetCurUserIdInfo();
	((CEmailManagementDlg*)GetParent())->CurUserChangeInit();
	((CEmailManagementDlg*)GetParent())->UpdateData(false);
	*pResult = 0;
}
