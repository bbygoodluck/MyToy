#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__

class CPanelFireworks;
class CMainFrame : public wxFrame
{
public:
	explicit CMainFrame(const wxString& strTitle);
	virtual ~CMainFrame();

#ifdef __WXMSW__
	virtual WXLRESULT MSWDefWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);
#endif

protected:
	//wxPanel* m_panelSnowBall;
	std::unique_ptr<CPanelFireworks> m_panelFireworks;
private:
	void OnClose(wxCloseEvent& event);
	wxDECLARE_EVENT_TABLE();
};

#endif