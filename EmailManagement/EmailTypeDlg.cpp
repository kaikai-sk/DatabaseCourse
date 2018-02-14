// EmailTypeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "EmailTypeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmailTypeDlg dialog


CEmailTypeDlg::CEmailTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmailTypeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmailTypeDlg)
	m_strEmailType = _T("");
	//}}AFX_DATA_INIT
}


void CEmailTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmailTypeDlg)
	DDX_Text(pDX, IDC_EDIT_ETYPE, m_strEmailType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmailTypeDlg, CDialog)
	//{{AFX_MSG_MAP(CEmailTypeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailTypeDlg message handlers
