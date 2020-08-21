#ifndef __MAZE_CELL_H__
#define __MAZE_CELL_H__

class CCell
{
public:
	CCell(int row, int col, int w);
	~CCell();

public:
	void show(wxDC* pDC);
	CCell* checkNeighbors(int cols, int rows, const wxVector<CCell *>& grid);
	void highLight(wxDC* pDC);
private:
	int getIndex(int i, int j, int cols, int rows);

public:
	bool m_bVisited = false;
	bool Walls[4] = { true, true, true, true };
	
	int m_i;
	int m_j;
	int m_w;	
	
	//wxVector<CCell*> m_vecNeighbor;
};
#endif