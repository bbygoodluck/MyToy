#ifndef __SNOWBALL_H__
#define __SNOWBALL_H__
//***************************************************************************************
// Program : RealTimeMonitor
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CSnowBallApp : public wxApp
{
public:
	explicit CSnowBallApp();
	virtual ~CSnowBallApp();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif