#include "./global/global.h"
#include "./view/SnowBallView.h"
#include "PanelSnowBall.h"


CPanelSnowBall::CPanelSnowBall(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelSnowBall::~CPanelSnowBall()
{
}

void CPanelSnowBall::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pSnowBallView = std::make_unique<CSnowBallView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pSnowBallView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
	this->Layout();
}

void CPanelSnowBall::Update()
{
	m_pSnowBallView->Update();
}