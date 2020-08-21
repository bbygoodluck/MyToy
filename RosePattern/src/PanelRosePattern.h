#ifndef __PANEL_ROSE_PATTERN_H__
#define __PANEL_ROSE_PATTERN_H__

class CRosePatternView;
class CPanelRosePattern : public wxPanel
{
public:
	explicit CPanelRosePattern(wxWindow* _parent);
	virtual ~CPanelRosePattern();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CRosePatternView> m_pRosePatternView;
};


#endif