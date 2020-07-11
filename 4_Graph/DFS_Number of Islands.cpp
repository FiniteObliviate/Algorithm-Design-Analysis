#include "util.hpp"
#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<char>>& grid, int i, int j)
{
	grid[i][j] = '2'; //标记遍历过的格子，以避免查找重复或进入死循环(若不标记，在第一个田字形岛屿就会兜圈子进入死循环)
	if (i - 1 >= 0 && grid[i - 1][j] == '1')  //向左查找
		DFS(grid, i - 1, j);
	if (j - 1 >= 0 && grid[i][j - 1] == '1') //向上
		DFS(grid, i, j - 1);
	if (i + 1 < grid.size() && grid[i + 1][j] == '1')  //向右
		DFS(grid, i + 1, j);
	if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')  //向下（总的来说是逆时针查找）
		DFS(grid, i, j + 1);
	//必须把“i - 1 >= 0”放在前面，否则可能会访问grid[-1][j]而出界报错
}

int numIslands(vector<vector<char>>& grid)
{
	int count = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
			if (grid[i][j] == '1')
			{
				DFS(grid, i, j);
				count++;
			}
	}
	return count;
}

int main()
{

	vector<vector<char>> grid =
	{
		{ '1', '1', '0', '0', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '1', '1' }
	};

	cout << numIslands(grid) << endl;

	// 按任意键继续
	Pause();
	return 0;
}

