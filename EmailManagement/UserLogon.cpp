// UserLogon.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "UserLogon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserLogon dialog


CUserLogon::CUserLogon(CWnd* pParent /*=NULL*/)
	: CDialog(CUserLogon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserLogon)
	m_strUserName = _T("");
	m_strPasswd = _T("");
	//}}AFX_DATA_INIT
}


void CUserLogon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserLogon)
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_USER_PASSWD, m_strPasswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserLogon, CDialog)
	//{{AFX_MSG_MAP(CUserLogon)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserLogon message handlers
