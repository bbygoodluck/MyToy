#include "../global/global.h"
#include "Snow.h"
#include "SnowBallView.h"

int _gSnowBallCount = 550;
wxBEGIN_EVENT_TABLE(CSnowBallView, wxWindow)
	EVT_PAINT(CSnowBallView::OnPaint)
	EVT_SIZE(CSnowBallView::OnSize)
	EVT_ERASE_BACKGROUND(CSnowBallView::OnErase)
	EVT_MOTION(CSnowBallView::OnMouseMove)
	EVT_LEFT_DOWN(CSnowBallView::OnMouseClick)
	EVT_TIMER(100, CSnowBallView::OnTimer)
wxEND_EVENT_TABLE()

CSnowBallView::CSnowBallView(wxWindow* _parent, const wxSize& _size)
	: wxWindow(_parent, wxID_ANY, wxDefaultPosition, _size, wxBORDER_NONE | wxCLIP_CHILDREN | /* wxTRANSPARENT_WINDOW  |*/ wxCLIP_SIBLINGS | wxNO_FULL_REPAINT_ON_RESIZE)
	, m_oldPt(0,0)
{
	m_vecSnow.reserve(_gSnowBallCount);
	m_timer.SetOwner(this, 100);
	m_timer.Start(10);
}

CSnowBallView::~CSnowBallView()
{
	m_bStop = true;
	if (m_timer.IsRunning())
		m_timer.Stop();

	if (m_pDoubleBuffer)
		delete m_pDoubleBuffer;

	m_pDoubleBuffer = nullptr;

	wxVector<CSnow *>::const_iterator iter = m_vecSnow.begin();
	for (iter; iter != m_vecSnow.end(); ++iter)
	{
		CSnow* pSnow = *iter;
		delete pSnow;

		pSnow = nullptr;
	}
}

void CSnowBallView::OnPaint(wxPaintEvent& event)
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
	
	if (m_vecSnow.size() == 0)
	{
		for (int i = 0; i < _gSnowBallCount; i++)
		{
			CSnow* pSnow = new CSnow(m_viewRect);

			pSnow->hFont = CreateFont(-MulDiv(pSnow->_FontSize, GetDeviceCaps(memDC.GetHDC(), LOGPIXELSY), 72), 0, pSnow->_Angle, pSnow->_Angle, 
				FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, pSnow->_strFont);

			m_vecSnow.push_back(pSnow);
		}
	}

	if (m_bResize)
	{
		for (int i = 0; i < _gSnowBallCount; i++)
		{
			CSnow* pSnowItem = m_vecSnow.at(i);
			pSnowItem->Reset(m_viewRect);
		}

		m_bResize = false;
	}

	Render(&memDC);

	dc.Blit(0, 0, m_pDoubleBuffer->GetWidth(), m_pDoubleBuffer->GetHeight(), &memDC, 0, 0);

	memDC.SetFont(wxNullFont);
	memDC.SetPen(wxNullPen);
	memDC.SetBrush(wxNullBrush);
	memDC.SelectObjectAsSource(wxNullBitmap);
}

void CSnowBallView::Render(wxDC* pDC)
{
	static HFONT    hFont, hFontOld;
	wxPen pen(wxColour(255, 255, 255));
	int iDisplayCount = _gSnowBallCount;
	if (dropType == SNOWFLOWER)
		iDisplayCount = wx_static_cast(int, m_viewRect.GetRight() * 0.08);

	for (int i = 0; i < iDisplayCount; i++)
	{
		if (m_bStop)
			break;

		CSnow* pSnowItem = m_vecSnow.at(i);
		wxBrush brush(pSnowItem->_color);

		if (dropType == RAIN || dropType == SNOW)
		{
			pDC->SetPen(pen);
			pDC->SetBrush(brush);
		}

		if (dropType == RAIN)
			pDC->DrawLine(pSnowItem->_xPos, pSnowItem->_yPos, pSnowItem->_xPos, pSnowItem->_yPos + pSnowItem->_fHeight);
		else if (dropType == SNOW)
		{
			pDC->DrawEllipse(pSnowItem->_xPos, pSnowItem->_yPos, pSnowItem->_fWidth, pSnowItem->_fHeight);
		}
		else
		{
			pDC->SetTextForeground(pSnowItem->_color);
			pDC->SetFont(pSnowItem->_font);
			pDC->DrawText(wxT("*"), pSnowItem->_xPos, pSnowItem->_yPos);
			pDC->SetFont(wxNullFont);
		}

		pSnowItem->Update();
	}
}

void CSnowBallView::OnSize(wxSizeEvent& event)
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
	
	m_bResize = true;
	UpdateView(this, m_viewRect);
}

void CSnowBallView::OnErase(wxEraseEvent& event)
{
	UpdateView(this, m_viewRect);
}

void CSnowBallView::UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate)
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

void CSnowBallView::OnMouseClick(wxMouseEvent& event)
{
	if (dropType == SNOW)
		dropType = RAIN;
	else if (dropType == RAIN)
		dropType = SNOWFLOWER;
	else if (dropType == SNOWFLOWER)
		dropType = SNOW;
}

void CSnowBallView::OnMouseMove(wxMouseEvent& event)
{
	/*if (m_vecSnow.size() == 0 || m_vecSnow.size() < _gSnowBallCount)
		return;

	wxPoint pt = event.GetPosition();

	if (m_oldPt.x < pt.x)
		m_fXSpeed -= (float)0.1;
	else if (m_oldPt.x > pt.x)
		m_fXSpeed += (float)0.1;
	else
		m_fXSpeed = 0.0;

	m_oldPt = pt;

	for (int i = 0; i < _gSnowBallCount; i++)
	{
		if (m_bStop)
			break;

		CSnow* pSnowItem = m_vecSnow.at(i);
		pSnowItem->_fXSpeed = m_fXSpeed;
	
		pSnowItem->Update();
	}*/
}

void CSnowBallView::Update()
{
	UpdateView(this, m_viewRect);
}

void CSnowBallView::OnTimer(wxTimerEvent& event)
{
	UpdateView(this, m_viewRect);
}