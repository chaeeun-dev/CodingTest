#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 신장 트리
// 모든 노드를 다 포함하면서 사이클이 존재하지 않음
// 간선의 개수 = 노드의 개수 - 1

// 최소 신장 트리
// ...

// [크루스칼 알고리즘]
// 간선의 비용을 기준으로 오름차순 정렬
// 비용이 작은 것부터 확인하며 사이클이 발생하는지 확인
// (루트 노드가 같지 않으면 사이클이 없는 것, 유니온 - 부모를 같게 만듦)
// 성능: 간선의 개수가 E개이면 O(ElogE) 




// 노드 개수, 간선 개수
// 간선의 개수가 노드 개수 - 1이면 트리임!
int v, e;

vector<int> parent;
vector<pair<int, pair<int, int>>> edges;
int result = 0;

int find_parent(int x)
{
	if (x == parent[x])
		return x;
	return find_parent(parent[x]);
}

void union_parnet(int a, int b)
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
	cin >> v >> e;

	// 자기 자신을 부모로 초기화
	parent.assign(v, 0);
	for (int i = 1; i < v + 1; ++i)
	{
		parent[i] = i;
	}

	// 모든 간선에 대한 정보를 입력 받음
	for (int i = 0; i < e; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		edges.push_back({ cost, {a,b} });
	}
	
	// 간선을 비용순으로 정렬
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); ++i)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		// 사이클이 발생하지 않는 경우에만 집합하여 포함
		if (find_parent(a) != find_parent(b))
		{
			union_parnet(a, b);
			result += cost;
		}
	}
}