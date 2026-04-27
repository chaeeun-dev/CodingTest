// 비밀지도(Programmers, 구현) 
// https://school.programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;

    //vector<vector<char>> map1(n, vector<char>(n, ' '));
    //vector<vector<char>> map2(n, vector<char>(n, ' '));

    // map1 해독
    for (int i = 0; i < n; ++i)
    {
        int temp = (arr1[i] | arr2[i]);     // 비트 or 연산

        for (int j = 0; j < n; ++j)
        {
            if (temp & 1)   // 비트 and 연산, temp의 마지막 비트가 1인지 검사
            {

            }
        }
    }

    return answer;
}

int main(void)
{
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}