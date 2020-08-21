#include "./global/global.h"
#include "LorenzView.h"

wxBEGIN_EVENT_TABLE(CLorenzView, wxWindow)
	EVT_PAINT(CLorenzView::OnPaint)
	EVT_SIZE(CLorenzView::OnSize)
	EVT_ERASE_BACKGROUND(CLorenzView::OnErase)
	EVT_TIMER(100, CLorenzView::OnTimer)
wxEND_EVENT_TABLE()

#define CONV_DEGREE_TO_RADIAN(angle) (float)(angle * (M_PI / 180.0f))
CLorenzView::CLorenzView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE)
	, m_iLorenzCount(4000)
{
	a = 10.0f;
	b = 28.0f;
	c = 8.0f / 3.0f;

	xPos = 0.5f;
	yPos = 0.5f;
	zPos = 0.0f;
	t = 0.01f;

	m_timer.SetOwner(this, 100);
	m_timer.Start(800);
}

CLorenzView::~CLorenzView()
{
	if (m_timer.IsRunning())
		m_timer.Stop();

	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;

	for (auto item : m_vecLorenzPos)
		delete item;

	m_vecLorenzPos.clear();
}

void CLorenzView::OnPaint(wxPaintEvent& event)
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
	
	m_iXCenter = m_viewRect.GetWidth() / 2;
	m_iYCenter = m_viewRect.GetHeight() / 2;

	::SetViewportOrgEx(memDC.GetHDC(), m_iXCenter, m_iYCenter, nullptr);

	Render(&memDC);

	dc.Blit(0, 0, m_pDoubleBuffer->GetWidth(), m_pDoubleBuffer->GetHeight(), &memDC, -1 * m_iXCenter, -1 * m_iYCenter);


	memDC.SetFont(wxNullFont);
	memDC.SetPen(wxNullPen);
	memDC.SetBrush(wxNullBrush);
	memDC.SelectObjectAsSource(wxNullBitmap);
}

void CLorenzView::Render(wxDC* pDC)
{
	wxPen pen(wxColour(255, 255, 255));
	wxBrush brush(wxColour(255, 255, 255));
	pDC->SetPen(pen);
	pDC->SetBrush(brush);


//	if (m_vecLorenzPos.size() == 0)
//	{
		for (int i = 0; i < m_iLorenzCount; i++)
		{
			float dx = t * (a * (yPos - xPos));
			float dy = t * xPos * (b - zPos) - yPos;
			float dz = t * xPos * yPos - c * zPos;

	//		LORENZPOS* pPos = new LORENZPOS;
	//		pPos->x = dx;
	//		pPos->y = dy;
	//		pPos->z = dz;

	//		m_vecLorenzPos.push_back(pPos);
			pDC->DrawPoint(dx, dy);

			xPos = dx;
			yPos = dy;
			zPos = dz;
		}
//	}
	
//	for (auto item : m_vecLorenzPos)
//		pDC->DrawPoint(item->x, item->y);

}

void CLorenzView::OnSize(wxSizeEvent& event)
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

void CLorenzView::OnErase(wxEraseEvent& event)
{

}

void CLorenzView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
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


void CLorenzView::Update()
{
	UpdateView(this, m_viewRect);
}

void CLorenzView::OnTimer(wxTimerEvent& event)
{
	UpdateView(this, m_viewRect);
}