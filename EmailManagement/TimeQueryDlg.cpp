// TimeQueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "TimeQueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TimeQueryDlg dialog


TimeQueryDlg::TimeQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TimeQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TimeQueryDlg)
	m_startDate = COleDateTime::GetCurrentTime();
	m_endDate = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void TimeQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TimeQueryDlg)
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START, m_startDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END, m_endDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TimeQueryDlg, CDialog)
	//{{AFX_MSG_MAP(TimeQueryDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TimeQueryDlg message handlers
