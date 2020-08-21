#ifndef __LORENZ_VIEW_H__
#define __LORENZ_VIEW_H__

class CLorenzView : public wxWindow
{
	typedef struct _LORENZPOS {
		float x;
		float y;
		float z;
	} LORENZPOS;
public:
	explicit CLorenzView(wxWindow* _parent, const wxSize& _size);
	virtual ~CLorenzView();
	
	void Update();

protected:
	void Render(wxDC* pDC);
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);

private:
	wxRect m_viewRect;
	wxBitmap* m_pDoubleBuffer = nullptr;
	wxSize m_szChanged;

	bool m_bResize = false;
	
	wxTimer m_timer;
	wxVector<LORENZPOS *> m_vecLorenzPos;
	int m_iLorenzCount;

	int m_iXCenter = 0;
	int m_iYCenter = 0;

	float a = 10.0f;
	float b = 28.0f;
	float c = 8.0f / 3.0f;

	float xPos = 0.1f;
	float yPos = 0.0f;
	float zPos = 0.0f;
	float t = 0.1f;
private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnTimer(wxTimerEvent& event);

	wxDECLARE_EVENT_TABLE();
};
#endif
