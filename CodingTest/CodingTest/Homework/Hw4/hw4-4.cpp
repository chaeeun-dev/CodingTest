// 실패율 (Programmers, 구현, 정렬) 
// https://school.programmers.co.kr/learn/courses/30/lessons/42889

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;

    // 스테이지 별 플레이어 수
    vector<int> playerNum(N, 0);
    for (int i = 0; i < N; ++i)
    {
        // 0번에는 1스테이지 플레이어 수
        playerNum[i] = count(stages.begin(), stages.end(), i + 1);
    }

    vector<int> arriveNum(N, 0);
    int totalPlayer = stages.size();
    int beforeStagePlayer = 0;
    // 각 스테이지에 도달한 사람 수
    for (int i = 0; i < N; ++i)
    {
        arriveNum[i] = totalPlayer - beforeStagePlayer;
        beforeStagePlayer += playerNum[i];
    }

    // 실패율 = i번의 count / 도달한 사람 수
    vector <pair<float, int>> result(N, { 0.f, 0 });   // [실패율, 스테이지 번호]
    for (int i = 0; i < N; ++i)
    {
        if (arriveNum[i] == 0)
            result[i].first = 0.f;
        else
            result[i].first = float(playerNum[i]) / arriveNum[i];

        result[i].second = i + 1;
    }

    // 정렬
    sort(result.begin(), result.end(), [](pair<float, int> a, pair<float, int> b) {
        if (a.first == b.first) // 실패율이 같다면
            return a.second < b.second;      // 스테이지 번호가 작은 순으로 정렬

        return a.first > b.first;       // 실패율이 높은 순으로 정렬
    });

    for (int i = 0; i < N; ++i)
    {
        answer.push_back(result[i].second);
    }
 
    return answer;
}

int main(void)
{
    solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });

    return 0;
}