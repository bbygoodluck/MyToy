#ifndef __PANEL_SNOW_BALL_H__
#define __PANEL_SNOW_BALL_H__

class CSnowBallView;
class CPanelSnowBall : public wxPanel
{
public:
	explicit CPanelSnowBall(wxWindow* _parent);
	virtual ~CPanelSnowBall();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CSnowBallView> m_pSnowBallView;
};


#endif