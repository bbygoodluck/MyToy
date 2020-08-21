#ifndef __Fireworks_VIEW_H__
#define __Fireworks_VIEW_H__

class CFireworksView : public wxWindow
{
public:
	explicit CFireworksView(wxWindow* _parent, const wxSize& _size);
	virtual ~CFireworksView();
	
	void Update();

protected:
	void Render(wxDC* pDC);	
	void UpdateView(wxWindow* pWindow, const wxRect& rect, bool bUpdate = false);

private:
	wxRect m_viewRect;
	wxBitmap* m_pDoubleBuffer = nullptr;
	wxSize m_szChanged;
	
	bool m_bResize = false;
	
	wxTimer m_timer;
	int m_iXCenter;
	int m_iYCenter;

	struct sParticle {
		float x = 0.0f;
		float y = 0.0f;
		float vx = 0.0f;
		float vy = 0.0f;
		float fuse = 0.0f;
		float lifetime = 0.0f;
		wxColour col;
	};

	class cFireworks : public sParticle
	{
	public:
		cFireworks(float xPos, float yPos, int size)
		{
			x = xPos;
			y = yPos;
			vx = RandomFloat(100.0f) - 50.0f;
			vy = -100.0f;
			fuse = RandomFloat(6.0f) + 5.0f;
			starCount = size;
		}

		void Update(float fElaspsedTime)
		{	//불꽃이 생성된 후 떨어지는 속도
			float fGravity = 25.0f;
			//터진후 벌어지는 X의크기
			float fDrag = 0.999f;
			//터진 후 번지는 y의크기
			float fExplodedGravity = 45.0f;

			lifetime += fElaspsedTime;
			if (lifetime <= fuse)
			{
				//were launching
				vx *= fDrag;
				x += vx * fElaspsedTime;
				y += (vy + fGravity) * fElaspsedTime;
			}
			else
			{
				if (!bHasExploded)
				{
					bHasExploded = true;
					//Explode
					wxColour col = wxColour(rand() % 100 + 155, rand() % 240 + 15, rand() % 240 + 15);

					for (int i = 0; i < starCount; i++)
					{
						sParticle s;
						s.x = x;
						s.y = y;
						s.col = col;

						float angle = RandomFloat((float)(2.0f * M_PI));
						float power = RandomFloat(50.0f);

						s.fuse = RandomFloat(3.0f) + 1.0f;
						s.vx = cosf(angle) * power;
						s.vy = sinf(angle) * power;

						vecStarts.push_back(s);
					}
				}
				else
				{
					for (auto &s : vecStarts)
					{
						s.lifetime += fElaspsedTime;

						s.vx *= fDrag;
						s.x += s.vx * fElaspsedTime;
						float fDisp = (s.vy + fExplodedGravity) * fElaspsedTime;
						s.y += fDisp;
					}
				}
			}
		}

		float RandomFloat(float fMax)
		{
			return ((float)rand() / (float)RAND_MAX) * fMax;
		}

		void DrawSelf(wxDC* pDC)
		{
			wxPen pen(wxColour(255, 255, 255));
			wxBrush brush(wxColour(255, 255, 255));
			pDC->SetPen(pen);
			pDC->SetBrush(brush);
			if(lifetime <= fuse)
				pDC->DrawCircle(x, y, 4);
			else
			{
				bExpired = true;
				for (auto &s : vecStarts)
				{
					if (s.lifetime <= s.fuse)
					{
						bExpired = false; 
						wxPen penParticle(wxColour(s.col));
					//	wxBrush brushParticle(s.col);
						pDC->SetPen(penParticle);
					//	pDC->SetBrush(brushParticle);
					//	pDC->DrawCircle(s.x, s.y, 1);
						pDC->DrawPoint(s.x, s.y);
					}
				}
			}
		}

		std::vector<sParticle> vecStarts;
		int starCount = 0;

		bool bHasExploded = false;
		bool bExpired = false;
	};

	std::list<cFireworks> listFireworks;
	float fDelay = 1.0f;
	float fElaspsedTime = 0.1f;

private:
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
	void OnErase(wxEraseEvent& event);
	void OnTimer(wxTimerEvent& event);

	wxDECLARE_EVENT_TABLE();
};
#endif
