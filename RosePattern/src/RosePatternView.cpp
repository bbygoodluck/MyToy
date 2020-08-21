/****************************************************************************************
/* Rose Patterns(Mathematics)
/* 참조 사이트 : https://en.wikipedia.org/wiki/Rose_(mathematics)
****************************************************************************************/
#include "./global/global.h"
#include "RosePatternView.h"

wxBEGIN_EVENT_TABLE(CRosePatternView, wxWindow)
	EVT_PAINT(CRosePatternView::OnPaint)
	EVT_SIZE(CRosePatternView::OnSize)
	EVT_ERASE_BACKGROUND(CRosePatternView::OnErase)
	EVT_LEFT_DOWN(CRosePatternView::OnMousetLBottonDown)
	EVT_RIGHT_DOWN(CRosePatternView::OnMouseRButtonDown)
	EVT_TIMER(100, CRosePatternView::OnTimer)
wxEND_EVENT_TABLE()

CRosePatternView::CRosePatternView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE)
{
	m_d = 8.0f;
	m_n = 5.0f;

	m_enumK = CHANGE_D;
	m_k = m_n / m_d;

	m_timer.SetOwner(this, 100);
	m_timer.Start(300);
}

CRosePatternView::~CRosePatternView()
{
	if (m_timer.IsRunning())
		m_timer.Stop();

	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;
}

void CRosePatternView::OnPaint(wxPaintEvent& event)
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

void CRosePatternView::Render(wxDC* pDC)
{
	wxString strValue = wxString::Format(wxT("d : %.1f   n : %.1f"), m_d, m_n);
	pDC->SetTextForeground(wxColour(255, 255, 255));
	pDC->DrawText(strValue, -75, -1 * m_iYCenter + 10);

	wxPen pen(wxColour(100 + rand() % 155, 100 + rand() % 155, 100 + rand() % 155));
	pDC->SetPen(pen);

	for (float a = 0.0f; a < 360.0f; a += 0.01f)
	{
		float r = 200 * cos(m_k * a);
		float x = r * cos(a);
		float y = r * sin(a);

		pDC->DrawPoint(x, y);
	}
}

void CRosePatternView::OnSize(wxSizeEvent& event)
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

void CRosePatternView::OnErase(wxEraseEvent& event)
{

}

void CRosePatternView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
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


void CRosePatternView::Update()
{
	UpdateView(this, m_viewRect);
}

//void CRosePatternView::OnTimer(wxTimerEvent& event)
//{
//	UpdateView(this, m_viewRect);
//}

void CRosePatternView::OnMousetLBottonDown(wxMouseEvent& event)
{
	if (m_enumK == CHANGE_D)
		m_enumK = CHANGE_N;
	else
		m_enumK = CHANGE_D;}

void CRosePatternView::OnMouseRButtonDown(wxMouseEvent& event)
{
	/*m_n += 1.0f;
	if (m_n > 10.0f)
		m_n = 1.0f;

	m_k = m_n / m_d;
	Update();*/
}

void CRosePatternView::OnTimer(wxTimerEvent& event)
{
	if (m_enumK == CHANGE_D)
	{
		m_d += 1.0f;
		if (m_d > 10.0f)
			m_d = 1.0f;		
	}
	else
	{
		m_n += 1.0f;
		if (m_n > 10.0f)
			m_n = 1.0f;
	}

	m_k = m_n / m_d;
	Update();
}