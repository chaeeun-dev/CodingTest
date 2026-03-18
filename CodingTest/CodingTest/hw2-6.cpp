#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// n: 전체 학생 수
// lost: 잃어버린 학생 배열
// reserve: 여분 있는 학생
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 여벌을 가져온 학생이 도난 -> lost와 reserve에서 제거
    for (size_t i = 0; i < lost.size(); ++i)
    {
        if (auto it = find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()) // 존재할 때
        {
            int index = it
            reserve.erase(reserve.begin(), index);
        }
    }

    // _reserve에서 하나씩 꺼내서, 빌려줄 수 있으면 빌려줌
    for (int reserve : _reserve)
    {
        int forward = reserve - 1;
        int backward = reserve + 1;

        if (find(_lost.begin(), _lost.end(), forward))
    }



    return answer;
}

int main(void)
{
    solution(5, { 2, 3 }, { 1, 3, 5 });
}