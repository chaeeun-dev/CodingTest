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
	int time = 0;

	// 방문 처리 변수 초기화 (0 <= N <= 100000)
	vector<bool> visited(100000, false);

	// 방문 처리 + 큐에 삽입
	visited[x] = true;
	queue<pair<int, int>> q;	// position, tIme
	q.push({ x, time });

	while (!q.empty())	// 큐가 빌 때까지
	{
		int curPos = q.front().first;
		int curTime = q.front().second;
		q.pop();

		// 목적지에 도착했다면 리턴
		if (curPos == y)
		{
			return curTime;
		}

		// 세 가지 방향
		for (int i = 0; i < 3; ++i)
		{
			int n_pos;

			if (i == 2)
			{
				n_pos = curPos * d[i];
			}
			else
			{
				n_pos = curPos + d[i];
			}

			if (n_pos >= 0 && n_pos <= 100000)		// 범위 내에 있음
			{
				if (!visited[n_pos])	// 방문하지 않았다면
				{
					visited[n_pos] = true;	// 방문 처리
					q.push({ n_pos, curTime + 1 });	// 큐에 추가
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