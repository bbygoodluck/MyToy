#ifndef __WATCH_H__
#define __WATCH_H__
//***************************************************************************************
// Program : RealTimeMonitor
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CWatch : public wxApp
{
public:
	explicit CWatch();
	virtual ~CWatch();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif