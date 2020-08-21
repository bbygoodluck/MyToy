#ifndef __WATCH_VIEW_H__
#define __WATCH_VIEW_H__

class CWatchView : public wxWindow
{
public:
	explicit CWatchView(wxWindow* _parent, const wxSize& _size);
	virtual ~CWatchView();
	
	void Update();

protected:
	void Render(wxDC* pDC);
	
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);
	void Rotate(float* nx, float* ny, float tx, float ty, float fradian);
	void DisplayHour(wxDC* pDC);
	void DisplayMinute(wxDC* pDC);
	void DisplaySecond(wxDC* pDC);

private:
	wxRect m_viewRect;
	wxBitmap* m_pDoubleBuffer = nullptr;
	wxSize m_szChanged;

	bool m_bResize = false;
	
	wxTimer m_timer;

	int m_iXCenter = 0;
	int m_iYCenter = 0;
	int m_iCenterR = 0;
	
	int m_iHour = 0;
	int m_iMinute = 0;
	int m_iSecond = 0;
	int m_iPenSize = 10;
	int m_iCircleSize = 15;
	float m_fSecX;
	float m_fSecY;
	wxString m_strNowTime;
private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnTimer(wxTimerEvent& event);

	wxDECLARE_EVENT_TABLE();
};
#endif
