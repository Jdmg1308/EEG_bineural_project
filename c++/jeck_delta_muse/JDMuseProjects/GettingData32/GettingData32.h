
// GettingData32.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGettingData32App:
// See GettingData32.cpp for the implementation of this class
//

class CGettingData32App : public CWinApp
{
public:
	CGettingData32App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()
};

extern CGettingData32App theApp;
