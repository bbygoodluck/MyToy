#ifndef __MAZE_VIEW_H__
#define __MAZE_VIEW_H__

class CCell;
class CMazeView : public wxWindow
{
public:
	explicit CMazeView(wxWindow* _parent, const wxSize& _size);
	virtual ~CMazeView();
	
	void Update();

protected:
	void Render(wxDC* pDC);
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);

	void Clear();
	void removeWalls(CCell* pCurrent, CCell* pNext);

private:
	wxRect m_viewRect;
	wxBitmap* m_pDoubleBuffer;
	wxSize m_szChagned;

	bool m_bResize = false;
	wxVector<CCell* > m_cellGrid;
	int m_w;
	int m_cols;
	int m_rows;

	CCell* m_pCurrent;

	wxTimer m_timer;

	wxVector<CCell *> m_vecStack;
	int m_iStackIndex = 0;
private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnMousetLBottonDown(wxMouseEvent& event);
	void OnMouseRButtonDown(wxMouseEvent& event);
	wxDECLARE_EVENT_TABLE();
};
#endif
