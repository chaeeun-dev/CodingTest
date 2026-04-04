// 숨바꼭질(백준, BFS최단거리)
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int d[] = { -1, 1, 2 };

int BFS(int x, int y)
{
	// 거리 0으로 초기화
	int distance = 0;

	// 방문 처리 변수 초기화 (0 <= N <= 100000)
	vector<bool> visited(100000, false);

	// 방문 처리 + 큐에 삽입
	visited[x] = true;
	queue<pair<int, int>> q;
	q.push({ x, distance });

	while (!q.empty())	// 큐가 빌 때까지
	{
		int cur_pos = q.front().first;
		int cur_dis = q.front().second;
		q.pop();

		if (cur_pos == y)
		{
			return cur_dis;
		}

		for (int i = 0; i < 3; ++i)
		{
			int n_pos;

			if (i == 2)
			{
				n_pos = cur_pos * d[i];
			}
			else
			{
				n_pos = cur_pos + d[i];
			}

			if (n_pos >= 0 && n_pos <= 100000)
			{
				if (!visited[n_pos])
				{
					visited[n_pos] = true;
					q.push({ n_pos, cur_dis + 1 });
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << endl;
}