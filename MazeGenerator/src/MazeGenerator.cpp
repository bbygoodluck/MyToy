#include "./global/global.h"
#include "MazeGenerator.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(CMazeGenerator);

CMazeGenerator::CMazeGenerator()
{

}

CMazeGenerator::~CMazeGenerator()
{

}

bool CMazeGenerator::OnInit()
{
#ifdef _WXRELEASE
	m_pSingleInstance = new wxSingleInstanceChecker;
	if (m_pSingleInstance->IsAnotherRunning())
	{
		delete m_pSingleInstance;
		m_pSingleInstance = NULL;

		wxMessageBox(wxT("이미 실행중입니다."), wxT("미로만들기"), wxOK | wxICON_INFORMATION);
		return false;
	}
#endif

	if (!wxApp::OnInit())
	{
		wxMessageBox(wxT("윈도우즈 초기화 실패"), wxT("미로만들기"), wxOK | wxICON_ERROR);
		return false;
	}

	wxString strPGTitle = wxT("미로만들기");

#ifdef _WXDEBUG
	strPGTitle += wxT(" - Debug Version");
#endif

	CMainFrame* pMainFrame = new CMainFrame(strPGTitle);
	pMainFrame->Show();

	this->SetTopWindow(pMainFrame);

	//	theSystemInfo->WatcherStart();
	return true;
}

int CMazeGenerator::OnExit()
{
	return 0;
}