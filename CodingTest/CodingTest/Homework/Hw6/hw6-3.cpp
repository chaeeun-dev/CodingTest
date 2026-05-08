// 베스트 앨범 (Programmers, 구현) 
// https://school.programmers.co.kr/learn/courses/30/lessons/42579

// 풀고 있는 중......................

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 아이디어(생각)
// 장르 별 벡터를 만들고 다 더함
// 재생 횟수가 가장 큰 장르 구함
// 장르 별 벡터에서 재생 횟수 별로 내림차순 정렬
// 장르 별 벡터의 0번 값을 비교해서 가장 크면 [0], [1]  값  answer에 추가
// 두번 째로 크면 0, 1 [0], [1] 값 넣기 
vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    vector <pair<string, int>> arr; // [이름, 재생 횟수]
    size_t length = genres.size();
    for (size_t i = 0; i < length; ++i)
    {
        arr.push_back({ genres[i], plays[i] });
    }

    // 가장 많이 재생된 장르 구하기
    int mostPlayIndex = *max_element(plays.begin(), plays.end());
    string mostPlayGenre = genres[mostPlayIndex];

    cout << mostPlayGenre << endl;

    // 장르 내에서 가장 많이 재생된 노래 수록 후, 그 다음 가장 많이 재생된 노래 수록
    // 재생 횟수가 같다면, 고유 번호가 낮은 노래 수록

    // 두 번째로 많이 재생된 장르 구함
    // 장르 내에서 가장 많이 재생된 노래 수록 ~

    return answer;
}

int main(void)
{
    solution({ "classic", "pop", "classic", "classic", "pop" },
        { 500, 600, 150, 800, 2500 });
}