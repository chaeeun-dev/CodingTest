// 양방향이 아닌 단방향으로 연결 되어야 하고, 사이클이 없어야 함.
// 예) 선수 과목

// 진입차수(Indegree): 특정 노드로 들어오는 간선의 개수
// 진출차수(Outdegree): 특정 노드에서 나가는 간선의 개수
// 진입차수 정보를 활용해서 위상정렬 가능

// 위상정렬 알고리즘 - 큐를 이용함
// 1. 진입차수가 0인 모든 노드를 큐에 넣음(없으면 사이클이 있는 것이라 어차피 안 됨)
// 2. 큐에서 원소를 꺼내고 연결된 노드의 진입 차수를 줄이고 0이 되면 큐에 넣음
// 큐에 집어 넣는 순서가 위상정렬의 순서임, 여러 가지 답이 존재할 수 있음

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
	vector<int> result;	// 위상정렬 결과 리스트
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 넣음
	for (int i = 1; i < V + 1; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())	// 큐가 빌 때까지
	{
		// 큐에서 원소 꺼내기
		int now = q.front();
		q.pop();

		// 결과 저장
		result.push_back(now);

		// 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
		for (int next : graph[now])
		{
			indegree[next]--;

			// t새롭게 진입 차수가 0이 되면 큐에 삽입
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	// 결과 출력
	for (int node : result)
		cout << node << ' ';
}

int main(void)
{
	cin >> V >> E;

	graph.resize(V + 1);
	indegree.assign(V + 1, 0);

	for (int i = 0; i < V + 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		indegree[b]++;
	}

	topologySort();

	return 0;
}