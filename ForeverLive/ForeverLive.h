// ForeverLive.h : main header file for the FOREVERLIVE application
//

#if !defined(AFX_FOREVERLIVE_H__5AD956A1_5F44_4D01_9EEE_198BF4ACD1DA__INCLUDED_)
#define AFX_FOREVERLIVE_H__5AD956A1_5F44_4D01_9EEE_198BF4ACD1DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CForeverLiveApp:
// See ForeverLive.cpp for the implementation of this class
//

class CForeverLiveApp : public CWinApp
{
public:
	CForeverLiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeverLiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CForeverLiveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOREVERLIVE_H__5AD956A1_5F44_4D01_9EEE_198BF4ACD1DA__INCLUDED_)
