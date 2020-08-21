#include "./global/global.h"
#include "FireworksView.h"
#include "PanelFireworks.h"


CPanelFireworks::CPanelFireworks(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelFireworks::~CPanelFireworks()
{
}

void CPanelFireworks::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pFireworksView = std::make_unique<CFireworksView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pFireworksView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
//	this->Layout();
}

void CPanelFireworks::Update()
{
//	m_pFireworksView->Update();
}