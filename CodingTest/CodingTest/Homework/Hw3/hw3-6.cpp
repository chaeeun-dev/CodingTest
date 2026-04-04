// 섬의 개수(백준, DFS / BFS 완전탐색)
// https://www.acmicpc.net/problem/4963

// 주의) vector 매개변수로 넘기지 말고 전역변수 사용하기

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 상 하 좌 우 좌상 우상 좌하 우하
int dr[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int R, C;

vector<vector<int>> v;

// 1: 땅
// 0: 바다

void DFS_Stack(int r, int c)
{
	stack<pair<int, int>> s;
	s.push({ r, c });
	v[r][c] = 0;

	while (!s.empty())
	{
		int cur_r = s.top().first;
		int cur_c = s.top().second;
		s.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			if (nr >= 0 && nr < R && nc >= 0 && nc < C)
			{
				if (v[nr][nc] == 1)
				{
					v[nr][nc] = 0;
					s.push({ nr, nc });
				}
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> C >> R;

		if (C == 0 && R == 0)
			break;

		v.assign(R, vector<int>(C));

		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cin >> v[i][j];
			}
		}

		int count = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (v[i][j] == 1)
				{
					count++;
					DFS_Stack(i, j);
				}
			}
		}

		cout << count << endl;
	}
}