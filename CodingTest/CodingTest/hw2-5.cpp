#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// n: 전체 학생 수
// lost: 잃어버린 학생 배열
// reserve: 여분 있는 학생


// 틀린 답 -> 순회 중에 삭제하면 안 됨. 
// 그리고 너무 복잡하게 생각했음..
int solution2(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int lostNum : lost)
    {
        // 잃어버린 학생 == 여분 있는 학생
        auto it = find(reserve.begin(), reserve.end(), lostNum);
        if (it != reserve.end())
        {
            // reserve 삭제
            reserve.erase(it);

            // lost 삭제
            auto it2 = find(lost.begin(), lost.end(), lostNum);
            lost.erase(it2);
        }
    }

    for (int lostNum : lost)
    {
        // 앞에 여분이 있는지?
        if (lostNum == 1)
            continue;

        auto itForward = find(reserve.begin(), reserve.end(), lostNum - 1);

        if (itForward != reserve.end())
        {
            // resreve 삭제
            reserve.erase(itForward);

            // lost 삭제
            auto it2 = find(lost.begin(), lost.end(), lostNum);
            lost.erase(it2);
        }
    }

    for (int lostNum : lost)
    {
        // 뒤에 여분이 있는지?
        if (lostNum == 1 || lostNum == n)
            continue;

        auto itBackward = find(reserve.begin(), reserve.end(), lostNum + 1);

        if (itBackward != reserve.end())
        {
            // resreve 삭제
            reserve.erase(itBackward);

            // lost 삭제
            auto it2 = find(lost.begin(), lost.end(), lostNum);
            lost.erase(it2);
        }
    }

    answer = n - lost.size();
    return answer;
}

// 체육복을 가진 수를 표현하는 벡터로 푸니까 훨씬 간단하구나
// 너무 복잡하게 생각해서 위에처럼 꼬아버림..
int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;

    vector<int> student(n, 1);

    for (size_t i = 0; i < lost.size(); ++i)
    {
        student[lost[i] - 1]--;
    }

    for (size_t i = 0; i < reserve.size(); ++i)
    {
        student[reserve[i] - 1]++;
    }

    for (size_t i = 0; i < student.size(); ++i)
    {
        if (student[i] == 0)
        {
            if (i != 0 && student[i - 1] == 2)
            {
                student[i]++;
                student[i - 1]--;
            }
            else if (i + 1 != student.size() && student[i + 1] == 2)
            {
                student[i]++;
                student[i + 1]--;
            }
        }
    }

    for (int stu : student)
    {
        if (stu >= 1)
            answer++;
    }

    return answer;
}

int main(void)
{
    cout << solution(5, { 2, 4 }, { 1, 3, 5 }) << endl;
    cout << solution(5, { 2, 4 }, { 3 }) << endl;
    cout << solution(3, { 3 }, { 1 }) << endl;
}