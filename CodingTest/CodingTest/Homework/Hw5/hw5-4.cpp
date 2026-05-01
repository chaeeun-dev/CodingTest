// 비밀지도(Programmers, 구현) 
// https://school.programmers.co.kr/learn/courses/30/lessons/17681

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;

    for (int i = 0; i < n; ++i)
    {
        // 비트 연산
        int bit = (arr1[i] | arr2[i]);

        string result;
        for (int j = n - 1 ; j >= 0; j--)    // 가장 왼쪽 비트부터 확인, n-1부터 시작해야 인덱스 4 ~ 0에 접근 
        {
            if (bit & (1 << j)) // j번째 비트가 1인지 확인
                result += "#";
            else // 0
                result += " ";
        }

        answer.push_back(result);
    }

    return answer;
}

int main(void)
{
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}