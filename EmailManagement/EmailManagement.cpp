// EmailManagement.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "EmailManagement.h"
#include "EmailManagementDlg.h"

#include "UserLogon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementApp

BEGIN_MESSAGE_MAP(CEmailManagementApp, CWinApp)
	//{{AFX_MSG_MAP(CEmailManagementApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementApp construction
const CString strSkinDir="skin\\";


CEmailManagementApp::CEmailManagementApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_strCurSkin=strSkinDir+"XP-Luna.ssk";
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CEmailManagementApp object

CEmailManagementApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementApp initialization

BOOL CEmailManagementApp::InitInstance()
{
	skinppLoadSkin((LPSTR)(LPCTSTR)m_strCurSkin);//blue.ssk为项目下的皮肤文件

	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CEmailManagementDlg dlg;
	/*CUserLogon dlg;*/
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CEmailManagementApp::ExitInstance() 
{
	skinppExitSkin();
	
	return CWinApp::ExitInstance();
}
