#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<bool> visited;
vector<vector<bool>> graph;
vector<int> result;

void BFS(int start, int skip)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		// 모든 교차로에 대해 검사
		for (int i = 1; i <= N; ++i)
		{
			if (i != skip && graph[cur][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	
	graph.assign(N + 1, vector<bool>(N + 1, false));

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;

		graph[a][b] = true;
		graph[b][a] = true;
	}

	// 모든 교차로에 대해 중요한 교차로인지 검사
	for (int i = 1; i <= N; ++i)
	{
		visited.assign(N + 1, false);

		// i를 제외한 임의의 점
		int start = (i == 1) ? 2 : 1;
		BFS(start, i);

		for (int j = 1; j <= N; ++j)
		{
			if (i != j && !visited[j])
			{
				result.push_back(j);
				break;
			}
		}
	}

	// 출력
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int v : result)
	{
		cout << v << endl;
	}

	return 0;
}