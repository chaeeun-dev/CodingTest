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

    // 스테이지의 개수
    int totalStage = *max_element(stages.begin(), stages.end());
    // 스테이지 별 플레이어 수
    vector<int> playerNum(totalStage, 0);
    for (int i = 0; i < totalStage; ++i)
    {
        // 0번에는 1스테이지 플레이어 수
        playerNum[i] = count(stages.begin(), stages.end(), i + 1);
    }

    vector<int> arriveNum(totalStage, 0);
    int totalPlayer = stages.size();
    int beforeStagePlayer = 0;
    // 각 스테이지에 도달한 사람 수
    for (int i = 0; i < totalStage; ++i)
    {
        arriveNum[i] = totalPlayer - beforeStagePlayer;
        beforeStagePlayer += playerNum[i];
    }

    // 실패율 = i번의 count / 도달한 사람 수
    vector<int> result(N, 0.f);   // 실패율
    for (int i = 0; i < totalStage; ++i)
    {
        result[i] = playerNum[i] / arriveNum[i];
    }

    return answer;
}

int main(void)
{
    solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });

    return 0;
}