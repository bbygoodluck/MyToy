#include "./global/global.h"
#include "FireworksApp.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(CFireworksApp);

CFireworksApp::CFireworksApp()
{

}

CFireworksApp::~CFireworksApp()
{

}

bool CFireworksApp::OnInit()
{
#ifdef NDEBUG
	m_pSingleInstance = new wxSingleInstanceChecker;
	if (m_pSingleInstance->IsAnotherRunning())
	{
		delete m_pSingleInstance;
		m_pSingleInstance = NULL;

		wxMessageBox(wxT("Already is Running"), wxT("Watch"), wxOK | wxICON_INFORMATION);
		return false;
	}
#endif

	if (!wxApp::OnInit())
	{
		wxMessageBox(wxT("Windows init is failed"), wxT("Fireworks"), wxOK | wxICON_ERROR);
		return false;
	}

	wxString strPGTitle = wxT("Fireworks");

#ifdef _WXDEBUG
	strPGTitle += wxT(" - Debug Version");
#endif

	CMainFrame* pMainFrame = new CMainFrame(strPGTitle);
	pMainFrame->Show();

	this->SetTopWindow(pMainFrame);

	//	theSystemInfo->WatcherStart();
	return true;
}

int CFireworksApp::OnExit()
{
	return 0;
}