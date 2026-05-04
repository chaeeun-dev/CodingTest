// 도둑질 (Programmers, DP) 
// https://school.programmers.co.kr/learn/courses/30/lessons/42897
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// dp 테이블을 2개 만듦
// dp0[i]: 0번집부터 털어서 i번째까지 털었을 때 최대값 (0 <= i <= 집의 개수 - 2)
// dp1[i]: 1번집부터 털어서 i번째까지 털었을 때 최대값 (1 <= i < 집의 개수 - 1)

// 점화식
// dp[i] = max(money[i] + dp[i-2], dp[i-1])

int solution(vector<int> money) 
{
    int answer = 0;

    size_t length = money.size();

    vector<int> dp0(length, 0);
    dp0[0] = money[0];
    dp0[1] = max(money[0], money[1]);
    // i = 2, 3, ..., L-2 (마지막 집 전까지)
    for (int i = 2; i < length - 1; ++i)
    {
        dp0[i] = max(money[i] + dp0[i - 2], dp0[i - 1]);
    }
    
    vector<int> dp1(length, 0);
    dp1[1] = money[1];
    // i = 2, 3, ..., L-1 (마지막 집까지)
    for (int i = 2; i < length; ++i)
    {
        dp1[i] = max(money[i] + dp1[i - 2], dp1[i - 1]);
    }

    answer = max(dp0[length - 2], dp1[length - 1]);
    return answer;
}

int main(void)
{
    solution({ 1, 2, 3, 1 });
}