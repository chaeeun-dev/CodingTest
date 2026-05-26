// 순회강연 (TUKorea,백준, 정렬, 우선순위큐, 그리디)
// http://210.93.60.51/problem/0187

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // {마감일, 강연료}
    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i)
    {
        int p, d;
        cin >> p >> d;

        v.push_back({ d, p });
    }

    // 마감일 기준 오름차순 정렬
    sort(v.begin(), v.end());

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        int d = v[i].first;
        int p = v[i].second;

        pq.push(p);

        // 현재 강연 개수가 마감일보다 크면
        // 가장 작은 강연료 제거
        if (pq.size() > d)
        {
            pq.pop();
        }
    }

    int result = 0;

    while (!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }

    cout << result;

    return 0;
}