#ifndef __MAZE_GENERATOR_H__
#define __MAZE_GENERATOR_H__
//***************************************************************************************
// Program : Maze Generator
// Make by : Bae Byoung Yong
//
//***************************************************************************************

#include <wx/snglinst.h>
class CMazeGenerator : public wxApp
{
public:
	explicit CMazeGenerator();
	virtual ~CMazeGenerator();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

private:
	wxSingleInstanceChecker* m_pSingleInstance;
};

#endif