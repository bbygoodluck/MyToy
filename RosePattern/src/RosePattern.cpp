#include "./global/global.h"
#include "RosePattern.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(CRosePattern);

CRosePattern::CRosePattern()
{

}

CRosePattern::~CRosePattern()
{

}

bool CRosePattern::OnInit()
{
#ifdef _WXRELEASE
	m_pSingleInstance = new wxSingleInstanceChecker;
	if (m_pSingleInstance->IsAnotherRunning())
	{
		delete m_pSingleInstance;
		m_pSingleInstance = NULL;

		wxMessageBox(wxT("이미 실행중입니다."), wxT("RosePattern"), wxOK | wxICON_INFORMATION);
		return false;
	}
#endif

	if (!wxApp::OnInit())
	{
		wxMessageBox(wxT("윈도우즈 초기화 실패"), wxT("RosePattern"), wxOK | wxICON_ERROR);
		return false;
	}

	wxString strPGTitle = wxT("RosePattern");

#ifdef _WXDEBUG
	strPGTitle += wxT(" - Debug Version");
#endif

	CMainFrame* pMainFrame = new CMainFrame(strPGTitle);
	pMainFrame->Show();

	this->SetTopWindow(pMainFrame);

	//	theSystemInfo->WatcherStart();
	return true;
}

int CRosePattern::OnExit()
{
	return 0;
}