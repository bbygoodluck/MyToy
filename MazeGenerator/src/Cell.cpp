#include "./global/global.h"
#include "Cell.h"

CCell::CCell(int row, int col, int w)
	: m_i(row)
	, m_j(col)
	, m_w(w)
{

}

CCell::~CCell()
{

}

void CCell::show(wxDC* pDC)
{
	int x = m_i * m_w;
	int y = m_j * m_w;

	if (m_bVisited)
	{
		wxPen pen(wxColour(56, 92,158), 1, wxPENSTYLE_SOLID);
		wxBrush brush(wxColour(56, 92, 158));
		
		pDC->SetPen(pen);
		pDC->SetBrush(brush);
		
		pDC->DrawRectangle(x, y, m_w, m_w);
	}

	wxPen pen(wxColour(255, 255, 255), 1, wxPENSTYLE_SOLID);
	pDC->SetPen(pen);

	if (Walls[0])
		pDC->DrawLine(x, y, x + m_w, y);

	if (Walls[1])
		pDC->DrawLine(x + m_w, y, x + m_w, y + m_w);

	if (Walls[2])
		pDC->DrawLine(x + m_w, y + m_w, x, y + m_w);

	if (Walls[3])
		pDC->DrawLine(x, y + m_w, x, y);
}

void CCell::highLight(wxDC* pDC)
{
	int x = m_i * m_w;
	int y = m_j * m_w;

	wxPen pen(wxColour(0, 255, 0), 1, wxPENSTYLE_SOLID);
	wxBrush brush(wxColour(0, 255, 0));

	pDC->SetPen(pen);
	pDC->SetBrush(brush);

	pDC->DrawRectangle(x, y, m_w, m_w);
}

int CCell::getIndex(int i, int j, int cols, int rows)
{
	if (i < 0 || j < 0 || i > rows - 1 || j > cols - 1)
		return -1;

	return i + j * cols;
}

CCell* CCell::checkNeighbors(int cols, int rows, const wxVector<CCell*>& grid)
{
	wxVector<CCell*> vecNeighbor;
	int iTop = getIndex(m_i, m_j - 1, cols, rows);
	int iRight = getIndex(m_i + 1, m_j, cols, rows);
	int iBottom = getIndex(m_i, m_j + 1, cols, rows);
	int iLeft = getIndex(m_i - 1, m_j, cols, rows);

	CCell* pTop = nullptr;
	CCell* pRight = nullptr;
	CCell* pBottom = nullptr;
	CCell* pLeft = nullptr;

	if (iTop > -1)
		pTop = grid[iTop];

	if (iRight > -1)
		pRight = grid[iRight];

	if (iBottom > -1)
		pBottom = grid[iBottom];

	if (iLeft > -1)
		pLeft = grid[iLeft];

	if (pTop && !pTop->m_bVisited)
		vecNeighbor.push_back(pTop);

	if (pRight && !pRight->m_bVisited)
		vecNeighbor.push_back(pRight);

	if (pBottom && !pBottom->m_bVisited)
		vecNeighbor.push_back(pBottom);

	if (pLeft && !pLeft->m_bVisited)
		vecNeighbor.push_back(pLeft);

	if (vecNeighbor.size() > 0)
	{
		int r = rand() % vecNeighbor.size();
		return vecNeighbor[r];
	}
	else
		return nullptr;
}