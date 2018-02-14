// BlurFindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "BlurFindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlurFindDlg dialog


CBlurFindDlg::CBlurFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBlurFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBlurFindDlg)
	m_nRecordBlurFindOption = -1;
	m_strKeyEmail = _T("");
	m_strKeyName = _T("");
	//}}AFX_DATA_INIT
}


void CBlurFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlurFindDlg)
	DDX_Radio(pDX, IDC_RADIO_BLUR_NAME, m_nRecordBlurFindOption);
	DDX_Text(pDX, IDC_EDIT_KEY_EMAIL, m_strKeyEmail);
	DDX_Text(pDX, IDC_EDIT_KEY_NAME, m_strKeyName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBlurFindDlg, CDialog)
	//{{AFX_MSG_MAP(CBlurFindDlg)
	ON_BN_CLICKED(IDC_RADIO_BLUR_NAME, OnRadioBlurName)
	ON_BN_CLICKED(IDC_RADIO_BLUR_EMAIL, OnRadioBlurEmail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlurFindDlg message handlers

void CBlurFindDlg::OnRadioBlurName() 
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_KEY_NAME)->ShowWindow(true);

	GetDlgItem(IDC_STATIC2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_KEY_EMAIL)->ShowWindow(false);
}

void CBlurFindDlg::OnRadioBlurEmail() 
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_KEY_NAME)->ShowWindow(false);

	GetDlgItem(IDC_STATIC2)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_KEY_EMAIL)->ShowWindow(true);
}

BOOL CBlurFindDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem(IDC_STATIC1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_KEY_NAME)->ShowWindow(false);
	GetDlgItem(IDC_STATIC2)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_KEY_EMAIL)->ShowWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
