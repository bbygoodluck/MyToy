#include "./global/global.h"
#include "FireworksView.h"

wxBEGIN_EVENT_TABLE(CFireworksView, wxWindow)
	EVT_PAINT(CFireworksView::OnPaint)
	EVT_SIZE(CFireworksView::OnSize)
	EVT_ERASE_BACKGROUND(CFireworksView::OnErase)
	EVT_TIMER(100, CFireworksView::OnTimer)
wxEND_EVENT_TABLE()

CFireworksView::CFireworksView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE)
{
	fElaspsedTime = 0.1f;
//	fDelay = 0.5f;
	m_timer.SetOwner(this, 100);
	m_timer.Start(30);
}

CFireworksView::~CFireworksView()
{
	if (m_timer.IsRunning())
		m_timer.Stop();

	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;
}

void CFireworksView::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	if (!m_pDoubleBuffer)
		return;

	if (!m_pDoubleBuffer->IsOk())
		return;

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

void CFireworksView::Render(wxDC* pDC)
{
	fDelay -= fElaspsedTime;
	if (fDelay <= 0.0f) 
	{
		fDelay = ((float)rand() / (float)RAND_MAX) * 1.5f + 0.1f;
		for(int i = 0; i < 2; i++)
			listFireworks.push_back({ (float)(m_viewRect.GetRight() / 2), (float)m_viewRect.GetHeight(), (rand() % 500 + 200)});
	}

	for (auto &f : listFireworks)
	{
		f.Update(fElaspsedTime);
		f.DrawSelf(pDC);
	}

	listFireworks.remove_if([](const cFireworks &f) {return f.bExpired; });
}

void CFireworksView::OnSize(wxSizeEvent& event)
{
	wxSize size = GetClientSize();
	if ((size.x == 0) || (size.y == 0))
		return;

	if (m_szChanged.x != size.x)
	{
		m_szChanged = size;
		if (m_pDoubleBuffer)
			delete m_pDoubleBuffer;

		m_pDoubleBuffer = new wxBitmap(m_szChanged.x, m_szChanged.y);
	}

	m_bResize = true;
	UpdateView(this, m_viewRect);
}

void CFireworksView::OnErase(wxEraseEvent& event)
{

}

void CFireworksView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
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


void CFireworksView::Update()
{
	UpdateView(this, m_viewRect);
}

void CFireworksView::OnTimer(wxTimerEvent& event)
{
//	fDelay -= 0.1f;
	Update();
}