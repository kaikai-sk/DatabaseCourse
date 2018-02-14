#if !defined(AFX_TIMEQUERYDLG_H__FCA933EA_6A9B_49F0_96B9_4B6144EFADF9__INCLUDED_)
#define AFX_TIMEQUERYDLG_H__FCA933EA_6A9B_49F0_96B9_4B6144EFADF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeQueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TimeQueryDlg dialog

class TimeQueryDlg : public CDialog
{
// Construction
public:
	TimeQueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TimeQueryDlg)
	enum { IDD = IDD_DIALOG_TIMEQUERY };
	COleDateTime	m_startDate;
	COleDateTime	m_endDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TimeQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TimeQueryDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEQUERYDLG_H__FCA933EA_6A9B_49F0_96B9_4B6144EFADF9__INCLUDED_)
