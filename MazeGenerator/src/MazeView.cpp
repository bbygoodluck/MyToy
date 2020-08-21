#include "./global/global.h"
#include "MazeView.h"
#include "Cell.h"

wxBEGIN_EVENT_TABLE(CMazeView, wxWindow)
	EVT_PAINT(CMazeView::OnPaint)
	EVT_SIZE(CMazeView::OnSize)
	EVT_ERASE_BACKGROUND(CMazeView::OnErase)
	EVT_TIMER(100, CMazeView::OnTimer)
	EVT_LEFT_DOWN(CMazeView::OnMousetLBottonDown)
	EVT_RIGHT_DOWN(CMazeView::OnMouseRButtonDown)
wxEND_EVENT_TABLE()

CMazeView::CMazeView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE)	
	, m_w(20)
{
	m_timer.SetOwner(this, 100);
}

CMazeView::~CMazeView()
{
	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;

	Clear();
}

void CMazeView::Clear()
{
	m_timer.Stop();
	for (int index = 0; index < m_cellGrid.size(); index++)
		delete m_cellGrid[index];

	m_cellGrid.clear();
	m_vecStack.clear();
	wxVector<CCell *>().swap(m_cellGrid);
	m_cellGrid.reserve(0);
}

void CMazeView::OnPaint(wxPaintEvent& event)
{
	if (!m_pDoubleBuffer->IsOk())
		return;
	
	wxPaintDC dc(this);
	PrepareDC(dc);

	m_viewRect = GetClientRect();

	wxPen pen(wxColour(0, 0, 0));
	wxBrush brush(wxColour(0, 0, 0));

	wxMemoryDC memDC(&dc);
	memDC.SelectObjectAsSource(*m_pDoubleBuffer);

	memDC.SetFont(wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT));
	memDC.SetPen(pen);
	memDC.SetBrush(brush);

	memDC.DrawRectangle(m_viewRect);
	
	Render(&memDC);
	
	dc.Blit(0, 0, m_pDoubleBuffer->GetWidth(), m_pDoubleBuffer->GetHeight(), &memDC, 0, 0);

	memDC.SetFont(wxNullFont);
	memDC.SetPen(wxNullPen);
	memDC.SetBrush(wxNullBrush);
	memDC.SelectObjectAsSource(wxNullBitmap);
}

void CMazeView::Render(wxDC* pDC)
{
	if (m_cellGrid.size() == 0)
	{
		m_cols = m_viewRect.GetWidth() / m_w;
		m_rows = m_viewRect.GetHeight() / m_w;

		for (int j = 0; j < m_cols; j++)
		{
			for (int i = 0; i < m_rows; i++)
			{
				CCell* pCell = new CCell(i, j, m_w);
				m_cellGrid.push_back(pCell);
			}
		}

		m_pCurrent = m_cellGrid[0];
		m_pCurrent->m_bVisited = true;

		m_timer.Start(40);
	}

	for (int index = 0; index < m_cellGrid.size(); index++)
	{
		m_cellGrid[index]->show(pDC);
	}

	m_pCurrent->highLight(pDC);
	
	//step 1
	CCell* pNext = m_pCurrent->checkNeighbors(m_cols, m_rows, m_cellGrid);
	if (pNext)
	{
		pNext->m_bVisited = true;
		//step2
		m_vecStack.push_back(m_pCurrent);
		m_iStackIndex++;
		//step 3
		removeWalls(m_pCurrent, pNext);
		//step 4
		m_pCurrent = pNext;
	}
	else if(m_vecStack.size() > 0)
	{
		m_pCurrent = m_vecStack[m_vecStack.size() - 1];
		m_vecStack.pop_back();
	}
}

void CMazeView::removeWalls(CCell* pCurrent, CCell* pNext)
{
	int x = pCurrent->m_i - pNext->m_i;
	if (x == 1)
	{
		pCurrent->Walls[3] = false;
		pNext->Walls[1] = false;
	}
	else if (x == -1)
	{
		pCurrent->Walls[1] = false;
		pNext->Walls[3] = false;
	}

	int y = pCurrent->m_j - pNext->m_j;
	if (y == 1)
	{
		pCurrent->Walls[0] = false;
		pNext->Walls[2] = false;
	}
	else if (y == -1)
	{
		pCurrent->Walls[2] = false;
		pNext->Walls[0] = false;
	}
}

void CMazeView::OnSize(wxSizeEvent& event)
{
	wxSize size = GetClientSize();
	if ((size.x == 0) || (size.y == 0))
		return;

	if (m_szChagned.x != size.x)
	{
		m_szChagned = size;
		if (m_pDoubleBuffer)
			delete m_pDoubleBuffer;

		m_pDoubleBuffer = new wxBitmap(m_szChagned.x, m_szChagned.y);
	}
	

	Clear();
	m_bResize = true;
	UpdateView(this, m_viewRect);
}

void CMazeView::OnErase(wxEraseEvent& event)
{

}

void CMazeView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
{
#ifdef __WXMSW__
	HWND hWnd = pWindow->GetHWND();
	if (rect.GetWidth() != 0)
	{
		RECT mswRect;
		const RECT* pRect;

		wxCopyRectToRECT(rect, mswRect);
		pRect = &mswRect;

		//	INT flags = RDW_INVALIDATE | RDW_NOCHILDREN | RDW_UPDATENOW | RDW_ERASE;
		//	::RedrawWindow(hWnd, pRect, NULL, flags);
		::InvalidateRect(hWnd, pRect, false);
	}
	else
		pWindow->Refresh(false);

	if (bUpdate) pWindow->Update();
	//	::UpdateWindow(hWnd);
#else
	pWindow->RefreshRect(rect, false);
	pWindow->Update();
#endif
}


void CMazeView::Update()
{
	UpdateView(this, m_viewRect);
}

void CMazeView::OnTimer(wxTimerEvent& event)
{
	UpdateView(this, m_viewRect);
}

void CMazeView::OnMousetLBottonDown(wxMouseEvent& event)
{
	Clear();
	UpdateView(this, m_viewRect);
}

void CMazeView::OnMouseRButtonDown(wxMouseEvent& event)
{
	m_timer.Stop();
	Clear();
	m_w *= 2;
	if (m_w > 80)
		m_w = 20;

	UpdateView(this, m_viewRect);
}