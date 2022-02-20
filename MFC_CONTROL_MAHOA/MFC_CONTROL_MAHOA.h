
// MFC_CONTROL_MAHOA.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCCONTROLMAHOAApp:
// See MFC_CONTROL_MAHOA.cpp for the implementation of this class
//

class CMFCCONTROLMAHOAApp : public CWinApp
{
public:
	CMFCCONTROLMAHOAApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCCONTROLMAHOAApp theApp;
