#ifndef __PANEL_WATCH_H__
#define __PANEL_WATCH_H__

class CWatchView;
class CPanelWatch : public wxPanel
{
public:
	explicit CPanelWatch(wxWindow* _parent);
	virtual ~CPanelWatch();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CWatchView> m_pWatchView;
};


#endif