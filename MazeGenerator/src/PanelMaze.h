#ifndef __PANEL_MAZE_H__
#define __PANEL_MAZE_H__

class CMazeView;
class CPanelMaze : public wxPanel
{
public:
	explicit CPanelMaze(wxWindow* _parent);
	virtual ~CPanelMaze();

	void Update();
private:
	void Init();

private:
	wxBoxSizer* m_Mainsizer = nullptr;
	std::unique_ptr<CMazeView> m_pMazeView;
};


#endif