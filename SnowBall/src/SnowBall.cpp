#include "./global/global.h"
#include "SnowBall.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(CSnowBallApp);

CSnowBallApp::CSnowBallApp()
{

}

CSnowBallApp::~CSnowBallApp()
{

}

bool CSnowBallApp::OnInit()
{
#ifdef _WXRELEASE
	m_pSingleInstance = new wxSingleInstanceChecker;
	if (m_pSingleInstance->IsAnotherRunning())
	{
		delete m_pSingleInstance;
		m_pSingleInstance = NULL;

		wxMessageBox(wxT("이미 실행중입니다."), wxT("Snow Ball"), wxOK | wxICON_INFORMATION);
		return false;
	}
#endif

	if (!wxApp::OnInit())
	{
		wxMessageBox(wxT("윈도우즈 초기화 실패"), wxT("Snow Ball"), wxOK | wxICON_ERROR);
		return false;
	}

	wxString strPGTitle = wxT("Snow Ball");

#ifdef _WXDEBUG
	strPGTitle += wxT(" - Debug Version");
#endif

	CMainFrame* pMainFrame = new CMainFrame(strPGTitle);
	pMainFrame->Show();

	this->SetTopWindow(pMainFrame);

	return true;
}

int CSnowBallApp::OnExit()
{
	return 0;
}