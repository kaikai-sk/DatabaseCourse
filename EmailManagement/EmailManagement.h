// EmailManagement.h : main header file for the EMAILMANAGEMENT application
//

#if !defined(AFX_EMAILMANAGEMENT_H__177EEC3D_3805_4349_89C4_A70FAE1D01EF__INCLUDED_)
#define AFX_EMAILMANAGEMENT_H__177EEC3D_3805_4349_89C4_A70FAE1D01EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

 #define SKINSPACE _T("/SPATH:")

/////////////////////////////////////////////////////////////////////////////
// CEmailManagementApp:
// See EmailManagement.cpp for the implementation of this class
//

class CEmailManagementApp : public CWinApp
{
public:
	CEmailManagementApp();
	CString m_strCurSkin;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailManagementApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEmailManagementApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILMANAGEMENT_H__177EEC3D_3805_4349_89C4_A70FAE1D01EF__INCLUDED_)
