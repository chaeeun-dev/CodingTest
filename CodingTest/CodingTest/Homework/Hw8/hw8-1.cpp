// 도시분할계획(TUKorea, 백준, 최소신장트리)
// http://210.93.60.51/problem/0189

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N: 집의 개수(노드), M: 길의 개수(간선)
int N, M;

vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int find_parent(int x)
{
	if (x == parent[x])
		return x;
	return find_parent(parent[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	cin >> N >> M;

	// 자기 자신을 부모로 초기화
	parent.assign(N + 1, 0);
	for (int i = 0; i < N + 1; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		// A와 B를 연결하는 유지비 C
		int A, B, C;
		cin >> A >> B >> C;

		edges.push_back({ C, { A, B } });
	}
	
	// 비용을 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end());

	int result = 0;		// 최소 신장트리 비용 합계
	int max_cost = 0;	// 최소 신장트리 간선 비용 중에서 가장 큰 값

	// 비용이 작은 간선을 하나씩 꺼내서
	for (int i = 0; i < edges.size(); ++i)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		// 사이클이 발생하지 않는 경우에만 집합하여 포함
		if (find_parent(a) != find_parent(b))
		{
			union_parent(a, b);
			result += cost;
			max_cost = max(max_cost, cost);
		}
	}

	cout << result - max_cost;

	return 0;
}