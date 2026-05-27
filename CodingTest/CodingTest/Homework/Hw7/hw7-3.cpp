// 소가길을건너간이유4 (TUKorea,백준,우선순위큐,최소힙,그리디)
// http://210.93.60.51/problem/0188

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    // C: 닭 마리수, N: 소 마리수
    int C, N;
    cin >> C >> N;

    // 닭 시간
    // chicken = [7, 8, 6, 2, 9]
    vector<int> chicken(C);
    for (int i = 0; i < C; ++i)
    {
        cin >> chicken[i];
    }

    // 소 시간 [시작 시간, 종료 시간]
    // cow = [[2,5], [4,9], [2,5], [8,13]]
    vector<pair<int, int>> cow(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cow[i].first >> cow[i].second;
    }

    // 닭 시간 오름차순 정렬
    sort(chicken.begin(), chicken.end());

    // 소 시작 시간 기준 정렬
    sort(cow.begin(), cow.end());

    // 종료 시간이 가장 작은 소를 먼저 꺼내기 위한 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    int idx = 0;
    int result = 0;

    // 각 닭에 대해
    for (int t : chicken)
    {
        // 현재 닭 시간 이전에 시작 가능한 소들 추가
        while (idx < N && cow[idx].first <= t)
        {
            pq.push(cow[idx].second);
            idx++;
        }

        // 이미 종료된 소 제거
        while (!pq.empty() && pq.top() < t)
        {
            pq.pop();
        }

        // 현재 닭이 도와줄 수 있는 소 선택
        if (!pq.empty())
        {
            pq.pop();
            result++;
        }
    }

    cout << result;

    return 0;
}