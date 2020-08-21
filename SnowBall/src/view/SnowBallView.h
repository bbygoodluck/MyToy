#ifndef __CPU_GRAPH_VIEW_H__
#define __CPU_GRAPH_VIEW_H__

class CSnow;
class CSnowBallView : public wxWindow
{
	typedef enum {
		SNOW = 0,
		RAIN,
		SNOWFLOWER
	} DROPTYPE;
public:
	explicit CSnowBallView(wxWindow* _parent, const wxSize& _size);
	virtual ~CSnowBallView();
	
	void Update();

protected:
	void Render(wxDC* pDC);
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);

private:
	wxRect m_viewRect;
	wxPoint m_oldPt;
	wxBitmap* m_pDoubleBuffer;
	wxSize m_szChagned;
	wxVector<CSnow *> m_vecSnow;

	bool m_bStop = false;
	bool m_bResize = false;
	float m_fXSpeed = 0.0;

	wxTimer m_timer;
	DROPTYPE dropType = SNOW;
private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnMouseClick(wxMouseEvent& event);
	void OnTimer(wxTimerEvent& event);

	wxDECLARE_EVENT_TABLE();
};
#endif
