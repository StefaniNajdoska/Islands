/* ===== C/C++ ====== */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
/*
The goal is to count and print the number of islands in the given map.
The map consists of a 2 dimensional matrix of 1’s and 0’s,
with 1’s representing land, and 0’s representing sea.
Continues list of “1” is considered as one island.
The correct answer in the example bellow is 4 islands.
*/

/*
Please make the code clean and neat.
take extra caution for :
memory leaks
problematic inputs
*/

/*
The code should be short and simple,
if you see many logical loops, ifs and conditions you are probably going in the wrong direction

Try to break the problem into several sub-problems
Feel free to use google but not your friends :)
*/

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
