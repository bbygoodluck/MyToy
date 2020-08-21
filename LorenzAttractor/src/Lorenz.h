#ifndef __LORENZ_H__
#define __LORENZ_H__
//***************************************************************************************
// Program : Lorenz Attractor
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CLorenz : public wxApp
{
public:
	explicit CLorenz();
	virtual ~CLorenz();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif