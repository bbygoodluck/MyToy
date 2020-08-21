#ifndef __PANEL_FIREWORKS_H__
#define __PANEL_FIREWORKS_H__

class CFireworksView;
class CPanelFireworks : public wxPanel
{
public:
	explicit CPanelFireworks(wxWindow* _parent);
	virtual ~CPanelFireworks();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CFireworksView> m_pFireworksView;
};


#endif