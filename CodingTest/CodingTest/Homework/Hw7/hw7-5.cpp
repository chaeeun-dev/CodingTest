// 합승 택시(Programmers, Floyd Warshall) 
// https://school.programmers.co.kr/learn/courses/30/lessons/72413

// 합승 택시(Programmers, Floyd Warshall, 우선순위큐) 
// https://school.programmers.co.kr/learn/courses/30/lessons/72413
// https://www.youtube.com/watch?v=ejkvFLxDngQ&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=14

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start, int n)
{
    vector<int> distance(n + 1, INF);
    distance[start] = 0;

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

        if (distance[now] < dist)
            continue;

        for (auto next : graph[now])
        {
            int nextNode = next.first;
            int nextCost = next.second;

            int cost = dist + nextCost;

            if (cost < distance[nextNode])
            {
                distance[nextNode] = cost;
                pq.push({ cost, nextNode });
            }
        }
    }

    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    graph.clear();
    graph.resize(n + 1);

    // 그래프 저장
    for (auto fare : fares)
    {
        int u = fare[0];
        int v = fare[1];
        int w = fare[2];

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    vector<int> distS = dijkstra(s, n);
    vector<int> distA = dijkstra(a, n);
    vector<int> distB = dijkstra(b, n);

    int answer = INF;

    for (int k = 1; k <= n; ++k)
    {
        // 갈 수 없는 경우 제외
        if (distS[k] == INF ||
            distA[k] == INF ||
            distB[k] == INF)
            continue;

        answer = min(answer,
            distS[k] + distA[k] + distB[k]);
    }

    return answer;
}

int main(void)
{
    solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} });
}