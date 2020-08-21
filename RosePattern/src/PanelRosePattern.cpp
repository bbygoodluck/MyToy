#include "./global/global.h"
#include "RosePatternView.h"
#include "PanelRosePattern.h"


CPanelRosePattern::CPanelRosePattern(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelRosePattern::~CPanelRosePattern()
{
}

void CPanelRosePattern::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pRosePatternView = std::make_unique<CRosePatternView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pRosePatternView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
//	this->Layout();
}

void CPanelRosePattern::Update()
{
//	m_pWatchView->Update();
}