#ifndef __PANEL_LORENZ_H__
#define __PANEL_LORENZ_H__

class CLorenzView;
class CPanelLorenz : public wxPanel
{
public:
	explicit CPanelLorenz(wxWindow* _parent);
	virtual ~CPanelLorenz();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CLorenzView> m_pLorenzView;
};


#endif