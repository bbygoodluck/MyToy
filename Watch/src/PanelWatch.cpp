#include "./global/global.h"
#include "WatchView.h"
#include "PanelWatch.h"


CPanelWatch::CPanelWatch(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelWatch::~CPanelWatch()
{
}

void CPanelWatch::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pWatchView = std::make_unique<CWatchView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pWatchView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
//	this->Layout();
}

void CPanelWatch::Update()
{
	m_pWatchView->Update();
}