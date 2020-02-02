/* ===== C/C++ ====== */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int island[12][10] = {
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

class CIslandInterface {
public:
	CIslandInterface(){};
	virtual ~CIslandInterface(){};
	virtual int CalculateIslands() = 0;
	virtual void CopyMatrix(int* Xi_referenceMatrix) = 0;
};

///////////////////// Code here /////////////////////////
class CIslandMatrix : public CIslandInterface{
public:
	CIslandMatrix(int cols, int rows)
	{
		m_cols = cols;
		m_rows = rows;
		m_pIsland = new int[cols * rows];
		m_Visited = new bool[cols * rows];
	};

	~CIslandMatrix(){
		delete[] m_pIsland;
		delete[] m_Visited;
	}

	void findNeighbours(int index)
	{
		vector< int > neighbours;
		neighbours.push_back(index + 1);
		neighbours.push_back(index - 1);
		neighbours.push_back(index + m_cols);
		neighbours.push_back(index - m_cols);

		m_Visited[index] = true;
		for (int i = 0; i < neighbours.size(); i++)
		{
			if (neighbours[i] >= 0 && neighbours[i] < m_cols * m_rows && !m_Visited[neighbours[i]] && m_pIsland[neighbours[i]] == 1)
			{
				findNeighbours(neighbours[i]);
			}
		}
	};

	int CalculateIslands()
	{
		int m_Counter = 0;
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				int k = i * m_cols + j;
				if (m_pIsland[k] == 1 && !m_Visited[k])
				{
					findNeighbours(k);
					m_Counter++;
				}
			}
		}
		return m_Counter;
	};

	void CopyMatrix(int* Xi_referenceMatrix)
	{
		memcpy(m_pIsland, Xi_referenceMatrix, (sizeof(int)*m_cols*m_rows));
		memset(m_Visited, false, sizeof(m_rows * m_cols));
	};

private:
	int m_cols;
	int m_rows;
	int* m_pIsland = nullptr;
	bool* m_Visited = nullptr;
};

////////////////////////////////////////////////////////////

int main()
{
	CIslandMatrix mat(10, 12);
	int* isl = &island[0][0];
	mat.CopyMatrix(isl);
	cout << "Islands found : " << mat.CalculateIslands() << std::endl;

	return 0;
}
