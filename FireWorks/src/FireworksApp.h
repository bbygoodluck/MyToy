#ifndef __FIREWORKS_H__
#define __FIREWORKS_H__
//***************************************************************************************
// Program : FireWorks
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CFireworksApp : public wxApp
{
public:
	explicit CFireworksApp();
	virtual ~CFireworksApp();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif