#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

// 학생(마을) 수, 간선 수, 모이는 마을
int N, M, X;

// 다익스트라
vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
    // 거리 테이블
    vector<int> distance(N + 1, INF);
    distance[start] = 0;

    // {거리, 노드}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 이미 더 짧은 경로가 있으면 스킵
        if (distance[now] < dist)
            continue;

        // 인접 노드 탐색
        for (pair<int, int> next : graph[now])
        {
            int nextNode = next.first;
            int nextCost = next.second;

            int cost = dist + nextCost;

            // 더 짧은 경로 발견
            if (cost < distance[nextNode])
            {
                distance[nextNode] = cost;
                pq.push({ cost, nextNode });
            }
        }
    }

    return distance;
}

int main(void)
{
    cin >> N >> M >> X;

    // 정방향 그래프
    vector<vector<pair<int, int>>> graph(N + 1);

    // 역방향 그래프
    vector<vector<pair<int, int>>> rev_graph(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 정방향: a -> b
        graph[a].push_back({ b, c });

        // 역방향: b -> a
        rev_graph[b].push_back({ a, c });
    }

    // X -> 모든 마을
    vector<int> dist_from_X = dijkstra(X, graph);

    // 모든 마을 -> X
    // 역방향 그래프에서 X 출발
    vector<int> dist_to_X = dijkstra(X, rev_graph);

    int max_dist = 0;

    for (int i = 1; i <= N; ++i)
    {
        max_dist = max(max_dist,
            dist_from_X[i] + dist_to_X[i]);
    }

    cout << max_dist;

    return 0;
}