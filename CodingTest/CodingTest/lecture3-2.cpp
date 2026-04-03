// 미로 탈출
// 0: 괴물
// 1: 갈 수 있음
// 아이디어) 값에 거리를 쓰기!

//5 6
//101010
//111111
//000001
//111111
//111111

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int N, M;
using namespace std;

vector<vector<int>> v;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int BFS(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({r, c});

	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (v[nr][nc] == 1)
				{
					v[nr][nc] = v[cur_r][cur_c] + 1;	// 거리 기록
					q.push({ nr, nc });
				}
			}
		}
	}

	return v[N - 1][M - 1];
}

int main(void)
{

	cin >> N >> M;

	v.assign(N, vector<int>(M));
	
	// 입력
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}

	// 탐색
	cout << BFS(0, 0) << endl;
}