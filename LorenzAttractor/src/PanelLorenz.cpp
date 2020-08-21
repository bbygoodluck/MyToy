#include "./global/global.h"
#include "LorenzView.h"
#include "PanelLorenz.h"


CPanelLorenz::CPanelLorenz(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelLorenz::~CPanelLorenz()
{
}

void CPanelLorenz::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pLorenzView = std::make_unique<CLorenzView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pLorenzView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
//	this->Layout();
}

void CPanelLorenz::Update()
{
//	m_pWatchView->Update();
}