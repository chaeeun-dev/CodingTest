#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

vector<int> indegree;
vector<int> T;

// 인접 리스트
vector<vector<int>> graph;

vector<int> dp;

void topology_sort()
{
    queue<int> q;

    // 진입차수 0인 작업 시작
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        // now 이후에 가능한 작업들
        for (int next : graph[now])
        {
            indegree[next]--;

            // next 작업 완료 시간 갱신
            dp[next] = max(dp[next], dp[now] + T[next]);

            if (indegree[next] == 0)
                q.push(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    graph.resize(N + 1);
    indegree.assign(N + 1, 0);
    T.assign(N + 1, 0);
    dp.assign(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        int time, cnt;
        cin >> time >> cnt;

        T[i] = time;

        // 선행 작업이 없는 경우 자기 시간부터 시작
        dp[i] = time;

        for (int j = 0; j < cnt; ++j)
        {
            int prev;
            cin >> prev;

            // prev -> i
            graph[prev].push_back(i);

            indegree[i]++;
        }
    }

    topology_sort();

    int answer = 0;

    for (int i = 1; i <= N; ++i)
    {
        answer = max(answer, dp[i]);
    }

    cout << answer;
}