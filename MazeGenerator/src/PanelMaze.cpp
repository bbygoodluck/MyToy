#include "./global/global.h"
#include "MazeView.h"
#include "PanelMaze.h"

CPanelMaze::CPanelMaze(wxWindow* _parent)
	: wxPanel(_parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN)
{
	Init();
}

CPanelMaze::~CPanelMaze()
{
}

void CPanelMaze::Init()
{
	m_Mainsizer = new wxBoxSizer(wxVERTICAL);
	m_Mainsizer->SetMinSize(wxSize(-1, -1));

	m_pMazeView = std::make_unique<CMazeView>(this, wxDefaultSize);
	m_Mainsizer->Add(m_pMazeView.get(), 1, wxEXPAND, 5);

	SetSizer(m_Mainsizer);
	this->Layout();
}

void CPanelMaze::Update()
{
//	m_pWatchView->Update();
}