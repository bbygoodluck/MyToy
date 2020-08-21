#include "./global/global.h"
#include "PanelRosePattern.h"
#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(CMainFrame, wxFrame)
	EVT_CLOSE(CMainFrame::OnClose)
wxEND_EVENT_TABLE()


CMainFrame::CMainFrame(const wxString& strTitle)
	: wxFrame(nullptr, wxID_ANY, strTitle, wxDefaultPosition, wxSize(800, 600))
{
	SetIcon(wxIcon("wxwin"));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	m_panelRosePattern = std::make_unique<CPanelRosePattern>(this);
	bSizer1->Add(m_panelRosePattern.get(), 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

//	this->Maximize();
	this->Centre(wxBOTH);
}

CMainFrame::~CMainFrame()
{

}

void CMainFrame::OnClose(wxCloseEvent& event)
{
	Destroy();
}

#ifdef __WXMSW__
WXLRESULT CMainFrame::MSWDefWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam)
{
	WXLRESULT rc;

	rc = ::DefWindowProc(this->GetHWND(), nMsg, wParam, lParam);
	return rc;
}
#endif