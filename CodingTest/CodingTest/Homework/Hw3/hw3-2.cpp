// 숨바꼭질(백준, BFS최단거리)
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int N)
{
	// 거리 0으로 초기화
	int distance = 0;

	// 방문 처리 변수 초기화 (0 <= N <= 100000)
	vector<bool> visited(100000, false);

	// 방문 처리 + 큐에 삽입
	visited[N] = true;
	queue<int, int> q;
	q.push((N, distance));

	while (!q.empty())	// 큐가 빌 때까지
	{

	}
	return 0;
}

int main(void)
{
	int N, K;
	cin >> N >> K;

	BFS(N);
}