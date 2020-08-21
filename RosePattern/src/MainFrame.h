#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__

class CPanelRosePattern;
class CMainFrame : public wxFrame
{
public:
	explicit CMainFrame(const wxString& strTitle);
	virtual ~CMainFrame();

#ifdef __WXMSW__
	virtual WXLRESULT MSWDefWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);
#endif

protected:
	std::unique_ptr<CPanelRosePattern> m_panelRosePattern;
private:
	void OnClose(wxCloseEvent& event);
	wxDECLARE_EVENT_TABLE();
};

#endif