#include "../global/global.h"
#include "Snow.h"

const char  *szFonts[] = { "Arial", "Arial Black", "Times new roman" };
CSnow::CSnow(const wxRect& rc)
	: m_rect(rc)
{
	Init();

}

CSnow::~CSnow()
{

}

void CSnow::Init(bool bReset)
{
	_xPos = rand() % m_rect.GetWidth();
	_yPos = rand() % m_rect.GetHeight();
	_strFont = szFonts[rand() % 3];
	_FontSize = 20 + rand() % 42;
	if(bReset)
		_yPos = -5.0f;
	
	_color = wxColour(rand() % 255, rand() % 255, rand() % 255);
	_fWidth = (float)(rand() % 20);
	if (_fWidth <= 8.0f)
		_fWidth = 8.0f;

	_iType = 1;// rand() % 2;
	_fHeight = _fWidth;
	_fYSpeed = (rand() % 3) + 0.5f;

	_Angle = rand() % 360 + 1;

	_font = wxFont(_FontSize, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _strFont);
}

void CSnow::Update()
{
	_xPos += _fXSpeed;
	_yPos += _fYSpeed;
	if (_yPos >= m_rect.GetHeight())
		Init(true);
}

void CSnow::Reset(const wxRect& rc)
{
	m_rect = rc;
	Init();
}