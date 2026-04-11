// 중요한 교차로(TUKorea, DFS / BFS완전탐색)
// http://210.93.60.51/problem/0045
// https://www.youtube.com/watch?v=_qNcHcGlp2s&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=7
// https://www.youtube.com/watch?v=tjxW8sJf1Rg&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=28

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int N, M;
vector<vector<bool>> graph;
vector<int> answer;	// 중요한 교차로 목록
vector<bool> visited;

void DFS_Rec(int start, int skip)
{
	visited[start] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (i == skip)
			continue;

		if (!visited[i] && graph[start][i])
		{
			DFS_Rec(i, skip);
		}
	}
}

void DFS_Stack(int start, int skip)
{
	stack<int> s;
	s.push(start);
	visited[start] = true;

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		for (int i = 1; i <= N; ++i)
		{
			if (i != skip && !visited[i] && graph[cur][i])
			{
				visited[i] = true;
				s.push(i);
			}
		}
	}
}

void BFS(int start, int skip)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; ++i)
		{
			if (i != skip && !visited[i] && graph[cur][i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void)
{
	// N: 교차로 수, M: 도로 수
	cin >> N >> M;
	graph.assign(N + 1, vector<bool>(N + 1, false));

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = true;
		graph[b][a] = true;
	}

	// 모든 교차로가 중요한지 검사
	for (int i = 1; i <= N; ++i)
	{
		// STEP1 - 모든 교차로 노드를 unvisited로 설정
		visited.assign(N + 1, false);

		// STEP2 - 임의의 교차로에서 DFS로 완전 순회하면 i를 제외한 모든 교차로를 방문해야 함
		int start = (i == 1 ? 2 : 1);	// i가 아닌 아무 교차로
		DFS_Rec(start, i);	// DFS 완전 탐색 수행

		// STEP3 - i를 제외하고 방문 못한 노드가 있으면 중요한 교차로임
		for (int j = 1; j <= N; ++j)
		{
			if (i != j && !visited[j])
			{
				answer.push_back(i);
				break;
			}
		}
	}

	// 정답 출력
	cout << answer.size() << endl;

	if (answer.size() > 1)
		sort(answer.begin(), answer.end());

	for (size_t i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
}