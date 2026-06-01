#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> indegree;
vector<int > T;

// 인접 리스트 2차원 그래프
vector<vector<int>> graph;

vector<int> dp;

void topology_sort()
{
	queue<int> q;

	for (int i = 1; i < N + 1; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (i : graph[now])	// now 작업과 연결된 i작업의 진입차수 1 빼기
		{
			indegree[i]--;
			dp[i] = max(dp[i], dp[now] + T[i]);	// now 작업 종료 후에 i작업 시간 더한 것 중에서 최대값

			if (indegree[i] == 0)
				q.push(i);
		}
	}
}

int main(void)
{
	// 작업 개수 입력
	cin >> N;

	graph.resize(N + 1);
	indegree.assign(N + 1, 0);	// 진입 차수 0으로 초기화
	T.assign(N + 1, 0);

	// dp[i]: i번 작업까지의 최소 수행 시간
	dp.assign(N + 1, 0);

	for (int i = 1; i < N + 1; ++i)
	{

	}
		cout 
}