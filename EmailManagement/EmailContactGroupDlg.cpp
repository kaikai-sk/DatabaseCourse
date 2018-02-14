// EmailContactGroupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "EmailContactGroupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmailContactGroupDlg dialog


CEmailContactGroupDlg::CEmailContactGroupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmailContactGroupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmailContactGroupDlg)
	m_strGroupName = _T("");
	m_strGroupDesc = _T("");
	m_strGroupMember = _T("");
	//}}AFX_DATA_INIT
}


void CEmailContactGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmailContactGroupDlg)
	DDX_Control(pDX, IDC_COMBO_GROUP_MEMBER, m_cbGroupMember);
	DDX_Text(pDX, IDC_EDIT_GROUUP_NAME, m_strGroupName);
	DDX_Text(pDX, IDC_EDIT_GROUP_DESC, m_strGroupDesc);
	DDX_CBString(pDX, IDC_COMBO_GROUP_MEMBER, m_strGroupMember);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmailContactGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CEmailContactGroupDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailContactGroupDlg message handlers

BOOL CEmailContactGroupDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	for(int i=0;i<m_strGroupMemArr.GetSize();i++)
	{
		m_cbGroupMember.AddString(m_strGroupMemArr.GetAt(i));
	}
	//如果是查看记录，这里表框的文本值为要差看的组的所有联系人
	if(!m_strGroupMember.IsEmpty())
	{
		m_cbGroupMember.SetWindowText(m_strGroupMember);
	}
	else
	{
		m_cbGroupMember.SetCurSel(0);
	}
	if(m_AddOrLook==ADD)
	{
		GetDlgItem(IDC_COMBO_GROUP_MEMBER)->ShowWindow(false);
		GetDlgItem(IDC_STATIC_MEM)->ShowWindow(false);
	}
	else if(m_AddOrLook==LOOK)
	{
		if(m_strGroupMemArr.GetSize()==0)
		{
			m_strGroupMember="该组内没有成员";
			GetDlgItem(IDC_COMBO_GROUP_MEMBER)->EnableWindow(false);
			UpdateData(false);
		}
		GetDlgItem(IDC_EDIT_GROUUP_NAME)->EnableWindow(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
