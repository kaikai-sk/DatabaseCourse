// EmailManagementDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "EmailManagementDlg.h"

#include "ContactManagement.h"
#include "EmailTypeDlg.h"
#include "EmailRecordDlg.h"
#include "TimeQueryDlg.h"
#include "EmailContactGroupDlg.h"
#include "DBConnDlg.h"
#include "UserLogon.h"
#include "UserRegistDlg.h"
#include "AllUsersDlg.h"
#include "BlurFindDlg.h"
#include "Base64Date6.h"
#include "EmailDraftDlg.h"
#include "MyEmailSendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
const CString dir="F:\\数据库课程设计\\image\\";

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementDlg dialog

CEmailManagementDlg::CEmailManagementDlg(CWnd* pParent /*=NULL*/)
: CDialog(CEmailManagementDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmailManagementDlg)
	m_strUserTishi = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_EMAIL);
	
	m_strDBSource="ORCLClient";
	m_strUserName="scott";
	m_strPassword="955219Sh";
}

void CEmailManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmailManagementDlg)
	DDX_Control(pDX, IDC_LIST_BLACK, m_listBlack);
	DDX_Control(pDX, IDC_LIST_RECYCLE_BIN, m_listRecycleBin);
	DDX_Control(pDX, IDC_LIST_FUJIAN, m_listFujian);
	DDX_Control(pDX, IDC_LIST_GROUP, m_listGroup);
	DDX_Control(pDX, IDC_LIST_RECORD, m_listRecord);
	DDX_Control(pDX, IDC_LIST_ETYPE, m_listType);
	DDX_Control(pDX, IDC_LIST_CONTACT, m_listContact);
	DDX_Text(pDX, IDC_STATIC_TISHI, m_strUserTishi);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEmailManagementDlg, CDialog)
//{{AFX_MSG_MAP(CEmailManagementDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BTN_ADDCON, OnBtnAddcon)
ON_BN_CLICKED(IDC_BTN_DELCON, OnBtnDelcon)
ON_BN_CLICKED(IDC_BTN_MODCON, OnBtnModcon)
ON_BN_CLICKED(IDC_BTN_ADDTYPE, OnBtnAddtype)
ON_BN_CLICKED(IDC_BTN_DELTYPE, OnBtnDeltype)
ON_BN_CLICKED(IDC_BTN_MODTYPE, OnBtnModtype)
ON_BN_CLICKED(IDC_BTN_SENDRED, OnBtnSendred)
ON_BN_CLICKED(IDC_BTN_QUERYRED, OnBtnQueryred)
ON_BN_CLICKED(IDC_BTNDELRED, OnBtndelred)
ON_BN_CLICKED(IDC_BUTTON_TIMEQUERY, OnButtonTimequery)
ON_BN_CLICKED(IDC_BTN_GROUP_ADD, OnBtnGroupAdd)
ON_BN_CLICKED(IDC_BTN_GROUP_QUERY, OnBtnGroupQuery)
ON_BN_CLICKED(IDC_BTN_GROUP_DEL, OnBtnGroupDel)
ON_BN_CLICKED(IDC_BTN_READED, OnBtnReaded)
ON_BN_CLICKED(IDC_BTN_NOTREAD, OnBtnNotread)
ON_BN_CLICKED(IDC_BTN_MOVETO_BIN, OnBtnMovetoBin)
ON_BN_CLICKED(IDC_BTN_RESTORE, OnBtnRestore)
ON_BN_CLICKED(IDC_BTN_MOVETO_BLACK_LIST, OnBtnMovetoBlackList)
ON_BN_CLICKED(IDC_BTN_RETURNTO_CONTACT, OnBtnReturntoContact)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_CONTACT, OnColumnclickListContact)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_ETYPE, OnColumnclickListEtype)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_RECORD, OnColumnclickListRecord)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_RECYCLE_BIN, OnColumnclickListRecycleBin)
ON_COMMAND(IDM_DB, OnDb)
ON_WM_DESTROY()
ON_COMMAND(IDM_CHANGE_MY_SKIN, OnChangeMySkin)
ON_COMMAND(IDM_REMOVE_SKIN, OnRemoveSkin)
ON_COMMAND(IDM_LOG_ON, OnLogOn)
ON_COMMAND(IDM_USER_REGIST, OnUserRegist)
ON_COMMAND(IDM_ALL_USERS, OnAllUsers)
ON_NOTIFY(NM_CLICK, IDC_LIST_FUJIAN, OnClickListFujian)
ON_BN_CLICKED(IDC_BTN_RECEIVE_BIN, OnBtnReceiveBin)
ON_BN_CLICKED(IDC_BTN_SEND_BIN, OnBtnSendBin)
ON_BN_CLICKED(IDC_BTN_BLUR_FIND, OnBtnBlurFind)
ON_COMMAND(IDM_NET_SEND_MAIL, OnNetSendMail)
	ON_BN_CLICKED(IDC_BTN_DRAFT, OnBtnDraft)
	ON_COMMAND(IDM_USER_CANCELLATION, OnUserCancellation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementDlg message handlers

BOOL CEmailManagementDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitListControl();
	//连接到数据库
	ConnDB();
	
	CMenu *menu = new CMenu;
	menu ->LoadMenu(MAKEINTRESOURCE(IDR_MENU_YOUJIAN)); //IDR_MENU 菜单ID
	this ->SetMenu(menu);
	
	//显示当前用户及等级
	UpdateData(true);
	CString tmepUser;
	if(""==m_strCurUser)
	{
		tmepUser="万能的管理员";
		m_strUserTishi="当前用户："+tmepUser+" ";
		m_strUserTishi=m_strUserTishi+"用户等级："+"super vip";
	}
	UpdateData(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEmailManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEmailManagementDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEmailManagementDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//连接到数据库
void CEmailManagementDlg::ConnDB()
{
	if(m_db.IsOpen())
	{
		AfxMessageBox("数据库已经连接");
		return;
	}
	if(m_strDBSource.IsEmpty()||m_strUserName.IsEmpty()||m_strPassword.IsEmpty())
	{
		AfxMessageBox("数据库配置参数不能够为空");
		return;
	}
	CString strConnect;
	strConnect.Format("DSN=%s;UID=%s;PWD=%s;QTO=F",m_strDBSource,m_strUserName,m_strPassword);
    TRY
	{
		m_db.OpenEx(strConnect,CDatabase::noOdbcDialog);
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
		InitListData();
}

//获得联系人ID的最大值
int CEmailManagementDlg::GetNewContactID()
{
	TRY
	{
		CRecordset rs(&m_db);
		rs.Open(CRecordset::dynaset,"select max(contact_id) from contact_info_tab");
		
		//设置新添加记录的联系人的ID值
		int newContactID=1;
		//如果数据库里面有记录了，则新的联系人ID=联系人的ID最大值加1
		if(!rs.IsEOF())
		{
			CDBVariant var;
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				newContactID=var.m_iVal+1;
			}
		}
		rs.Close();
		return newContactID;
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
		return -1;
}

//执行sql语句
void CEmailManagementDlg::MyExecuteSQL(CString sql)
{
	TRY
	{
		TRACE(sql);
		m_db.ExecuteSQL(sql);
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

//插入联系人的信息
void CEmailManagementDlg::OnBtnAddcon() 
{
	//创建一个联系人对话框实例
	CContactManagement dlg;
	
	//如果此用户并没有联系人分组
	if(m_listGroup.GetItemCount()==0)
	{
		dlg.m_isGroupShow=false;
	}
	
	CString sql;
	CString tempGroupName;
	
	//为下拉框填充值
	CRecordset rs2;
	rs2.m_pDatabase=&m_db;
	if(m_strCurUser=="")
	{
		sql.Format("select * from contact_group");
	}
	else
	{
		sql.Format("select * from contact_group where group_id in(select group_id from user_own where user_id=%d)",GetCurUserID());
	}
	rs2.Open(CRecordset::dynaset,sql);
	while(!rs2.IsEOF())
	{
		rs2.GetFieldValue(1,tempGroupName);
		dlg.m_strAllGroupArr.Add(tempGroupName);
		rs2.MoveNext();
	}
	rs2.Close();
	
	if(dlg.DoModal()==IDOK)
	{
		//从对话框中获取姓名和Email参数
		CString strName=dlg.m_strCName;
		CString strEmail=dlg.m_strCEmail;
		CString strPath=dlg.m_strHeadPath;
		
		//非法输入的预处理
		if(""==strName || ""==strEmail)
		{
			MessageBox("用户名或邮件地址不能为空！");
			return;
		}
		
		TRY
		{
			//打开记录集
			int tempGroupID=0;
			CRecordset rs(&m_db);
			rs.Open(CRecordset::dynaset,"select max(contact_id) from contact_info_tab");
			
			//设置新添加记录的联系人的ID值
			int newContactID=1;
			//如果数据库里面有记录了，则新的联系人ID=联系人的ID最大值加1
			if(!rs.IsEOF())
			{
				CDBVariant var;
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					newContactID=var.m_iVal+1;
				}
			}
			rs.Close();
			
            if(dlg.m_strContactGroup!="")
			{
				//获得要添加的组的联系人的id
				sql.Format("select * from contact_group where GROUP_NAME='%s'",dlg.m_strContactGroup);
				rs.Open(CRecordset::dynaset,sql);
				while(!rs.IsEOF())
				{
					CDBVariant var;
					rs.GetFieldValue((short)0,var,SQL_C_SLONG);
					if(var.m_dwType!=DBVT_NULL)
					{
						tempGroupID=var.m_iVal;
					}
					rs.MoveNext();
				}
				rs.Close();

				if(0==tempGroupID)
				{
					MessageBox("联系人的分组并不存在，请您检查之");
					return;
				}
			}

			//创建插入新联系人记录的字符串
			CString sql;
			sql.Format("insert into contact_info_tab(contact_id,""contact_name,e_mail,GROUP_ID,IS_BLACK,HEAD_PIC_PATH) \
				values(""%d,'%s','%s','%d',%d,'%s')",newContactID,strName,strEmail,tempGroupID,0,strPath);
			TRACE(sql);
			//新的联系人记录插入到数据库中
			m_db.ExecuteSQL(sql);
			if(m_strCurUser!="")
			{
			sql.Format("insert into user_own(USER_ID,CONTACT_ID,RECORD_ID,GROUP_ID,FUJIAN_ID) \
				values(%d,%d,%d,%d,%d)",GetCurUserID(),newContactID,0,tempGroupID,0,0);
			TRACE(sql);
			//新的联系人记录插入到数据库中
			m_db.ExecuteSQL(sql);
			}
			//把新的联系人记录的信息显示在列表控件中
			ReadcontactInfo(newContactID,strName,strEmail,dlg.m_strContactGroup);
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}
	else
	{
		return;
	}
}

//插入组的信息
void CEmailManagementDlg::OnBtnGroupAdd() 
{
	//创建一个联系人对话框实例
	CEmailContactGroupDlg dlg;
	dlg.m_AddOrLook=ADD;
	if(dlg.DoModal()==IDOK)
	{
		//从对话框中获取姓名和Email参数
		CString strName=dlg.m_strGroupName;
		CString strDesc=dlg.m_strGroupDesc;

		if(""==strName || ""==strDesc)
		{
			MessageBox("组名或组备注不能为空");
			return;
		}

		TRY
		{
			//打开记录集
			CRecordset rs(&m_db);
			rs.Open(CRecordset::dynaset,"select max(group_id) from contact_group");
			//设置新添加记录的联系人的ID值
			int newGroupID=1;
			//如果数据库里面有记录了，则新的联系人ID=联系人的ID最大值加1
			if(!rs.IsEOF())
			{
				CDBVariant var;
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					newGroupID=var.m_iVal+1;
				}
			}
			//创建插入新联系人记录的字符串
			CString sql;
			sql.Format("insert into contact_group(group_id,""group_name,group_desc)""values(""%d,'%s','%s')",newGroupID,strName,strDesc);
			TRACE(sql);
			//新的联系人记录插入到数据库中
			m_db.ExecuteSQL(sql);
			if(m_strCurUser!="")
			{
				sql.Format("insert into user_own(USER_ID,CONTACT_ID,RECORD_ID,GROUP_ID) values(%d,0,0,%d)",GetCurUserID(),newGroupID);
				TRACE(sql);
				m_db.ExecuteSQL(sql);
			}
			//把新的联系人记录的信息显示在列表控件中
			ReadContactGroupInfo(newGroupID,strName,strDesc);
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}
}


//删除联系人的信息
void CEmailManagementDlg::OnBtnDelcon() 
{
	if(IDOK==MessageBox("您确定要删除这个联系人吗？，您关于此联系人的记录也会删除！","警告",MB_OKCANCEL))
	{
		//获取要删除的联系人的记录所在的行
		int cItem=m_listContact.GetNextItem(-1,LVNI_SELECTED);
		if(cItem==-1)
		{
			AfxMessageBox("没有选中要删除的联系人！");
			return;
		}
		//获得要删除的联系人的id
		int id=atoi(m_listContact.GetItemText(cItem,0));
		TRY
		{
			CString sql;
			//查询到此条记录的

			//从数据库中删除记录
			sql.Format("delete contact_info_tab where contact_id=%d",id);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
             
			//删除用户的相关记录
			sql.Format("delete user_own where contact_id=%d and user_id=%d",id,GetCurUserID());
			TRACE(sql);
			m_db.ExecuteSQL(sql);
			
			//从列表控件中删除该记录
			m_listContact.DeleteItem(cItem);
			GetCurUserIdInfo();
			CurUserChangeInit();
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}
	else
	{
		MessageBox("联系人并未删除！");
	}
}

//修改联系人的信息
void CEmailManagementDlg::OnBtnModcon() 
{
	//选择要修改的记录项
	int cItem=m_listContact.GetNextItem(-1,LVNI_SELECTED);
	if(cItem==-1)
	{
		AfxMessageBox("没有选中要修改的联系人！");
		return;
	}
	//获得第cItem行中的信息
	int id=atoi(m_listContact.GetItemText(cItem,0));
	CString name=m_listContact.GetItemText(cItem,1);
	CString strEmail=m_listContact.GetItemText(cItem,2);
	//创建联系人对话框实例
	CContactManagement dlg;
	dlg.m_strCName=name;
	dlg.m_strCEmail=strEmail;
	
	TRY
	{
		CString sql;
		CString path;
		
		CRecordset rs(&m_db);
		sql.Format("select * from contact_info_tab where CONTACT_ID=%d",id);
		rs.Open(CRecordset::dynaset,sql);
		if(!rs.IsEOF())
		{
			rs.GetFieldValue(5,dlg.m_strHeadPath);
		}
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH;
	
	//为下拉框填充值
	CString sql,tempGroupName;
	CRecordset rs2;
	rs2.m_pDatabase=&m_db;
	if(m_strCurUser=="")
	{
		sql.Format("select * from contact_group");
	}
	else
	{
		sql.Format("select * from contact_group where group_id in(select group_id from user_own where user_id=%d)",GetCurUserID());
	}
	rs2.Open(CRecordset::dynaset,sql);
	while(!rs2.IsEOF())
	{
		rs2.GetFieldValue(1,tempGroupName);
		dlg.m_strAllGroupArr.Add(tempGroupName);
		rs2.MoveNext();
	}
	rs2.Close();
	
	//打开联系人对话框进行修改
	if(dlg.DoModal()==IDOK)
	{
		//从对话框中获取姓名和Email参数
		CString strName=dlg.m_strCName;
		CString strEmail=dlg.m_strCEmail;

		if(""==strName || ""==strEmail)
		{
			MessageBox("姓名或邮件地址不能为空","提示");
			return;
		}

		TRY
		{
			CString sql;
			
			//查找要添加的组的id
			int tempGroupID=0;
			CRecordset rs(&m_db);
			sql.Format("select * from contact_group where group_name='%s'",dlg.m_strContactGroup);
			rs.Open(CRecordset::dynaset,sql);
			if(!rs.IsEOF())
			{
				CDBVariant var;
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					tempGroupID=var.m_iVal;
				}
			}
			rs.Close();
			
			if(0==tempGroupID)
			{
				MessageBox("此分组并不存在，请检查之！","提示");
				return;
			}

			//修改数据库相应的记录
			sql.Format("update contact_info_tab set contact_name='%s',e_mail='%s',GROUP_ID=%d,HEAD_PIC_PATH='%s' where contact_id=%d",strName,strEmail,tempGroupID,dlg.m_strHeadPath,id);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
			//修改列表控件的值
			m_listContact.SetItemText(cItem,1,strName);
			m_listContact.SetItemText(cItem,2,strEmail);
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}
}

void CEmailManagementDlg::OnBtnAddtype() 
{
	//创建一个类型对话框实例
	CEmailTypeDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		//从对话框中获取Email类型参数
		CString strEmailType=dlg.m_strEmailType;
		TRY
		{
			//打开记录集
			CRecordset rs(&m_db);
			rs.Open(CRecordset::dynaset,"select max(type_id) from email_type_tab");
			//设置新添加记录的联系人的ID值
			int newTypeID=1;
			//如果数据库里面有记录了，则新的联系人ID=联系人的ID最大值加1
			if(!rs.IsEOF())
			{
				CDBVariant var;
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					newTypeID=var.m_iVal+1;
				}
			}
			//创建插入新联系人记录的字符串
			CString sql;
			sql.Format("insert into email_type_tab(type_id,TYPE_NAME) values(%d,'%s')",newTypeID,strEmailType);
			TRACE(sql);
			//新的邮件类型记录插入到数据库中
			m_db.ExecuteSQL(sql);
			//把新的邮件类型记录的信息显示在列表控件中
			ReadTypeInfo(newTypeID,strEmailType);
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}	
}

void CEmailManagementDlg::OnBtnDeltype() 
{
	//获取要删除的邮件类型的记录所在的行
	int cItem=m_listType.GetNextItem(-1,LVNI_SELECTED);
	if(cItem==-1)
	{
		AfxMessageBox("没有选中要删除的联系人！");
		return;
	}
	//获得要删除的联系人的id
	int id=atoi(m_listType.GetItemText(cItem,0));
	TRY
	{
		CString sql;
		//从数据库中删除记录
		sql.Format("delete email_type_tab where TYPE_ID=%d",id);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		//从列表控件中删除该记录
		m_listType.DeleteItem(cItem);
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH;
}

//删除一个分组
void CEmailManagementDlg::OnBtnGroupDel() 
{
	//获取要删除的邮件类型的记录所在的行
	int cItem=m_listGroup.GetNextItem(-1,LVNI_SELECTED);
	if(cItem==-1)
	{
		AfxMessageBox("没有选中要删除的联系人！");
		return;
	}
	//获得要删除的组的id
	int groupID=atoi(m_listGroup.GetItemText(cItem,0));
	if(MessageBox("您确定要删除联系人吗？","提示",MB_OKCANCEL)!=IDOK)
	{
		return;
	}
	TRY
	{
		CString sql;
		
		//有好提示
		if(MessageBox("删除分组可能会涉及到修改联系人信息，你确定吗？","提示")!=IDOK)
		{
			GetDlgItem(IDC_LIST_GROUP)->SetFocus();
			return;
		}
		
		//修改联系人列表中的groupID;
		sql.Format("update contact_info_tab set GROUP_ID=null where GROUP_ID=%d",groupID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		
		//从数据库中删除记录
		sql.Format("delete contact_group where GROUP_ID=%d",groupID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		if(m_strCurUser!="")
		{
			sql.Format("delete user_own where GROUP_ID=%d",groupID);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
		}
		//从列表控件中删除该记录
		m_listGroup.DeleteItem(cItem);
		GetCurUserIdInfo();
		CurUserChangeInit();
	}
	CATCH(CDBException,ex)
	{
		AfxMessageBox(ex->m_strError);
		AfxMessageBox(ex->m_strStateNativeOrigin);
	}
	AND_CATCH(CException,e)
	{
		TCHAR szError[100];
		e->GetErrorMessage(szError,100);
		AfxMessageBox(szError);
	}
	END_CATCH;		
}

void CEmailManagementDlg::OnBtnModtype() 
{
	//选择要修改的记录项
	int cItem=m_listType.GetNextItem(-1,LVNI_SELECTED);
	if(cItem==-1)
	{
		AfxMessageBox("没有选中要修改的联系人！");
		return;
	}
	//获得第cItem行中的信息
	int id=atoi(m_listType.GetItemText(cItem,0));
	CString strEmailType=m_listType.GetItemText(cItem,1);
	//创建联系人对话框实例
	CEmailTypeDlg dlg;
	dlg.m_strEmailType=strEmailType;
	//打开联系人对话框进行修改
	if(dlg.DoModal()==IDOK)
	{
		//从对话框中获取姓名和Email类型参数
		CString strEmailType=dlg.m_strEmailType;
		TRY
		{
			CString sql;
			//修改数据库相应的记录
			sql.Format("update email_type_tab set TYPE_NAME='%s' where TYPE_ID=%d",strEmailType,id);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
			//修改列表控件的值
			m_listType.SetItemText(cItem,1,strEmailType);
		}
		CATCH(CDBException,ex)
		{
			AfxMessageBox(ex->m_strError);
			AfxMessageBox(ex->m_strStateNativeOrigin);
		}
		AND_CATCH(CException,e)
		{
			TCHAR szError[100];
			e->GetErrorMessage(szError,100);
			AfxMessageBox(szError);
		}
		END_CATCH;
	}		
}

//清空所有的列表控件
void CEmailManagementDlg::ClearAllLists()
{
	m_listContact.DeleteAllItems();
	m_listRecord.DeleteAllItems();
	m_listType.DeleteAllItems();
	m_listGroup.DeleteAllItems();
	m_listFujian.DeleteAllItems();
	m_listRecycleBin.DeleteAllItems();
	m_listBlack.DeleteAllItems();
}

//除邮件类型列表控件外全部清空
void CEmailManagementDlg::ClearAllListsUnless()
{
	m_listContact.DeleteAllItems();
	m_listRecord.DeleteAllItems();
	m_listGroup.DeleteAllItems();
	m_listFujian.DeleteAllItems();
	m_listRecycleBin.DeleteAllItems();
	m_listBlack.DeleteAllItems();
}

void CEmailManagementDlg::InitListControl()
{
	//设置列表控件的拓展风格
	DWORD dwExStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_UNDERLINEHOT;
	m_listContact.SetExtendedStyle(dwExStyle);
	m_listRecord.SetExtendedStyle(dwExStyle);
	m_listType.SetExtendedStyle(dwExStyle);
	m_listGroup.SetExtendedStyle(dwExStyle);
	m_listFujian.SetExtendedStyle(dwExStyle);
	m_listRecycleBin.SetExtendedStyle(dwExStyle);
	m_listBlack.SetExtendedStyle(dwExStyle);
	
	//初始化联系人列表控件
	m_listContact.InsertColumn(0,"ID",LVCFMT_CENTER,30);
	m_listContact.InsertColumn(1,"姓名",LVCFMT_CENTER,70);
	m_listContact.InsertColumn(2,"E-mail",LVCFMT_CENTER,80);
	m_listContact.InsertColumn(3,"所在组",LVCFMT_CENTER,100);
	
	//初始化邮件记录列表控件
	m_listRecord.InsertColumn(0,"记录 ID",LVCFMT_CENTER,60);
	m_listRecord.InsertColumn(1,"姓名",LVCFMT_CENTER,60);
	m_listRecord.InsertColumn(2,"邮件发送日期",LVCFMT_CENTER,140);
	m_listRecord.InsertColumn(3,"添加附件",LVCFMT_CENTER,60);
	m_listRecord.InsertColumn(4,"邮件类型",LVCFMT_CENTER,60);
	m_listRecord.InsertColumn(5,"邮件内容",LVCFMT_CENTER,200);
	m_listRecord.InsertColumn(6,"附件名",LVCFMT_CENTER,140);
	
	//初始化邮件类型列表控件
	m_listType.InsertColumn(0,"类型 ID",LVCFMT_CENTER,60);
	m_listType.InsertColumn(1,"邮件类型",LVCFMT_CENTER,100);
	
	//初始化联系人分组列表控件
	m_listGroup.InsertColumn(0,"组 ID",LVCFMT_CENTER,55);
	m_listGroup.InsertColumn(1,"组名",LVCFMT_CENTER,55);
	m_listGroup.InsertColumn(2,"组备注",LVCFMT_CENTER,55);
	
	//初始化附件管理列表控件
	m_listFujian.InsertColumn(0,"附件ID",LVCFMT_CENTER,55);
	m_listFujian.InsertColumn(1,"附件名",LVCFMT_CENTER,50);
	m_listFujian.InsertColumn(2,"附件描述",LVCFMT_CENTER,60);
	
	//初始化回收站列表控件
	m_listRecycleBin.InsertColumn(0,"记录 ID",LVCFMT_CENTER,60);
	m_listRecycleBin.InsertColumn(1,"姓名",LVCFMT_CENTER,60);
	m_listRecycleBin.InsertColumn(2,"邮件发送日期",LVCFMT_CENTER,140);
	m_listRecycleBin.InsertColumn(3,"添加附件",LVCFMT_CENTER,60);
	m_listRecycleBin.InsertColumn(4,"邮件类型",LVCFMT_CENTER,60);
	m_listRecycleBin.InsertColumn(5,"邮件内容",LVCFMT_CENTER,200);
	m_listRecycleBin.InsertColumn(6,"附件名",LVCFMT_CENTER,140);
	
	//初始化黑名单列表控件
	m_listBlack.InsertColumn(0,"ID",LVCFMT_CENTER,60);
	m_listBlack.InsertColumn(1,"姓名",LVCFMT_CENTER,60);
	m_listBlack.InsertColumn(2,"E-mail",LVCFMT_CENTER,60);
}

//查看已读邮件的函数响应
void CEmailManagementDlg::OnBtnReaded() 
{
	m_listRecord.DeleteAllItems();
	CString sql;
	if(m_strCurUser=="")
	{
		sql="select * from view_email_readed";
	}
	else
	{
		sql.Format("select * from view_email_readed where record_id in (select record_id from user_own where user_id=%d)",\
			GetCurUserID());
	}
	ReadReadedOrNotEmail(sql);
}

//参看未读邮件的函数响应
void CEmailManagementDlg::OnBtnNotread() 
{
	m_listRecord.DeleteAllItems();
	CString sql;
	if(m_strCurUser=="")
	{
		sql="select * from view_email_notread";
	}
	else
	{
		sql.Format("select * from view_email_notread where record_id in (select record_id from user_own where user_id=%d)",\
			GetCurUserID());
	}
	ReadReadedOrNotEmail(sql);
}

//供查询已读未读邮件所使用的函数
void CEmailManagementDlg::ReadReadedOrNotEmail(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		
		rs.Open(CRecordset::dynaset,sql);
		int id,isFujian;
		CString contactName,sendDate,typeName,emailInfo,fujianName;
		
		while(!rs.IsEOF())
		{
			id=-1;	isFujian=-1;
			contactName="";		sendDate="";	typeName="";	emailInfo="";	fujianName="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				id=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,contactName);
			rs.GetFieldValue(2,sendDate);
			rs.GetFieldValue((short)3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				isFujian=var.m_iVal;
			var.Clear();
			rs.GetFieldValue(4,typeName);
			rs.GetFieldValue(5,emailInfo);
			rs.GetFieldValue(6,fujianName);
			ReadRecordInfo(id,contactName,sendDate,isFujian,typeName,emailInfo,fujianName);
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

//初始化邮件类型列表控件的数据
void CEmailManagementDlg::InitEmailTypeData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		int id;
		CString typeName;
		
		//向邮件类型列表控件中添加邮件类型信息
		sql="select * from email_type_tab";
		//获取邮件类型的记录集
		rs.Open(CRecordset::dynaset,sql);
		while(!rs.IsEOF())
		{
			CDBVariant var;
			//获取邮件类型id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				id=var.m_iVal;
			var.Clear();
			//获取邮件类型名称字段值
			rs.GetFieldValue(1,typeName);
			//在邮件类型列表控件中加入新的记录信息
			ReadTypeInfo(id,typeName);
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

//初始化联系人信息列表控件的数据(带参)
void CEmailManagementDlg::InitContactListData(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		/*CString sql;*/
		
		//添加联系人基本记录信息
		/*sql="select * from contact_info_tab where IS_BLACK=0 or IS_BLACK is null";*/
		//获取邮件联系人的记录集
		rs.Open(CRecordset::dynaset,sql);
		int id,groupID;
		CString name,email,TempGroup;
		while(!rs.IsEOF())
		{
			groupID=-1;
			TempGroup="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				id=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,name);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,email);
			//获取联系人所在组的id;
			rs.GetFieldValue((short)3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
			{
				groupID=var.m_iVal;
			}
			else
			{
				groupID=NULL;
			}
			var.Clear();
			
			CRecordset rs2(&m_db);
			CString sql2;
			sql2.Format("select * from contact_group where group_id=%d",groupID);
			rs2.Open(CRecordset::dynaset,sql2);
			while(!rs2.IsEOF())
			{
				rs2.GetFieldValue(1,TempGroup);
				rs2.MoveNext();
			}
			rs2.Close();
			
			//把记录纸插入到联系人列表控件中
			ReadcontactInfo(id,name,email,TempGroup);
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


//初始化联系人信息列表控件的数据
void CEmailManagementDlg::InitContactListData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//添加联系人基本记录信息
		sql="select * from contact_info_tab where IS_BLACK=0 or IS_BLACK is null";
		//获取邮件联系人的记录集
		rs.Open(CRecordset::dynaset,sql);
		int id,groupID;
		CString name,email,TempGroup;
		while(!rs.IsEOF())
		{
			groupID=-1;
			TempGroup="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				id=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,name);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,email);
			//获取联系人所在组的id;
			rs.GetFieldValue((short)3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
			{
				groupID=var.m_iVal;
			}
			else
			{
				groupID=NULL;
			}
			var.Clear();
			
			CRecordset rs2(&m_db);
			CString sql2;
			sql2.Format("select * from contact_group where group_id=%d",groupID);
			rs2.Open(CRecordset::dynaset,sql2);
			while(!rs2.IsEOF())
			{
				rs2.GetFieldValue(1,TempGroup);
				rs2.MoveNext();
			}
			rs2.Close();
			
			//把记录纸插入到联系人列表控件中
			ReadcontactInfo(id,name,email,TempGroup);
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

//初始化联系人分组列表控件的数据(带参)
void CEmailManagementDlg::InitContactGroupData(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		
		rs.Open(CRecordset::dynaset,sql);
		int groupid;
		CString groupname,groupDesc;
		while(!rs.IsEOF())
		{
			groupid=-1;
			groupname="";	groupDesc="";
			CDBVariant var;
			//获取联系人组id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				groupid=var.m_iVal;
			var.Clear();
			//获取联系人组名字段值
			rs.GetFieldValue(1,groupname);
			//获取联系人组备注
			rs.GetFieldValue(2,groupDesc);
			ReadContactGroupInfo(groupid,groupname,groupDesc);
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


//初始化联系人分组列表控件的数据
void CEmailManagementDlg::InitContactGroupData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//向联系人分组列表控件中添加信息
		sql.Format("select * from contact_group");
		rs.Open(CRecordset::dynaset,sql);
		int groupid;
		CString groupname,groupDesc;
		while(!rs.IsEOF())
		{
			CDBVariant var;
			//获取联系人组id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				groupid=var.m_iVal;
			var.Clear();
			//获取联系人组名字段值
			rs.GetFieldValue(1,groupname);
			//获取联系人组备注
			rs.GetFieldValue(2,groupDesc);
			ReadContactGroupInfo(groupid,groupname,groupDesc);
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

//初始化回收站列表控件的数据(带参)
void CEmailManagementDlg::InitRecycleBinData(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		
		rs.Open(CRecordset::dynaset,sql);
		int tempRecordID,tempIsFujian;
		CString huishouName,huishouDate,huishouType,huishouInfo,huishouFujian;
		while(!rs.IsEOF())
		{
			tempRecordID=-1;tempIsFujian=-1;
			huishouName="";huishouDate="";huishouType="";huishouInfo="";huishouFujian="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				tempRecordID=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,huishouName);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,huishouDate);
			//获取联系人所在组的id;
			rs.GetFieldValue((short)3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
			{
				tempIsFujian=var.m_iVal;
			}
			var.Clear();
			rs.GetFieldValue(4,huishouType);
			rs.GetFieldValue(5,huishouInfo);
			rs.GetFieldValue(6,huishouFujian);
			
			//把记录插入到回收站列表控件中
			ReadRecycleBinInfo(tempRecordID,huishouName,huishouDate,tempIsFujian,huishouType,huishouInfo,huishouFujian);
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


//初始化回收站列表控件的数据
void CEmailManagementDlg::InitRecycleBinData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//初始化回收站列表控件
		sql="select * from view_record_recycle_bin";
		rs.Open(CRecordset::dynaset,sql);
		int tempRecordID,tempIsFujian;
		CString huishouName,huishouDate,huishouType,huishouInfo,huishouFujian;
		while(!rs.IsEOF())
		{
			tempRecordID=-1;tempIsFujian=-1;
			huishouName="";huishouDate="";huishouType="";huishouInfo="";huishouFujian="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				tempRecordID=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,huishouName);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,huishouDate);
			//获取联系人所在组的id;
			rs.GetFieldValue((short)3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
			{
				tempIsFujian=var.m_iVal;
			}
			var.Clear();
			rs.GetFieldValue(4,huishouType);
			rs.GetFieldValue(5,huishouInfo);
			rs.GetFieldValue(6,huishouFujian);
			
			//把记录插入到回收站列表控件中
			ReadRecycleBinInfo(tempRecordID,huishouName,huishouDate,tempIsFujian,huishouType,huishouInfo,huishouFujian);
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

//初始化邮件记录列表控件的数据(带参)
void CEmailManagementDlg::InitEmailRecordInfo(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		/*CString sql;
		
		  //向邮件记录列表控件中添加邮件类型信息
		sql="select * from email_record_tab where IS_RECYCLE_BIN=0 or IS_RECYCLE_BIN is null";*/
		//获取邮件类型的记录集
		rs.Open(CRecordset::dynaset,sql);
		
		int recordID,contactID,isFujian,typeID,fujianID;
		CString email,sendDate,emailTxt,strName,strType,fujianName;
		
		while(!rs.IsEOF())
		{
			recordID=-1;contactID=-1;isFujian=-1;typeID=-1;fujianID=-1;
			email="";	sendDate="";	emailTxt="";	strName="";		strType="";	fujianName="";
			
			CDBVariant var;
			//获取邮件ID字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				recordID=var.m_iVal;
			var.Clear();
			//获取收件人ID字段值
			rs.GetFieldValue(1,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				contactID=var.m_iVal;
			var.Clear();
			//获取邮件发送日期字段值
			rs.GetFieldValue(2,sendDate);
			//获取是否添加附件字段值
			rs.GetFieldValue(3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				isFujian=var.m_iVal;
			var.Clear();
			//获取邮件类型ID字段值
			rs.GetFieldValue(4,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				typeID=var.m_iVal;
			var.Clear();
			//获取邮件信息内容字段值
			rs.GetFieldValue(5,emailTxt);
			//获取附件ID字段值
			rs.GetFieldValue(6,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				fujianID=var.m_iVal;
			var.Clear();
			
			CRecordset rs2(&m_db);
			//通过联系人ID获得联系人姓名
			CString temp;
			temp.Format("select contact_name from contact_info_tab where ""contact_id=%d",contactID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strName);
			}
			rs2.Close();
			
			//通过邮件类型ID获取邮件类型名称
			temp.Format("select type_name from email_type_tab where ""type_id=%d",typeID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strType);
			}
			rs2.Close();
			
			//通过附件ID获得附件的名称的名称
			temp.Format("select fname from email_fujian where fid=%d",fujianID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,fujianName);
			}
			rs2.Close();
			
			//向邮件列表控件中加入一条新的记录信息
			ReadRecordInfo(recordID,strName,sendDate,isFujian,strType,emailTxt,fujianName);
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

//初始化邮件记录列表控件的数据
void CEmailManagementDlg::InitEmailRecordInfo()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//向邮件记录列表控件中添加邮件类型信息
		sql="select * from email_record_tab where IS_RECYCLE_BIN=0 or IS_RECYCLE_BIN is null";
		//获取邮件类型的记录集
		rs.Open(CRecordset::dynaset,sql);
		
		int recordID,contactID,isFujian,typeID,fujianID;
		CString email,sendDate,emailTxt,strName,strType,fujianName;
		
		while(!rs.IsEOF())
		{
			recordID=-1;contactID=-1;isFujian=-1;typeID=-1;fujianID=-1;
			email="";	sendDate="";	emailTxt="";	strName="";		strType="";	fujianName="";
			
			CDBVariant var;
			//获取邮件ID字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				recordID=var.m_iVal;
			var.Clear();
			//获取收件人ID字段值
			rs.GetFieldValue(1,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				contactID=var.m_iVal;
			var.Clear();
			//获取邮件发送日期字段值
			rs.GetFieldValue(2,sendDate);
			//获取是否添加附件字段值
			rs.GetFieldValue(3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				isFujian=var.m_iVal;
			var.Clear();
			//获取邮件类型ID字段值
			rs.GetFieldValue(4,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				typeID=var.m_iVal;
			var.Clear();
			//获取邮件信息内容字段值
			rs.GetFieldValue(5,emailTxt);
			//获取附件ID字段值
			rs.GetFieldValue(6,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				fujianID=var.m_iVal;
			var.Clear();
			
			CRecordset rs2(&m_db);
			//通过联系人ID获得联系人姓名
			CString temp;
			temp.Format("select contact_name from contact_info_tab where ""contact_id=%d",contactID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strName);
			}
			rs2.Close();
			
			//通过邮件类型ID获取邮件类型名称
			temp.Format("select type_name from email_type_tab where ""type_id=%d",typeID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strType);
			}
			rs2.Close();
			
			//通过附件ID获得附件的名称的名称
			temp.Format("select fname from email_fujian where fid=%d",fujianID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,fujianName);
			}
			rs2.Close();
			
			//向邮件列表控件中加入一条新的记录信息
			ReadRecordInfo(recordID,strName,sendDate,isFujian,strType,emailTxt,fujianName);
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

//初始化黑名单列表控件的数据(带参)
void CEmailManagementDlg::InitBlackListData(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		
		rs.Open(CRecordset::dynaset,sql);
		int blackID;
		CString blackName,blackEmail;
		
		while(!rs.IsEOF())
		{
			blackID=-1;
			blackName="";blackEmail="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				blackID=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,blackName);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,blackEmail);
			
			//把记录插入到回收站列表控件中
			ReadBlackListInfo(blackID,blackName,blackEmail);
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


//初始化黑名单列表控件的数据
void CEmailManagementDlg::InitBlackListData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//初始化回收站列表控件
		sql="select * from view_black_list";
		rs.Open(CRecordset::dynaset,sql);
		int blackID;
		CString blackName,blackEmail;
		
		while(!rs.IsEOF())
		{
			blackID=-1;
			blackName="";blackEmail="";
			
			CDBVariant var;
			//获取联系人id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				blackID=var.m_iVal;
			var.Clear();
			//获取联系人姓名字段值
			rs.GetFieldValue(1,blackName);
			//获取联系人邮箱字段值
			rs.GetFieldValue(2,blackEmail);
			
			//把记录插入到回收站列表控件中
			ReadBlackListInfo(blackID,blackName,blackEmail);
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

//初始化附件列表控件的数据(带参)
void CEmailManagementDlg::InitFujianListData(CString sql)
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		/*	CString sql;
		
		  //向附件管理列表中初始化值
		sql="select * from email_fujian where fid>0";*/
		rs.Open(CRecordset::dynaset,sql);
		int fujianID;
		CString fujianName,fujianDesc;
		while(!rs.IsEOF())
		{
			fujianID=-1;
			fujianName="";
			fujianDesc="";
			
			CDBVariant var;
			//获取附件id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				fujianID=var.m_iVal;
			var.Clear();
			if(-1==fujianID)
			{
				break;
			}
			//获取附件名字段值
			rs.GetFieldValue(1,fujianName);
			//获取附件备注
			rs.GetFieldValue(2,fujianDesc);
			ReadFujianInfo(fujianID,fujianName,fujianDesc);
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


//初始化附件列表控件的数据
void CEmailManagementDlg::InitFujianListData()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//向附件管理列表中初始化值
		sql="select * from email_fujian where fid>0";
		rs.Open(CRecordset::dynaset,sql);
		int fujianID;
		CString fujianName,fujianDesc;
		while(!rs.IsEOF())
		{
			fujianID=-1;
			fujianName="";
			fujianDesc="";
			
			CDBVariant var;
			//获取附件id字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				fujianID=var.m_iVal;
			var.Clear();
			//获取附件名字段值
			rs.GetFieldValue(1,fujianName);
			//获取附件备注
			rs.GetFieldValue(2,fujianDesc);
			ReadFujianInfo(fujianID,fujianName,fujianDesc);
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



//初始化所有列表控件的数据
void CEmailManagementDlg::InitListData()
{
	//初始化邮件类型列表控件
	InitEmailTypeData();
	
	//初始化联系人信息列表控件的数据
	InitContactListData();
	
	//初始化联系人分组列表控件的数据
	InitContactGroupData();
	
	//初始化回收站列表控件的数据
	InitRecycleBinData();
	
	//初始化邮件记录列表控件的数据
	InitEmailRecordInfo();
	
	//初始化黑名单列表控件的数据
    InitBlackListData();
	
	//初始化附件列表控件的数据
	InitFujianListData();
	
	//附件三个按钮的控制
	GetDlgItem(IDC_BTN_ADDTYPE)->EnableWindow(true);
	GetDlgItem(IDC_BTN_MODTYPE)->EnableWindow(true);
	GetDlgItem(IDC_BTN_DELTYPE)->EnableWindow(true);
}

//添加黑名单列表控件信息的函数实现
void CEmailManagementDlg::ReadBlackListInfo(int blackID, CString blackName, CString blackEmail)
{
	//获得当前的记录数
	int nIndex=m_listBlack.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",blackID);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_listBlack.InsertItem(&lvItem);
	m_listBlack.SetItemText(nIndex,1,blackName);
	m_listBlack.SetItemText(nIndex,2,blackEmail);
}


//添加联系人列表控件信息的函数实现
void CEmailManagementDlg::ReadcontactInfo(int id, CString name, CString email,CString group)
{
	//获得当前的记录数
	int nIndex=m_listContact.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",id);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_listContact.InsertItem(&lvItem);
	m_listContact.SetItemText(nIndex,1,name);
	m_listContact.SetItemText(nIndex,2,email);
	m_listContact.SetItemText(nIndex,3,group);
}

//添加邮件类型列表控件信息的函数实现
void CEmailManagementDlg::ReadTypeInfo(int id, CString typeName)
{
	//获得当前的记录数
	int nIndex=m_listType.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",id);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_listType.InsertItem(&lvItem);
	m_listType.SetItemText(nIndex,1,typeName);
}

//向附件管理列表控件添加信息的函数
void CEmailManagementDlg::ReadFujianInfo(int id, CString fujianName, CString fujianDesc)
{
	//获得当前的记录数
	int nIndex=m_listFujian.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",id);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_listFujian.InsertItem(&lvItem);
	m_listFujian.SetItemText(nIndex,1,fujianName);
	m_listFujian.SetItemText(nIndex,2,fujianDesc);
}

//添加联系人分组列表控件信息的函数实现
void CEmailManagementDlg::ReadContactGroupInfo(int id, CString groupName, CString groupDesc)
{
	//获得当前的记录数
	int nIndex=m_listGroup.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",id);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	
	//插入一行数据
	m_listGroup.InsertItem(&lvItem);
	m_listGroup.SetItemText(nIndex,1,groupName);
	m_listGroup.SetItemText(nIndex,2,groupDesc);
}

//向邮件记录列表中添加记录
void CEmailManagementDlg::ReadRecordInfo(int id, CString name, CString sendDate, int isFujian, CString type, CString emailTxt,CString fujianName)
{
	ReadRecordInfo(m_listRecord,id,name,sendDate,isFujian,type,emailTxt,fujianName);
}

void CEmailManagementDlg::ReadRecycleBinInfo(int id, CString name, CString sendDate, int isFujian, CString type, CString emailTxt, CString fujianName)
{
	ReadRecordInfo(m_listRecycleBin,id,name,sendDate,isFujian,type,emailTxt,fujianName);
}

//用于初始化邮件记录列表控件和回收站列表控件
void CEmailManagementDlg::ReadRecordInfo(CListCtrl &m_list, int id, CString name, CString sendDate, int isFujian, CString type, CString emailTxt, CString fujianName)
{
	//获得当前的记录数
	int nIndex=m_list.GetItemCount();
	LV_ITEM lvItem;
	lvItem.mask=LVIF_TEXT;
	lvItem.iItem=nIndex;
	lvItem.iSubItem=0;
	CString temp;
	temp.Format("%d",id);
	lvItem.pszText=(char *)(LPCTSTR)temp;
	//在nIndex一行插入联系人信息数据
	m_list.InsertItem(&lvItem);
	m_list.SetItemText(nIndex,1,name);
	m_list.SetItemText(nIndex,2,sendDate);
	m_list.SetItemText(nIndex,3,isFujian==0?"否":"是");
	m_list.SetItemText(nIndex,4,type);
	m_list.SetItemText(nIndex,5,emailTxt);
	m_list.SetItemText(nIndex,6,fujianName);
}

void CEmailManagementDlg::OnBtnSendred() 
{
	//初始化邮件记录信息对话框
	CEmailRecordDlg dlg;
	//获取所有联系人的姓名
	int n=m_listContact.GetItemCount();
	for(int i=0;i<n;i++)
	{
		CString mytempname=m_listContact.GetItemText(i,1);
		dlg.m_strContactArray.Add(mytempname);
	}
	//获取所有邮件类型信息
	for(i=0;i<m_listType.GetItemCount();i++)
	{
		dlg.m_strTypeArray.Add(m_listType.GetItemText(i,1));
	}
	//获取所有组的姓名
	for(i=0;i<m_listGroup.GetItemCount();i++)
	{
		dlg.m_strGroupArr.Add(m_listGroup.GetItemText(i,1));
	}
	//打开邮件记录对话框，添加新的记录
	if(IDOK==dlg.DoModal())
	{
		CString strName,strType,strSendDate,strEInfo,strFujianName,strFujianDesc;
		int isFujian,isDraft;
		
		if(dlg.m_isQunfa==false)
		{
			dlg.m_strReceiverArr.Add(dlg.m_strContact);
		}
		for(int i=0;i<dlg.m_strReceiverArr.GetSize();i++)
		{
			//从对话框中获取记录值
			strName=dlg.m_strReceiverArr.GetAt(i);
			strType=dlg.m_strEtype;
			strSendDate=COleDateTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S");
			isFujian=dlg.m_isFujian;
			strEInfo=dlg.m_strEmailInfo;
			strFujianName=dlg.m_strFileName;
			strFujianDesc=dlg.m_strFujianDesc;
			isDraft=dlg.m_isDraft;
			
			if(""==strEInfo)
			{
				MessageBox("邮件内容不能为空","提示");
				break;
			}
			if(1==isFujian && ""==strFujianName)
			{
				MessageBox("附件名称不能为空","提示");
				break;
			}
            if(""==strType)
			{
				MessageBox("邮件类型不能为空","提示");
				break;
			}
			if(""==strName)
			{
				MessageBox("联系人姓名不能为空","提示");
				break;
			}
			
			TRY
			{
				CRecordset rs(&m_db);
				CString sql;
				//根据联系人姓名获取联系人ID值
				sql.Format("select contact_id from contact_info_tab where contact_name='%s'",strName);
				rs.Open(CRecordset::dynaset,sql);
				int contactID=-1;
				if(!rs.IsEOF())
				{
					CDBVariant var;
					rs.GetFieldValue((short)0,var,SQL_C_SLONG);
					if(var.m_dwType!=DBVT_NULL)
					{
						contactID=var.m_iVal;
					}
				}
				rs.Close();
				
				//如果联系人不存在，则添加
				if(-1==contactID)
				{
					if(IDOK==MessageBox("此联系人不存在，请问您是否添加？","提示"))
					{
						OnBtnAddcon();
						
						sql.Format("select contact_id from contact_info_tab where contact_name='%s'",strName);
						rs.Open(CRecordset::dynaset,sql);
						if(!rs.IsEOF())
						{
							CDBVariant var;
							rs.GetFieldValue((short)0,var,SQL_C_SLONG);
							if(var.m_dwType!=DBVT_NULL)
							{
								contactID=var.m_iVal;
							}
						}
						rs.Close();
						
						if(-1==contactID)
						{
							MessageBox("您输入的联系人前后不一致!请检查之！联系人已经为您添加，邮件并未发送","警告");
							return ;
						}
					}
					else
					{
						return;
					}
				}
				
				//根据邮件类型获取邮件类型ID
				sql.Format("select type_id from email_type_tab where type_name='%s'",strType);
				rs.Open(CRecordset::dynaset,sql);
				int typeID=1;
				if(!rs.IsEOF())
				{
					CDBVariant var;
					rs.GetFieldValue((short)0,var,SQL_C_SLONG);
					if(var.m_dwType!=DBVT_NULL)
					{
						typeID=var.m_iVal;
					}
				}
				rs.Close();
				
				//向附件表中插入一个附件
				int tempFujianID;
				
				if(isFujian==1)
				{
					int sk=0;
					sql.Format("select * from email_fujian where fname='%s'",strFujianName);
					rs.Open(CRecordset::snapshot,sql);
					if(!rs.IsEOF())
					{
						CDBVariant var;
						rs.GetFieldValue((short)0,var,SQL_C_SLONG);
						if(var.m_dwType!=DBVT_NULL)
						{
							sk=var.m_iVal;
						}
					}
					rs.Close();
					
					if(0!=sk)
					{
						MessageBox("附件名出现了同名的现象，请改个名字再上传");
						return;
					}
					
					if(strFujianName!="")
					{
						sql.Format("call email_load_fujian('%s','%s')",strFujianName,strFujianDesc);
						TRACE(sql);
						m_db.ExecuteSQL(sql);
					}
					else
					{
						MessageBox("附件名不能为空","错误友情提示");
						return;
					}
					
					//获取附件的ID
					sql.Format("select fid from email_fujian where fname='%s'",strFujianName);
					rs.Open(CRecordset::snapshot,sql);
					if(!rs.IsEOF())
					{
						CDBVariant var;
						rs.GetFieldValue((short)0,var,SQL_C_SLONG);
						if(var.m_dwType!=DBVT_NULL)
						{
							tempFujianID=var.m_iVal;
						}
					}
					rs.Close();
					
					ReadFujianInfo(tempFujianID,strFujianName,strFujianDesc);
				}
				else
				{
					tempFujianID=0;
				}
				
				
				//从SEQ_RECORD_ID序列中获取下一个值
				rs.Open(CRecordset::snapshot,"select SEQUENCE_RECORD_ID.NEXTVAL from dual");
				int recordID=10000;
				if(!rs.IsEOF())
				{
					CDBVariant var;
					rs.GetFieldValue((short)0,var,SQL_C_SLONG);
					if(var.m_dwType!=DBVT_NULL)
					{
						recordID=var.m_iVal;
					}
				}
				
				//插入新纪录
				if(isFujian==1)
				{
					sql.Format("insert into email_record_tab(record_id,contact_id,send_date,is_fujian,\
																									type_id,email_info,fujian_id,isread,IS_RECYCLE_BIN,is_draft) values(%d,%d,to_date('%s','yyyy-mm-dd hh24:mi:ss'),\
																									%d,%d,'%s',%d,%d,%d,%d)",recordID,
																									contactID,strSendDate,isFujian,typeID,strEInfo,tempFujianID,0,0,isDraft);
					TRACE(sql);
					m_db.ExecuteSQL(sql);
					rs.Close();
					if(1!=isDraft)
					{
						//向主界面中插入新的记录
						ReadRecordInfo(recordID,strName,strSendDate,isFujian,strType,strEInfo,strFujianName);
					}
					else
					{
						MessageBox("您已经将此封邮件存为草稿");
					}
					if(m_strCurUser!="")
					{
						sql.Format("insert into user_own(USER_ID,CONTACT_ID,RECORD_ID,GROUP_ID,FUJIAN_ID) values(%d,%d,%d,%d,%d)",\
							GetCurUserID(),contactID,recordID,0,tempFujianID);
						TRACE(sql);
						m_db.ExecuteSQL(sql);
					}
				}
				else
				{
					sql.Format("insert into email_record_tab(record_id,contact_id,send_date,is_fujian,type_id,\
						email_info,isread,IS_RECYCLE_BIN,is_draft) values(%d,%d,to_date('%s','yyyy-mm-dd hh24:mi:ss'),%d,%d,\
						'%s',%d,%d,%d)",\
						recordID,
						contactID,strSendDate,isFujian,typeID,strEInfo,0,0,isDraft);
					TRACE(sql);
					m_db.ExecuteSQL(sql);
					rs.Close();
					if(1!=isDraft)
					{
						ReadRecordInfo(recordID,strName,strSendDate,isFujian,strType,strEInfo,"");
					}
					else
					{
						MessageBox("您已经将此封邮件存为草稿");
					}
					if(m_strCurUser!="")
					{
						sql.Format("insert into user_own(USER_ID,CONTACT_ID,RECORD_ID,GROUP_ID,FUJIAN_ID) values(%d,%d,%d,%d,%d)",\
							GetCurUserID(),contactID,recordID,0,0);
						TRACE(sql);
						m_db.ExecuteSQL(sql);
					}
				}
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
		if(""==strEInfo)
		{
				return;
		}
		if(1==isFujian && ""==strFujianName)
		{
				return;
		}
		if(""==strType)
		{
				return;
		}
		if(""==strName)
		{
				return;
		}
	}	
}

//将联系人拉黑
void CEmailManagementDlg::OnBtnMovetoBlackList() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listContact.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int contactID=atoi(m_listContact.GetItemText(rItem,0));
	
	TRY
	{
		
		CString sql;
		sql.Format("update contact_info_tab set IS_BLACK=1 where CONTACT_ID=%d",contactID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		m_listContact.DeleteItem(rItem);
		m_listBlack.DeleteAllItems();
		if(m_strCurUser=="")
		{
			InitBlackListData();
		}
		else
		{
			GetCurUserIdInfo();
			CurUserChangeInit();
		}
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

//从黑名单中还原
void CEmailManagementDlg::OnBtnReturntoContact() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listBlack.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int contactID=atoi(m_listBlack.GetItemText(rItem,0));
	
	TRY
	{
		CString sql;
		sql.Format("update contact_info_tab set IS_BLACK=0 where CONTACT_ID=%d",contactID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		m_listBlack.DeleteItem(rItem);
		m_listContact.DeleteAllItems();
		if(m_strCurUser=="")
		{
			//初始化邮件记录列表控件的数据
			InitContactListData();
		}
		else
		{
			CurUserChangeInit();
		}
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

//移动到回收站
void CEmailManagementDlg::OnBtnMovetoBin() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listRecord.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int recordID=atoi(m_listRecord.GetItemText(rItem,0));
	
	TRY
	{
		
		CString sql;
		sql.Format("update email_record_tab set ISREAD=1 where RECORD_ID=%d",recordID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		sql.Format("update email_record_tab set IS_RECYCLE_BIN=1 where RECORD_ID=%d",recordID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		m_listRecord.DeleteItem(rItem);
		m_listRecycleBin.DeleteAllItems();
		if(m_strCurUser=="")
		{
			InitRecycleBinData();
		}
		else if(m_strCurUser!="")
		{
			GetCurUserIdInfo();
			CurUserChangeInit();
		}
		else
		{
			MessageBox("出现了意外的输入");
		}
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

//从回收站中还原
void CEmailManagementDlg::OnBtnRestore() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listRecycleBin.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int recordID=atoi(m_listRecycleBin.GetItemText(rItem,0));
	
	TRY
	{
		CString sql;
		sql.Format("update email_record_tab set IS_RECYCLE_BIN=0 where RECORD_ID=%d",recordID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		m_listRecycleBin.DeleteItem(rItem);
		m_listRecord.DeleteAllItems();
		if(m_strCurUser=="")
		{
			//初始化邮件记录列表控件的数据
			InitEmailRecordInfo();
		}
		else if(m_strCurUser!="")
		{
			GetCurUserIdInfo();
			CurUserChangeInit();
		}
		else
		{
			MessageBox("出现了意外的输入");
		}
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

void CEmailManagementDlg::OnBtnQueryred() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listRecord.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int recordID=atoi(m_listRecord.GetItemText(rItem,0));
	
	//初始化邮件记录信息对话框
	CEmailRecordDlg* queryDlg=new CEmailRecordDlg();
	queryDlg->GetRecordID(recordID);
	
	//给对话框赋参数
	queryDlg->m_strContact=m_listRecord.GetItemText(rItem,1);
	queryDlg->m_strEtype=m_listRecord.GetItemText(rItem,4);
	queryDlg->m_sendDate.ParseDateTime(m_listRecord.GetItemText(rItem,2));
	if(m_listRecord.GetItemText(rItem,3).CompareNoCase("是")==0)
	{
		queryDlg->m_isFujian=1;
		
		//当存在附件的时候，就要给对话框的附件名和附件描述赋值
		queryDlg->m_strFileName=m_listRecord.GetItemText(rItem,6);
		
		//获取附件描述
		TRY
		{
			CString tempFujiandesc;
			
			CRecordset rs;
			rs.m_pDatabase=&m_db;
			
			CString sql;
			sql.Format("select * from email_fujian where fname='%s'",queryDlg->m_strFileName);
			rs.Open(CRecordset::dynaset,sql);
			while(!rs.IsEOF())
			{
				rs.GetFieldValue(2,tempFujiandesc);
				rs.MoveNext();
			}
			rs.Close();
			
			queryDlg->m_strFujianDesc=tempFujiandesc;
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
	else
	{
		queryDlg->m_isFujian=0;
	}
	queryDlg->m_strEmailInfo=m_listRecord.GetItemText(rItem,5);
	
	//获取邮件是否已读
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		//获取邮件是否已读
		sql.Format("select * from email_record_tab where RECORD_ID=%d",recordID);
		rs.Open(CRecordset::dynaset,sql);
		while(!rs.IsEOF())
		{
			CDBVariant var;
			rs.GetFieldValue((short)7,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				queryDlg->m_isRead=var.m_iVal;
			}
			rs.MoveNext();
		}
		rs.Close();
		
		//获取联系人所在的分组
		sql.Format("select * from contact_group,email_record_tab,\
																   contact_info_tab where contact_group.group_id=contact_info_tab.group_id\
																   and email_record_tab.contact_id=contact_info_tab.contact_id and record_id=%d",\
																   recordID);
		rs.Open(CRecordset::dynaset,sql);
		while(!rs.IsEOF())
		{
			CString tempGroup;
			rs.GetFieldValue(1,tempGroup);
			queryDlg->m_strGroup=tempGroup;
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
		
		//打开邮件记录的对话框
		queryDlg->Create(IDD_DIALOG_RECORD);
	BOOL isShow=queryDlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框
	
	queryDlg->GetDlgItem(IDC_CHECK_ISREAD)->ShowWindow(true);
	
	if(queryDlg->m_isFujian==1)
	{
		queryDlg->GetDlgItem(IDC_EDIT_FILE_NAME)->ShowWindow(true);
		queryDlg->GetDlgItem(IDC_EDIT_FILE_DESC)->ShowWindow(true);
	}
    if(queryDlg->m_isRead==1)
	{
		queryDlg->GetDlgItem(IDC_CHECK_ISREAD)->EnableWindow(false);
	}
	
	if(isShow)
	{
		//获取查看记录的值
		CString strName=queryDlg->m_strContact;
		CString strType=queryDlg->m_strEtype;
		CString strSendDate=m_listRecord.GetItemText(rItem,2);
		int isFujian=queryDlg->m_isFujian;
		CString strEmailInfo=queryDlg->m_strEmailInfo;
		CString fujianName=queryDlg->m_strFujianDesc;
		TRY
		{
			m_listRecord.DeleteItem(rItem);
			ReadRecordInfo(recordID,strName,strSendDate,isFujian,strType,strEmailInfo,"");
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
}

void CEmailManagementDlg::OnBtndelred() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listRecord.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要删除的记录");
		return;
	}
	//获取邮件记录ID
	int recordID=atoi(m_listRecord.GetItemText(rItem,0));
	
	TRY
	{
		CString sql;
		int fujianID;
		//删除的时候级联删除附件表中的附件
		
		//1. 获取元组记录的附件ID
		sql.Format("select fujian_id from email_record_tab where record_id=%d",recordID);
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		rs.Open(CRecordset::dynaset,sql);
		while(!rs.IsEOF())
		{
			CDBVariant var;
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				fujianID=var.m_iVal;
			}
			rs.MoveNext();
		}
		rs.Close();
		
		//从数据库中删除记录
		sql.Format("delete email_record_tab where record_id=%d",recordID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
		
		//2. 删除附件列表中的元组
		sql.Format("delete email_fujian where fid=%d",fujianID);
		TRACE(sql);
		m_db.ExecuteSQL(sql);
        if(m_strCurUser!="")
		{
			sql.Format("delete user_own where record_id=%d",recordID);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
			sql.Format("delete user_own where fujian_id=%d",fujianID);
			TRACE(sql);
			m_db.ExecuteSQL(sql);
		}
		//从列表控件中删除该记录
		m_listRecord.DeleteItem(rItem);
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

void CEmailManagementDlg::OnButtonTimequery() 
{
	TimeQueryDlg dlg;
	CString startTime,endTime;
	if(dlg.DoModal()==IDOK)
	{
		startTime=dlg.m_startDate.Format("%Y-%m-%d");
		endTime=dlg.m_endDate.Format("%Y-%m-%d");
		
		if(startTime>endTime)
		{
			MessageBox("您可能起始时间和终止时间填反了！","错误提示！！！");
			return;
		}

		CString sql;
		sql.Format("select RECORD_ID from email_record_tab where to_char(send_date,'yyyy-mm-dd') >= '%s' and to_char(send_date,'yyyy-mm-dd')<='%s'",startTime,endTime);
		int recordID;
		TRY
		{
			CRecordset rs(&m_db);
			rs.Open(CRecordset::dynaset,sql);
			while(!rs.IsEOF())
			{
				CDBVariant var;
				//获取id值
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					recordID=var.m_iVal;
				}
				var.Clear();
				
				//位选择出来的元组描成深色
				for(int nItem=0;nItem<m_listRecord.GetItemCount();nItem++)
				{
					CString strID,strListID;
					strID.Format("%d",recordID);
					strListID=m_listRecord.GetItemText(nItem,0);
					if(strID==strListID)
					{
						m_listRecord.SetFocus();
						m_listRecord.SetItemState(nItem,LVIS_SELECTED,LVIS_SELECTED);
					}
				}
				
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
}

//参看组的详细情况
void CEmailManagementDlg::OnBtnGroupQuery() 
{
	//获取要查看的记录信息所在的行数
	int rItem=m_listGroup.GetNextItem(-1,LVNI_SELECTED);
	if(-1==rItem)
	{
		AfxMessageBox("没有选择要查看的记录");
		return;
	}
	//获取邮件记录ID
	int groupID=atoi(m_listGroup.GetItemText(rItem,0));
	
    //实例化组管理对话框
	CEmailContactGroupDlg dlg;
	dlg.m_strGroupName=m_listGroup.GetItemText(rItem,1);
	dlg.m_strGroupDesc=m_listGroup.GetItemText(rItem,2);
	dlg.m_AddOrLook=LOOK;
	//从数据库获取组内成员
	CString strMem;
	
	CRecordset rs;
	rs.m_pDatabase=&m_db;
	CString sql;
	sql.Format("select * from contact_group,contact_info_tab where contact_group.group_id=contact_info_tab.group_id and contact_group.group_id=%d",groupID);	
	rs.Open(CRecordset::dynaset,sql);
	while(!rs.IsEOF())
	{
		rs.GetFieldValue(4,strMem);
		dlg.m_strGroupMemArr.Add(strMem);
		rs.MoveNext();
	}
	rs.Close();
	
	if(IDOK==dlg.DoModal())
	{
		if(MessageBox("按下ok按钮并不会彻底修改值，您确定吗？","提示",MB_OKCANCEL)!=IDOK)
		{
			return;
		}
		//获取查看记录的值
		CString strName=dlg.m_strGroupName;
		CString strDesc=dlg.m_strGroupDesc;
		
		TRY
		{
			m_listGroup.DeleteItem(rItem);
			ReadContactGroupInfo(groupID,strName,strDesc);
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
}

//获取数据库的指针
CDatabase* CEmailManagementDlg::GetDB()
{
	return &m_db;
}

//用于联系人列表控件的比较
static int m_nlistContactSortColum;
static bool m_bListContactCmp=true;

//列表控件用于比较
static int CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	
	CListCtrl* pListCtrl = (CListCtrl*) lParamSort;
    CString   strItem1 = pListCtrl->GetItemText(lParam1,m_nlistContactSortColum);
    CString   strItem2 = pListCtrl->GetItemText(lParam2,m_nlistContactSortColum);    
    if (m_bListContactCmp)
    {    
        return strcmp(strItem2, strItem1);    
    }
    else    
    {
        return strcmp(strItem1, strItem2);    
    }
}

//联系人列表头的排序
void CEmailManagementDlg::OnColumnclickListContact(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	m_nlistContactSortColum = pNMListView->iSubItem;//点击的列
	
	int count=m_listContact.GetItemCount();
	for (int i=0;i<count;i++)
	{
		// 每行的比较关键字，此处为列序号（点击的列号），可以设置为其他比较函数的第一二个参数
		m_listContact.SetItemData(i,i); 
	}
	m_listContact.SortItems((PFNLVCOMPARE)MyCompareProc,(LPARAM)&m_listContact);//排序第二个参数是比较函数的第三个参数
	m_bListContactCmp = !m_bListContactCmp;
	
	*pResult = 0;
}

//用于邮件类型列表控件的比较
static int m_nlistTypeSortColum;
static bool m_bListTypeCmp=true;
//列表控件用于比较
static int CALLBACK MyCompareProc1(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	
	CListCtrl* pListCtrl = (CListCtrl*) lParamSort;
    CString   strItem1 = pListCtrl->GetItemText(lParam1,m_nlistTypeSortColum);
    CString   strItem2 = pListCtrl->GetItemText(lParam2,m_nlistTypeSortColum);    
    if (m_bListTypeCmp)
    {    
        return strcmp(strItem2, strItem1);    
    }
    else    
    {
        return strcmp(strItem1, strItem2);    
    }
}
//邮件类型列表控件
void CEmailManagementDlg::OnColumnclickListEtype(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	int count=m_listType.GetItemCount();
	for (int i=0;i<count;i++)
	{
		// 每行的比较关键字，此处为列序号（点击的列号），可以设置为其他比较函数的第一二个参数
		m_listType.SetItemData(i,i); 
	}
	m_listType.SortItems((PFNLVCOMPARE)MyCompareProc1,(LPARAM)&m_listType);//排序第二个参数是比较函数的第三个参数
	m_bListTypeCmp = !m_bListTypeCmp;
	
	*pResult = 0;
}

//用于邮件记录列表控件的比较
static int m_nlistRecordSortColum;
static bool m_bListRecordCmp=true;
//列表控件用于比较
static int CALLBACK MyCompareProc2(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*) lParamSort;
    CString   strItem1 = pListCtrl->GetItemText(lParam1,m_nlistRecordSortColum);
    CString   strItem2 = pListCtrl->GetItemText(lParam2,m_nlistRecordSortColum);    
    if (m_bListRecordCmp)
    {    
        return strcmp(strItem2, strItem1);    
    }
    else    
    {
        return strcmp(strItem1, strItem2);    
    }
}
//邮件记录
void CEmailManagementDlg::OnColumnclickListRecord(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
    // TODO: Add your control notification handler code here
    m_nlistRecordSortColum = pNMListView->iSubItem; 
	
    m_bListRecordCmp=!m_bListRecordCmp;//升序还是降序  
    int count = m_listRecord.GetItemCount(); //行数    
    for(int i=0; i<count;  i++)      
    {  
        m_listRecord.SetItemData(i,i);      
    }
    m_listRecord.SortItems(MyCompareProc2, (LPARAM) &m_listRecord);
	
	*pResult = 0;
}

//用于回收站列表控件的比较
static int m_nlistBinSortColum;
static bool m_bListBinCmp=true;
//回收站列表控件用于比较
static int CALLBACK MyCompareProc3(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*) lParamSort;
    CString   strItem1 = pListCtrl->GetItemText(lParam1,m_nlistBinSortColum);
    CString   strItem2 = pListCtrl->GetItemText(lParam2,m_nlistBinSortColum);    
    if (m_bListBinCmp)
    {    
        return strcmp(strItem2, strItem1);    
    }
    else    
    {
        return strcmp(strItem1, strItem2);    
    }
}
//回收站
void CEmailManagementDlg::OnColumnclickListRecycleBin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	// TODO: Add your control notification handler code here
    m_nlistBinSortColum = pNMListView->iSubItem; 
	
    m_bListBinCmp=!m_bListBinCmp;//升序还是降序  
    int count = m_listRecycleBin.GetItemCount(); //行数    
    for(int i=0; i<count;  i++)      
    {  
        m_listRecycleBin.SetItemData(i,i);      
    }
    m_listRecycleBin.SortItems(MyCompareProc3, (LPARAM) &m_listRecycleBin);
	
	*pResult = 0;
}

//查看数据库信息的菜单响应
void CEmailManagementDlg::OnDb() 
{
	CDBConnDlg dlg;
	dlg.m_strDBSource=m_strDBSource;
	dlg.m_strUserName=m_strUserName;
	dlg.m_strPassword=m_strPassword;
	if(IDOK==dlg.DoModal())
	{
		m_strDBSource=dlg.m_strDBSource;
		m_strUserName=dlg.m_strUserName;
		m_strPassword=dlg.m_strPassword;
		ConnDB();
	}
}

BOOL CEmailManagementDlg::ParsePathPieces(LPCTSTR szFile, LPTSTR szPath, LPTSTR szSkin)
{
	// Slice up the path a bit so that we have it in the required root/skin separation
	
    // Find the last \ character
    TCHAR* lastslash = (TCHAR *) _tcsrchr(szFile, _T('\\'));
    if (lastslash) {
		
        // Null it out, then get the next \ so that we have the end of the path
        *lastslash = 0;
		
        TCHAR* pathend = (TCHAR *) _tcsrchr(szFile, _T('\\'));
        if (pathend) {
			
            // Copy path, length is pathend minus pathstart
            // (we leave off the trailing \, it works either way)
            _tcsncpy(szPath, szFile, pathend - szFile);
			
            // Copy the rest, not forgetting to put the \ back
            *lastslash = _T('\\');
            _tcscpy(szSkin, pathend + 1);
            return TRUE;
        }
    }
	
    return FALSE;
}

void CEmailManagementDlg::OnDestroy() 
{
	UnSubclassControls();
	
	CDialog::OnDestroy();
}

void CEmailManagementDlg::UnSubclassControls()
{
	SETNOSKINHWND(m_listBlack);
	SETNOSKINHWND(m_listContact);
	SETNOSKINHWND(m_listFujian);
	SETNOSKINHWND(m_listGroup);
	SETNOSKINHWND(m_listRecord);
	SETNOSKINHWND(m_listRecycleBin);
	SETNOSKINHWND(m_listType);
	/*SETNOSKINHWND(m_Slider1);
	SETNOSKINHWND(m_Slider2);
	SETNOSKINHWND(m_Slider3);
	SETNOSKINHWND(m_Slider4);
	SETNOSKINHWND(m_Slider5);
	SETNOSKINHWND(m_Slider6);*/
}

void CEmailManagementDlg::OnChangeMySkin() 
{
	TCHAR szFile[MAX_PATH] = {0};
	OPENFILENAME OpenFileName;
	
	OpenFileName.lStructSize       = sizeof(OPENFILENAME);
	OpenFileName.hwndOwner         = m_hWnd;
	OpenFileName.hInstance         = AfxGetInstanceHandle();
	OpenFileName.lpstrFilter       = _T("Skin++ skinfiles (*.ssk)\0*.ssk\0\0");
	OpenFileName.lpstrCustomFilter = NULL;
	OpenFileName.nMaxCustFilter    = 0;
	OpenFileName.nFilterIndex      = 0;
	OpenFileName.lpstrFile         = szFile;
	OpenFileName.nMaxFile          = sizeof(szFile);
	OpenFileName.lpstrFileTitle    = NULL;
	OpenFileName.nMaxFileTitle     = 0;
	OpenFileName.lpstrInitialDir   = _T("..\\skins");
	OpenFileName.lpstrTitle        = _T("Select a ssk File");
	OpenFileName.nFileOffset       = 0;
	OpenFileName.nFileExtension    = 0;
	OpenFileName.lpstrDefExt       = NULL;
	OpenFileName.Flags             = OFN_SHOWHELP | OFN_EXPLORER;
	
	if(GetOpenFileName(&OpenFileName))
	{
		TCHAR szPathA[MAX_PATH] = {0};
		TCHAR szPathB[MAX_PATH] = {0};
		
		// We need a root path and a skin directory/name combination
		ParsePathPieces(szFile, szPathA, szPathB);
		
		skinppLoadSkin(szFile);
		Invalidate();
	}	
}

void CEmailManagementDlg::OnRemoveSkin() 
{
	skinppRemoveSkin();	
}

//当用户进行切换的时候初始化
void CEmailManagementDlg::CurUserChangeInit()
{
	if(m_strCurUser!="")
	{
		GetDlgItem(IDC_BTN_ADDTYPE)->EnableWindow(false);
		GetDlgItem(IDC_BTN_MODTYPE)->EnableWindow(false);
		GetDlgItem(IDC_BTN_DELTYPE)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_BTN_ADDTYPE)->EnableWindow(true);
		GetDlgItem(IDC_BTN_MODTYPE)->EnableWindow(true);
		GetDlgItem(IDC_BTN_DELTYPE)->EnableWindow(true);
	}
	
	m_listContact.DeleteAllItems();
	m_listRecord.DeleteAllItems();
	m_listFujian.DeleteAllItems();
	m_listRecycleBin.DeleteAllItems();
	m_listBlack.DeleteAllItems();
	m_listGroup.DeleteAllItems();
	
	TRY
	{
		CString sql;
		for(int i=0;i<m_CurContactIdArr.GetSize();i++)
		{
			sql.Format("select * from contact_info_tab where contact_id=%d and is_black=0",m_CurContactIdArr.GetAt(i));
			InitContactListData(sql);
			//初始化黑名单
			sql.Format("select * from view_black_list where contact_id=%d",m_CurContactIdArr.GetAt(i));
			InitBlackListData(sql);
		}
		for(i=0;i<m_CurRecordIdArr.GetSize();i++)
		{
			sql.Format("select * from email_record_tab where record_id=%d and IS_RECYCLE_BIN=0",m_CurRecordIdArr.GetAt(i));
			InitEmailRecordInfo(sql);
		}
		for(i=0;i<m_CurRecordIdArr.GetSize();i++)
		{
			sql.Format("select * from email_record_tab where record_id=%d and IS_RECYCLE_BIN=1",m_CurRecordIdArr.GetAt(i));
			InitRecycleBinData(sql);
		}
		for(i=0;i<m_CurFujianIdArr.GetSize();i++)
		{
			sql.Format("select * from email_fujian where fid=%d",m_CurFujianIdArr.GetAt(i));
			InitFujianListData(sql);
		}
		for(i=0;i<m_CurGroupIdArr.GetSize();i++)
		{
			sql.Format("select * from contact_group where group_id=%d",m_CurGroupIdArr.GetAt(i));
			InitContactGroupData(sql);
		}
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

//设置用户等级提示
void CEmailManagementDlg::SetUserTishi(CString name, CString rank)
{
	m_strUserTishi="当前用户："+name+" ";
	m_strUserTishi=m_strUserTishi+"用户等级："+rank;
}

void CEmailManagementDlg::OnLogOn() 
{
	CUserLogon dlg;
	int n=m_strCurUser.Find("@");
	CString temp=m_strCurUser.Left(n);
	dlg.m_strUserName=temp;
	if(IDOK==dlg.DoModal())
	{
		if(""==dlg.m_strPasswd)
		{
			MessageBox("用户的密码不可能为空！","提醒");
			return;
		}
		if(""==dlg.m_strUserName && "955219"==dlg.m_strPasswd)
		{
			UpdateData(true);
			MessageBox("您已经切换到了最大权限用户，请慎重操作！");
			SetUserTishi("万能的管理员","super vip");
			m_strCurUser="";
			ClearAllLists();
			InitListData();
			UpdateData(false);
		}
		else
		{
			TRY
			{
				CRecordset rs;
				rs.m_pDatabase=&m_db;
				CString sql;
				
				sql.Format("select * from email_user where user_name='%s'",dlg.m_strUserName+userNameTear);
				rs.Open(CRecordset::dynaset,sql);
				CString userPassWd,userName;
				
				while(!rs.IsEOF())
				{
					userPassWd="";userName="";
					
					rs.GetFieldValue(1,userName);
					rs.GetFieldValue(2,userPassWd);
					
					//把记录插入到回收站列表控件中
					//ReadBlackListInfo(blackID,blackName,blackEmail);
					rs.MoveNext();
				}
				rs.Close();
				
				if(userPassWd==dlg.m_strPasswd && dlg.m_strPasswd!="")
				{
					UpdateData(true);
					m_strCurUser=dlg.m_strUserName+userNameTear;
					MessageBox("用户"+dlg.m_strUserName+userNameTear+"您好！"+"您已经成功个登陆！");
					m_strUserTishi="当前用户："+m_strCurUser+" ";
					m_strUserTishi=m_strUserTishi+"用户等级："+GetCurUserRank();
					GetCurUserIdInfo();
					CurUserChangeInit();
					UpdateData(false);
				}
				if(userName=="")
				{
					MessageBox("用户登录不成功!");
				}
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
	}
}


void CEmailManagementDlg::GetCurUserIdInfo()
{
	m_CurContactIdArr.RemoveAll();
	m_CurFujianIdArr.RemoveAll();
	m_CurRecordIdArr.RemoveAll();
	m_CurGroupIdArr.RemoveAll();
	
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		sql.Format("select * from user_own where user_id=%d",GetCurUserID());
		rs.Open(CRecordset::dynaset,sql);
		
		int contactID,recordID,fujianID,groupID;
		
		while(!rs.IsEOF())
		{
			contactID=-1;	recordID=-1;	fujianID=-1;	groupID=-1;
			
			CDBVariant var;
			rs.GetFieldValue((short)1,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				contactID=var.m_iVal;
			}
			var.Clear();
			rs.GetFieldValue(2,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				recordID=var.m_iVal;
			}
			var.Clear();
			rs.GetFieldValue(4,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				fujianID=var.m_iVal;
			}
			var.Clear();
			rs.GetFieldValue(3,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				groupID=var.m_iVal;
			}
			var.Clear();
			if(contactID>0 && !isInArr(contactID,&m_CurContactIdArr))
			{
				m_CurContactIdArr.Add(contactID);
			}
			if(fujianID>0 && !isInArr(fujianID,&m_CurFujianIdArr))
			{
				m_CurFujianIdArr.Add(fujianID);
			}
			if(recordID>0 && !isInArr(recordID,&m_CurRecordIdArr))
			{
				m_CurRecordIdArr.Add(recordID);
			}
			if(groupID>0 && !isInArr(groupID,&m_CurGroupIdArr))
			{
				m_CurGroupIdArr.Add(groupID);
			}
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

//获得当前用户的等级
CString CEmailManagementDlg::GetCurUserRank()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		sql.Format("select count(record_id) from user_own where user_id=%d and record_id>0",GetCurUserID());
		rs.Open(CRecordset::dynaset,sql);
		
		int count;
		
		while(!rs.IsEOF())
		{
			count=-1;
			CDBVariant var;
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				count=var.m_iVal;
			}
			var.Clear();
			rs.MoveNext();
		}
		rs.Close();
		
		CString strCount;
		strCount.Format("%d",count);
		return strCount;
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
		return "0";
}

//获取当前用户的id
int CEmailManagementDlg::GetCurUserID()
{
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		sql.Format("select * from Email_user where user_name='%s'",m_strCurUser);
		rs.Open(CRecordset::dynaset,sql);
		
		int userID;
		
		while(!rs.IsEOF())
		{
			userID=-1;
			CDBVariant var;
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType!=DBVT_NULL)
			{
				userID=var.m_iVal;
			}
			var.Clear();
			rs.MoveNext();
		}
		rs.Close();
		return userID;
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
		return -1;
}

BOOL CEmailManagementDlg::isInArr(int a, CArray<int,int> *arr)
{
	for(int i=0;i<arr->GetSize();i++)
	{
		if(a==arr->GetAt(i))
		{
			return TRUE;
		}
	}
	if(i==arr->GetSize())
	{
		return FALSE;
	}
	return FALSE;
}

void CEmailManagementDlg::OnUserRegist() 
{
	CUserRegistDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_strPassword == dlg.m_strOKPassword && dlg.m_strUserName!="" && dlg.m_strPassword!="" && dlg.m_strOKPassword!="")
		{
			TRY
			{
				//打开记录集
				CRecordset rs(&m_db);
				rs.Open(CRecordset::dynaset,"select max(user_id) from email_user");
				
				//设置新添加记录的用户的ID值
				int newUserID=1;
				//如果数据库里面有记录了，则新的用户ID=用户的ID最大值加1
				if(!rs.IsEOF())
				{
					CDBVariant var;
					rs.GetFieldValue((short)0,var,SQL_C_SLONG);
					if(var.m_dwType!=DBVT_NULL)
					{
						newUserID=var.m_iVal+1;
					}
				}
				rs.Close();
				
				//创建插入新用户记录的字符串
				CString sql;
				sql.Format("insert into email_user values(%d,'%s','%s')",\
					newUserID,dlg.m_strUserName+userNameTear,dlg.m_strOKPassword);
				TRACE(sql);
				//新的用户记录插入到数据库中
				m_db.ExecuteSQL(sql);
				ClearAllListsUnless();
				UpdateData(true);
				m_strCurUser=dlg.m_strUserName+userNameTear;
				SetUserTishi(m_strCurUser,"0");
				UpdateData(false);
			}
			CATCH(CDBException,ex)
			{
				AfxMessageBox(ex->m_strError);
				AfxMessageBox(ex->m_strStateNativeOrigin);
			}
			AND_CATCH(CException,e)
			{
				TCHAR szError[100];
				e->GetErrorMessage(szError,100);
				AfxMessageBox(szError);
			}
			END_CATCH;
		}
	}
	else
	{
		MessageBox("用户名密码不能为空，且密码和确认密码要一致！","提醒");
	}
}

//查看所有的用户
void CEmailManagementDlg::OnAllUsers() 
{
	if(m_strCurUser!="")
	{
		MessageBox("普通用户没有此项权限");
		return;
	}
	else
	{
		CAllUsersDlg dlg;
		dlg.DoModal();
	}
}

//点击一行，调用系统的默认程序打开附件
void CEmailManagementDlg::OnClickListFujian(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	POSITION Pos = m_listFujian.GetFirstSelectedItemPosition();
    int nSelect = -1;
    while ( Pos )
    {
        nSelect = m_listFujian.GetNextSelectedItem(Pos);    //nSelect能获得第几行
    }
	char szFirstTrunk[60] = { 0 };
    m_listFujian.GetItemText(nSelect,1, szFirstTrunk, 60);  //获得想要的列值给szFirstTrunk*/
	CString cmd;
	if("txt"==GetSuffix(szFirstTrunk))
	{
		cmd="notepad.exe  ";
	}
    else if("bmp"==GetSuffix(szFirstTrunk) || "png"==GetSuffix(szFirstTrunk) ||"jpg"==GetSuffix(szFirstTrunk)
		|| "jpeg"==GetSuffix(szFirstTrunk))
	{
		cmd="mspaint.exe  ";
	}
	else if("doc"==GetSuffix(szFirstTrunk))
	{
		cmd="E:\\Users\\dell\\AppData\\Local\\Kingsoft\\WPS Office\\ksolaunch.exe ";
	}
	else if("avi"==GetSuffix(szFirstTrunk) || "mp4"==GetSuffix(szFirstTrunk) )
	{
		cmd="wmplayer.exe ";
	}
	cmd+=dir;
	cmd+=szFirstTrunk;
	WinExec(cmd, SW_SHOW);
	
	*pResult = 0;
}

//查看收件箱
void CEmailManagementDlg::OnBtnReceiveBin() 
{
	m_listRecord.DeleteAllItems();
	TRY
	{
		CRecordset rs;
		rs.m_pDatabase=&m_db;
		CString sql;
		
		//向邮件记录列表控件中添加邮件类型信息
		sql.Format("select * from email_record_tab where (IS_RECYCLE_BIN=0 or IS_RECYCLE_BIN is null)\
			and contact_id in(select contact_id from contact_info_tab where contact_name='%s')",m_strCurUser);
		//获取邮件类型的记录集
		rs.Open(CRecordset::dynaset,sql);
		
		int recordID,contactID,isFujian,typeID,fujianID;
		CString email,sendDate,emailTxt,strName,strType,fujianName;
		
		while(!rs.IsEOF())
		{
			recordID=-1;contactID=-1;isFujian=-1;typeID=-1;fujianID=-1;
			email="";	sendDate="";	emailTxt="";	strName="";		strType="";	fujianName="";
			
			CDBVariant var;
			//获取邮件ID字段值
			rs.GetFieldValue((short)0,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				recordID=var.m_iVal;
			var.Clear();
			//获取收件人ID字段值
			rs.GetFieldValue(1,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				contactID=var.m_iVal;
			var.Clear();
			//获取邮件发送日期字段值
			rs.GetFieldValue(2,sendDate);
			//获取是否添加附件字段值
			rs.GetFieldValue(3,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				isFujian=var.m_iVal;
			var.Clear();
			//获取邮件类型ID字段值
			rs.GetFieldValue(4,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				typeID=var.m_iVal;
			var.Clear();
			//获取邮件信息内容字段值
			rs.GetFieldValue(5,emailTxt);
			//获取附件ID字段值
			rs.GetFieldValue(6,var,SQL_C_SLONG);
			if(var.m_dwType != DBVT_NULL)
				fujianID=var.m_iVal;
			var.Clear();
			
			CRecordset rs2(&m_db);
			//通过联系人ID获得联系人姓名
			CString temp;
			temp.Format("select contact_name from contact_info_tab where ""contact_id=%d",contactID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strName);
			}
			rs2.Close();
			
			//通过邮件类型ID获取邮件类型名称
			temp.Format("select type_name from email_type_tab where ""type_id=%d",typeID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,strType);
			}
			rs2.Close();
			
			//通过附件ID获得附件的名称的名称
			temp.Format("select fname from email_fujian where fid=%d",fujianID);
			rs2.Open(CRecordset::dynaset,temp);
			if(!rs2.IsEOF())
			{
				rs2.GetFieldValue((short)0,fujianName);
			}
			rs2.Close();
			
			//向邮件列表控件中加入一条新的记录信息
			ReadRecordInfo(recordID,strName,sendDate,isFujian,strType,emailTxt,fujianName);
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

//查看发件箱
void CEmailManagementDlg::OnBtnSendBin() 
{
	GetCurUserIdInfo();
	CurUserChangeInit();
}


//获得文件的拓展名
CString CEmailManagementDlg::GetSuffix(CString strFileName)
{
	return strFileName.Right(strFileName.GetLength()-strFileName.ReverseFind('.')-1);
}

//给指定的列表控件取消高亮
void CEmailManagementDlg::CancelListHigh(CListCtrl m_list)
{
	for(int i=0;i<m_listRecord.GetItemCount();i++)
	{
		m_list.SetItemState(i, 0,-1);
	}
}

//邮件记录的模糊查询
void CEmailManagementDlg::OnBtnBlurFind() 
{
	CBlurFindDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		int option;
		option=dlg.m_nRecordBlurFindOption;
		CString sql;
		CString sk1,sk2,sk3;
		
		if(0==option)
		{
			sk1="%"+dlg.m_strKeyName+"%";
			sk2="%"+dlg.m_strKeyName;
			sk3=dlg.m_strKeyName+"%";
			
			sql.Format("select record_id from email_record_tab where contact_id in (select \
																							 contact_id from contact_info_tab where contact_name like '%s' or\
																							 contact_name like '%s'or \
																							 contact_name like '%s')",sk1,sk2,sk3);
		}
		else if(1==option)
		{
			sk1="%"+dlg.m_strKeyEmail+"%";
			sk2="%"+dlg.m_strKeyEmail;
			sk3=dlg.m_strKeyEmail+"%";
			
			sql.Format("select record_id from email_record_tab where contact_id in (select \
																							 contact_id from contact_info_tab where e_mail like '%s' or\
																							 contact_name like '%s'or \
																							 contact_name like '%s')",sk1,sk2,sk3);
		}
		else
		{
			MessageBox("有意外输入，请重试","提示");
		}
		TRY
		{
			CRecordset rs(&m_db);
			rs.Open(CRecordset::dynaset,sql);
			
			int recordID=-1;
			
			for(int i=0;i<m_listRecord.GetItemCount();i++)
			{
				this->m_listRecord.SetItemState(i, 0,-1);
			}
			
			while(!rs.IsEOF())
			{
				CDBVariant var;
				//获取id值
				rs.GetFieldValue((short)0,var,SQL_C_SLONG);
				if(var.m_dwType!=DBVT_NULL)
				{
					recordID=var.m_iVal;
				}
				var.Clear();
				
				//位选择出来的元组描成深色
				for(int nItem=0;nItem<m_listRecord.GetItemCount();nItem++)
				{
					CString strID,strListID;
					strID.Format("%d",recordID);
					strListID=m_listRecord.GetItemText(nItem,0);
					if(strID==strListID)
					{
						m_listRecord.SetFocus();
						m_listRecord.SetItemState(nItem,LVIS_SELECTED,LVIS_SELECTED);
					}
				}
				
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
}

//通过网络发送邮件
void CEmailManagementDlg::OnNetSendMail() 
{
	CMyEmailSendDlg dlg;
	CString strEmailTo="18186482897@163.com";
	CString strMyContents="Hello World, Hello Email! hello DB";
	CString strEmailContents="From: \"lucy\"<wxbliaotian@163.com>\r\n"
			"To: \"dasiy\"<"+strEmailTo+">\r\n"
			"Subject: Hello\r\n\r\n"
			+strMyContents;
    dlg.m_strReceiveAddress=strEmailTo;
	dlg.m_strMyInfo=strMyContents;
	if(IDOK==dlg.DoModal())
	{
		strEmailTo=dlg.m_strReceiveAddress;
		strMyContents=dlg.m_strMyInfo;
		strEmailContents="From: \"lucy\"<wxbliaotian@163.com>\r\n"
			"To: \"dasiy\"<"+strEmailTo+">\r\n"
			"Subject: Hello\r\n\r\n"
			+strMyContents;
		char* EmailTo=(LPSTR)(LPCTSTR)strEmailTo;
		char* EmailContents=(LPSTR)(LPCTSTR)strEmailContents;
		SendMail(EmailTo,EmailContents);
	}	
}

void CEmailManagementDlg::OnBtnDraft() 
{
	CEmailDraftDlg dlg;
	if(dlg.DoModal())
	{

	}
}

//注销当前用户
void CEmailManagementDlg::OnUserCancellation() 
{
	if(m_strCurUser!="")
	{
		CString sql;
		sql.Format("call user_delete(%d)",GetCurUserID());
		MyExecuteSQL(sql);
		InitListData();
		MessageBox("当前用户已经注销，谢谢使用！");
	}
	else
	{
		MessageBox("当前是超级用户，不能删除！");
	}
}
