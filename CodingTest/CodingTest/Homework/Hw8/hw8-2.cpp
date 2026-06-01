#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// V: 노드의 개수, E: 간선의 개수
int V, E;

// 진입 차수 저장
vector<int> indegree;

// 인접 리스트 2차원 그래프
vector<vector<int>> graph;

void topologySort()
{
    vector<int> result(V + 1, 1);
    queue<int> q;

    // 진입차수 0 -> 1학기 가능
    for (int i = 1; i <= V; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : graph[now])
        {
            indegree[next]--;

            // next 과목은 now 다음 학기에 가능
            result[next] = max(result[next], result[now] + 1);

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= V; ++i)
        cout << result[i] << ' ';
}

int main(void)
{
	cin >> V >> E;

	graph.resize(V + 1);
	indegree.assign(V + 1, 0);

	for (int i = 0; i < E; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		indegree[b]++;
	}

	topologySort();

	return 0;
}