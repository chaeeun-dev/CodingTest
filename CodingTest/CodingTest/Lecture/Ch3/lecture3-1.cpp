// 음료수 얼려 먹기
// 0: 구멍
// 1: 막힌 곳

//4 5
//00110
//00011
//11111
//00000

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> v;

// 상 하 좌 우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void BFS(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r, c });
	v[r][c] = 1;	// 방문 처리

	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			// 범위 내 && 0 구멍이라면 -> 1로 막아버림
			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (v[nr][nc] == 0)
				{
					v[nr][nc] = 1;	// 방문 처리
					q.push({ nr, nc });	// 큐에 삽입
				}
			}
		}
	}
}

void DFS_rec(int r, int c)
{
	v[r][c] = 1;	// 방문 처리

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M)	// 범위 내
		{
			if (v[nr][nc] == 0)	// 구멍이라면
			{
				DFS_rec(nr, nc);	// 방문 처리는 재귀 호출될 때 됨
			}
		}
	}
}

void DFS_Stack(int r, int c)
{
	stack<pair<int, int>> s;
	s.push({ r, c });
	v[r][c] = 1;

	while (!s.empty())
	{
		int cur_r = s.top().first;
		int cur_c = s.top().second;
		s.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (v[nr][nc] == 0)
				{
					v[nr][nc] = 1;
					s.push({ nr, nc });
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	v.assign(N, vector<int>(M));	// assign 크기 할당
	
	// 입력
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; ++j)
		{
			v[i][j] = str[j] - '0';	// str을 int로 변환!!! 중요
		}
	}

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 0)
			{
				count++;
				DFS_Stack(i, j);
			}
		}
	}

	cout << count << endl;
	return 0;
}
