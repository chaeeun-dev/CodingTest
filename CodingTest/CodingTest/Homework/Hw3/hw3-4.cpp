// 여행경로(Programmers, DFS)
// https://school.programmers.co.kr/learn/courses/30/lessons/43164
// https://www.youtube.com/watch?v=b1G0EsqOvr8&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=6
// https://www.youtube.com/watch?v=SPdMC1wNKDs&list=PLg0hsGjqxAUZimgPzzUdTjrV0bn5ALtAl&index=27

// [백트레킹] DFS_Rec로 풀기
// 동일한 티켓이 여러 장 있을 수 있음 -> 동일한 경로를 여러 번 여행해야 모두 사용 가능
// 중복 티켓이 존재하는 경우 -> graph[][]를 int 배열로
// 티켓 순서가 바뀔 경우 전체 순회가 불가능해질 수 있음 -> 다른 티켓으로도 전체 순회를 검사

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> graph;
vector<string> airport;
vector<string> path;
bool isFound = false;
int ticketNum;

void DFS_Rec(string startPort)
{
    path.push_back(startPort);

    // 모든 티켓을 사용했다면
    if (ticketNum == 0)
    {
        isFound = true;
        return;
    }

    // 출발 공항의 airport 리스트에서의 인덱스를 구함
    int startPortIndex = find(airport.begin(), airport.end(), startPort) - airport.begin();

    // 출발 공항에서 갈 수 있는 알파벳이 빠른 공항을 찾음
    for (int c = 0; c < airport.size(); ++c)
    {
        // startPort -> c 경로가 존재한다면
        if (graph[startPortIndex][c] > 0)
        {
            graph[startPortIndex][c]--; // 해당 경로 여행
            ticketNum--;    // 티켓 개수 감소

            // 인덱스 c에 해당하는 도착 공항을 출발 공항으로 재귀 호출
            DFS_Rec(airport[c]);

            if (isFound)
                return;
            else
            {
                graph[startPortIndex][c]++;     // 여행 경로 복원
                ticketNum++;
            }
        }
    }

    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) 
{
    // STEP1. 티켓을 조회해서 모든 공항을 중복을 허락하지 않고 알파벳 순서로 공항 리스트 생성

    for (vector<string> v : tickets)
    {
        for (string str : v)
        {
            // 공항이 이미 있으면 건너 뜀
            if (find(airport.begin(), airport.end(), str) != airport.end())
                continue;

            // 공항 리스트에 추가
            airport.push_back(str);
        }
    }

    sort(airport.begin(), airport.end());   // 알파벳 정렬

    // STEP2. 티켓을 보면서 경로 graph 생성
    // NxN 배열 0으로 초기화(동일한 경로에 티켓이 여러 장 있을 수 있음)
    int N = airport.size();
    graph.assign(N, vector<int>(N, 0));

    // 티켓 배열을 돌면서 티켓 수 추가
    for (vector<string> v : tickets)
    {
        int a, b;
        
        // airport에서 str("ICN", "HND" 등)이 있는 인덱스
        a = find(airport.begin(), airport.end(), v[0]) - airport.begin();   // 출발 공항
        b = find(airport.begin(), airport.end(), v[1]) - airport.begin();   // 도착 공항
    
        graph[a][b]++;  // a -> b 티켓 수 1 증가, 동일 경로 티켓이 존재할 수 있음
    }

    // STEP3. ICN에서 시작해서 DFS 재귀 백트레킹으로 티켓을 모두 사용하는 경로를 탐색
    ticketNum = tickets.size();
    DFS_Rec("ICN");

    vector<string> answer = path;
    return answer;
}

int main(void)
{
    solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} });
    //cout << '\n\n';

    solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} });

    return 0;
}