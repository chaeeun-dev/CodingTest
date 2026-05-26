// 택배 배송 (TUKorea, 백준, 다익스트라)
// http://210.93.60.51/problem/0186

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, M;

// 거리 배열
vector<int> d;

// 인접 리스트
// graph[a] = { {b, cost}, ... }
vector<vector<pair<int, int>>> graph;

void dijkstra(int start)
{
    // {거리, 노드}
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 이미 더 짧은 경로가 있다면 무시
        if (d[now] < dist)
            continue;

        // 인접 노드 탐색
        for (int i = 0; i < graph[now].size(); ++i)
        {
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;

            // 더 짧은 경로 발견
            if (cost < d[next])
            {
                d[next] = cost;
                pq.push({ cost, next });
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    d.assign(N + 1, INF);
    graph.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 양방향 그래프
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    dijkstra(1);

    cout << d[N];

    return 0;
}