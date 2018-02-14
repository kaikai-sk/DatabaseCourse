// MyEmailSendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "MyEmailSendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEmailSendDlg dialog


CMyEmailSendDlg::CMyEmailSendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyEmailSendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyEmailSendDlg)
	m_strReceiveAddress = _T("");
	m_strMyInfo = _T("");
	//}}AFX_DATA_INIT
}


void CMyEmailSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyEmailSendDlg)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strReceiveAddress);
	DDX_Text(pDX, IDC_EDIT_MYEMAIL_INFO, m_strMyInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyEmailSendDlg, CDialog)
	//{{AFX_MSG_MAP(CMyEmailSendDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEmailSendDlg message handlers
