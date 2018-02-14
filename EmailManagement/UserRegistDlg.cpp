// UserRegistDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "UserRegistDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserRegistDlg dialog


CUserRegistDlg::CUserRegistDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserRegistDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserRegistDlg)
	m_strOKPassword = _T("");
	m_strPassword = _T("");
	m_strUserName = _T("");
	//}}AFX_DATA_INIT
}


void CUserRegistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserRegistDlg)
	DDX_Text(pDX, IDC_EDIT_OK_PASSWORD, m_strOKPassword);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_strUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserRegistDlg, CDialog)
	//{{AFX_MSG_MAP(CUserRegistDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserRegistDlg message handlers
