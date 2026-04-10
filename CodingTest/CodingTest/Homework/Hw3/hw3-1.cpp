// DFS와 BFS(백준)
// https://www.acmicpc.net/problem/1260
// https://www.youtube.com/watch?v=UQyUuiDRB1o&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=5
// https://www.youtube.com/watch?v=uQ5oq802r9k&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=26

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<bool>> graph;

vector<bool> visitedDFSRec;
vector<bool> visitedDFS;
vector<bool> visitedBFS;

void DFS_Rec(int start)
{
	if (!visitedDFSRec[start])
	{
		visitedDFSRec[start] = true;
		cout << start << ' ';
	}

	for (int i = 0; i <= N; ++i)
	{
		if (!visitedDFSRec[i] && graph[start][i])
		{
			visitedDFSRec[i] = true;
			cout << i << ' ';
			DFS_Rec(i);
		}
	}
}

void DFS_Stack(int start)
{
	stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		if (!visitedDFS[cur])	// 방문하지 않았으면
		{
			cout << cur << ' ';
			visitedDFS[cur] = true;	// 방문처리
		}
		for (int i = N; i >= 1; --i)		// 거꾸로
		{
			if (!visitedDFS[i] && graph[cur][i])		// i번 방문 안 함 & v와 연결됐다면
			{
				s.push(i);
			}
		}
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (!visitedBFS[cur])
		{
			cout << cur << ' ';
			visitedBFS[cur] = true;
		}

		for (int i = 0; i <= N; ++i)
		{
			if (!visitedBFS[i] && graph[cur][i])
			{
				q.push(i);
			}
		}
	}
}

int main(void)
{
	// N: 정점 개수, M: 간선 개수, V: 탐색 시작 정점 번호
	cin >> N >> M >> V;
	
	graph.assign(N + 1, vector<bool>(N + 1, false));
	visitedDFSRec.assign(N + 1, false);
	visitedBFS.assign(N + 1, false);
	visitedDFS.assign(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = true;
		graph[b][a] = true;
	}

	DFS_Rec(V);
	cout << endl;
	DFS_Stack(V);
	cout << endl;
	BFS(V);
}
