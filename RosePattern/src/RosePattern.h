#ifndef __ROSE_PATTERN_H__
#define __ROSE_PATTERN_H__
//***************************************************************************************
// Program : Lorenz Attractor
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CRosePattern : public wxApp
{
public:
	explicit CRosePattern();
	virtual ~CRosePattern();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif