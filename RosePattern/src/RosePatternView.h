#ifndef __ROSE_PATTERN_VIEW_H__
#define __ROSE_PATTERN_VIEW_H__

class CRosePatternView : public wxWindow
{
	typedef enum {
		CHANGE_D = 0,
		CHANGE_N
	} CHANGE_K;
public:
	explicit CRosePatternView(wxWindow* _parent, const wxSize& _size);
	virtual ~CRosePatternView();
	
	void Update();

protected:
	void Render(wxDC* pDC);
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);

private:
	wxRect m_viewRect;
	wxBitmap* m_pDoubleBuffer = nullptr;
	wxSize m_szChanged;

	bool m_bResize = false;
	int m_iXCenter;
	int m_iYCenter;

	float m_k = 0.0f;
	float m_d = 0.0f;
	float m_n = 0.0f;
	wxTimer m_timer;

	CHANGE_K m_enumK;
private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnMousetLBottonDown(wxMouseEvent& event);
	void OnMouseRButtonDown(wxMouseEvent& event);

	void OnTimer(wxTimerEvent& event);
	wxDECLARE_EVENT_TABLE();
};
#endif
