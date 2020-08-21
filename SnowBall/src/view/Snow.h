#ifndef __SNOW_H__
#define __SNOW_H__

class CSnow
{
public:
	CSnow(const wxRect& rc);
	~CSnow();

public:
	void Update();
	void Reset(const wxRect& rc);

private:
	void Init(bool bReset = false);

public:
	float _xPos;
	float _yPos;
	int _iType;
	int _FontSize = 10;
	int _Angle = 0;
	float _fWidth = 0.0;
	float _fHeight = 0.0;
	float _fXSpeed = 0.0;
	float _fYSpeed = 0.0;

	wxColour _color;
	wxString _strFont;
	wxFont _font;

	HFONT hFont;
private:
	wxRect m_rect;
};
#endif