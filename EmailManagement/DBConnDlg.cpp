// DBConnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "DBConnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBConnDlg dialog


CDBConnDlg::CDBConnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDBConnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDBConnDlg)
	m_strDBSource = _T("");
	m_strPassword = _T("");
	m_strUserName = _T("");
	//}}AFX_DATA_INIT
}


void CDBConnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDBConnDlg)
	DDX_Text(pDX, IDC_EDIT_DB_SRC, m_strDBSource);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_USER, m_strUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDBConnDlg, CDialog)
	//{{AFX_MSG_MAP(CDBConnDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBConnDlg message handlers
