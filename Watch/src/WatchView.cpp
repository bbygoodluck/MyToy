#include "./global/global.h"
#include "WatchView.h"

wxBEGIN_EVENT_TABLE(CWatchView, wxWindow)
	EVT_PAINT(CWatchView::OnPaint)
	EVT_SIZE(CWatchView::OnSize)
	EVT_ERASE_BACKGROUND(CWatchView::OnErase)
	EVT_TIMER(100, CWatchView::OnTimer)
wxEND_EVENT_TABLE()

#define CONV_DEGREE_TO_RADIAN(angle) (float)(angle * (M_PI / 180.0f))
CWatchView::CWatchView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE),
	m_iCenterR(5)
	
{
	m_iPenSize = 39;
	m_iCircleSize = 2;

	m_timer.SetOwner(this, 100);
	m_timer.Start(1000);
}

CWatchView::~CWatchView()
{
	if (m_timer.IsRunning())
		m_timer.Stop();

	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;
}

void CWatchView::OnPaint(wxPaintEvent& event)
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

void CWatchView::Render(wxDC* pDC)
{
	pDC->SetTextForeground(wxColour(255, 255, 255));
	DisplayHour(pDC);
	DisplayMinute(pDC);
	DisplaySecond(pDC);

	wxPen penSec(wxColour(255, 255, 0), 2, wxPENSTYLE_SHORT_DASH);
	pDC->SetPen(penSec);
	pDC->DrawLine(0, 0, m_fSecX, m_fSecY);
	
	if (!m_strNowTime.IsEmpty())
	{
		wxSize szTime = pDC->GetTextExtent(m_strNowTime);

		wxRect rcTime(-90, -15, szTime.GetWidth() + 15, szTime.GetHeight() + 5);
		wxPen rcPen(wxColour(0, 0, 0), 1, wxPENSTYLE_SOLID);
		wxBrush rcBrush(wxColour(0, 0, 0));

		pDC->SetPen(rcPen);
		pDC->SetBrush(rcBrush);
		pDC->DrawRoundedRectangle(rcTime, 2.0);

		pDC->DrawLabel(m_strNowTime, rcTime, wxALIGN_CENTER);
	}
}

void CWatchView::DisplayHour(wxDC* pDC)
{
	wxPen pen(wxColour(30, 250, 24), m_iPenSize, wxPENSTYLE_SOLID);
	wxBrush brush(wxColour(30, 250, 24));

	pDC->SetPen(pen);
	pDC->SetBrush(brush);

	float fStartX = 0.0f;
	float fStartY = (-1.0f * m_iYCenter) + 30.0f;

	float fNewX = 0.0f;
	float fNewY = 0.0f;

	if (m_iHour == 0)
	{
		pDC->DrawCircle(fStartX, fStartY, m_iCircleSize);
		return;
	}

	m_iHour = m_iHour > 12 ? m_iHour - 12 : m_iHour;
	int iCount = m_iHour * 30;
	for (int i = 0; i < iCount; i++)
		Rotate(&fNewX, &fNewY, fStartX, fStartY, CONV_DEGREE_TO_RADIAN(i));

	pDC->SetBrush(wxNullBrush);

	brush.SetStyle(wxBRUSHSTYLE_TRANSPARENT);
	pDC->SetBrush(brush);

	pDC->DrawArc(wxPoint(fNewX, fNewY), wxPoint(fStartX, fStartY), wxPoint(0, 0));
	pDC->DrawText(wxString::Format(wxT("%02d"), m_iHour), fNewX - 10, fNewY - 8);
}

void CWatchView::DisplayMinute(wxDC* pDC)
{
	wxPen pen(wxColour(49, 123, 247), m_iPenSize, wxPENSTYLE_SOLID);
	wxBrush brush(wxColour(49, 123, 247));

	pDC->SetPen(pen);
	pDC->SetBrush(brush);

	float fStartX = 0.0f;
	float fStartY = (-1.0f * m_iYCenter) + 80.0f;

	float fNewX = 0.0f;
	float fNewY = 0.0f;
	
	int iCount = m_iMinute * 6;
	if (iCount == 0)
		pDC->DrawCircle(fStartX, fStartY, m_iCircleSize);
	else
	{
		for (int i = 0; i < iCount; i++)
			Rotate(&fNewX, &fNewY, fStartX, fStartY, CONV_DEGREE_TO_RADIAN(i));

		pDC->SetBrush(wxNullBrush);

		brush.SetStyle(wxBRUSHSTYLE_TRANSPARENT);
		pDC->SetBrush(brush);

		pDC->DrawArc(wxPoint(fNewX, fNewY), wxPoint(fStartX, fStartY), wxPoint(0, 0));
		pDC->DrawText(wxString::Format(wxT("%02d"), m_iMinute), fNewX - 10, fNewY - 8);
	}
}

void CWatchView::DisplaySecond(wxDC* pDC)
{
	wxPen pen(wxColour(255, 100, 255), m_iPenSize, wxPENSTYLE_SOLID);
	wxBrush brush(wxColour(255, 100, 255));
	
	pDC->SetPen(pen);
	pDC->SetBrush(brush);

	float fStartX = 0.0f;
	float fStartY = (-1.0f * m_iYCenter) + 130.0f;
	float fStartSecX = 0.0f;
	float fStartSecY = (-1.0f * m_iYCenter) + 160.0f;
	
	float fNewX = 0.0f;
	float fNewY = 0.0f;
	float fNewSecX = 0.0f;
	float fNewSecY = 0.0f;
	int iCount = m_iSecond * 6;

	m_fSecX = fNewSecX;
	m_fSecY = fStartSecY;

	if (iCount == 0)
		pDC->DrawCircle(fStartX, fStartY, m_iCircleSize);
	else
	{
		for (int i = 0; i < iCount; i++)
		{
			Rotate(&fNewX, &fNewY, fStartX, fStartY, CONV_DEGREE_TO_RADIAN(i));
			Rotate(&fNewSecX, &fNewSecY, fStartSecX, fStartSecY, CONV_DEGREE_TO_RADIAN(i));
		}

		m_fSecX = fNewSecX;
		m_fSecY = fNewSecY;

		pDC->SetBrush(wxNullBrush);
	
		brush.SetStyle(wxBRUSHSTYLE_TRANSPARENT);
		pDC->SetBrush(brush);
		
		pDC->DrawArc(wxPoint(fNewX, fNewY), wxPoint(fStartX, fStartY), wxPoint(0, 0));
		pDC->DrawText(wxString::Format(wxT("%02d"), m_iSecond), fNewX - 10, fNewY - 8);
	}
}

void CWatchView::Rotate(float* nx, float* ny, float tx, float ty, float fradian)
{
	float fsin = sin(fradian);
	float fcos = cos(fradian);

	*nx = tx * fcos - ty * fsin;
	*ny = tx * fsin + ty * fcos;
}

void CWatchView::OnSize(wxSizeEvent& event)
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

void CWatchView::OnErase(wxEraseEvent& event)
{

}

void CWatchView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
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


void CWatchView::Update()
{
	UpdateView(this, m_viewRect);
}

void CWatchView::OnTimer(wxTimerEvent& event)
{
	wxDateTime now = wxDateTime::Now();
	m_strNowTime = now.FormatISODate();
	m_strNowTime += wxT(" ");
	m_strNowTime += now.FormatISOTime();

	m_iHour = now.GetHour();
	m_iMinute = now.GetMinute();
	m_iSecond = now.GetSecond();

	UpdateView(this, m_viewRect);
}