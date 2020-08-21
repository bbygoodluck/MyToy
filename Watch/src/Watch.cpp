#include "./global/global.h"
#include "Watch.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(CWatch);

CWatch::CWatch()
{

}

CWatch::~CWatch()
{

}

bool CWatch::OnInit()
{
#ifdef _WXRELEASE
	m_pSingleInstance = new wxSingleInstanceChecker;
	if (m_pSingleInstance->IsAnotherRunning())
	{
		delete m_pSingleInstance;
		m_pSingleInstance = NULL;

		wxMessageBox(wxT("이미 실행중입니다."), wxT("Watch"), wxOK | wxICON_INFORMATION);
		return false;
	}
#endif

	if (!wxApp::OnInit())
	{
		wxMessageBox(wxT("윈도우즈 초기화 실패"), wxT("Watch"), wxOK | wxICON_ERROR);
		return false;
	}

	wxString strPGTitle = wxT("Watch");

#ifdef _WXDEBUG
	strPGTitle += wxT(" - Debug Version");
#endif

	CMainFrame* pMainFrame = new CMainFrame(strPGTitle);
	pMainFrame->Show();

	this->SetTopWindow(pMainFrame);

	//	theSystemInfo->WatcherStart();
	return true;
}

int CWatch::OnExit()
{
	return 0;
}