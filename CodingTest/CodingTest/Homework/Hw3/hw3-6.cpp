// 섬의 개수(백준, DFS / BFS 완전탐색)
// https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	while (1)
	{
		int row = 0, col = 0;
		cin >> row >> col;

		if (row == 0 && col == 0)
			break;

		// row * col 크기의 2차원 벡터 생성
		vector<vector<int>> input(row, vector<int>(col));

		// 벡터에 숫자 넣기
		for (int i = 0; i < row; ++i)
		{		
			string str;
			cin >> str;
			
			for (int j = 0; j < col; ++j)
			{
				input[i][j] = str[j];
			}
		}
	}
}