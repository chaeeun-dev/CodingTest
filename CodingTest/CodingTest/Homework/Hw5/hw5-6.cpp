// 공유기 설치 (이분탐색)
// http://210.93.60.51/problem/0259
// https://www.acmicpc.net/problem/2110

// 공유기가 모든 집을 커버하는 건 아님

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> pos;

bool check(int mid)
{
	int lastL = pos[0];		// 첫 번째 집에 공유기 설치
	int count = 1;	// 설치한 공유기 개수

	for (int i = 0; i < N; ++i)
	{	
		// 마지막 공유기 위치부터 i번째 집 사이의 거리가 mid 이상이면 새로운 공유기를 i번째 집에 설치
		if (pos[i] - lastL >= mid)
		{
			lastL = pos[i];
			count++;

			if (count == C)
				return true;	// mid 간격 이상으로 C개를 다 설치했으면 true 반환
		}
	}
	
	return false;	// mid 간격 이상 C개를 모두 설치하지 못했으므로 false 반환
}

int main(void)
{
	cin >> N >> C;
	pos.assign(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> pos[i];
	}

	// 오름차순 정렬
	sort(pos.begin(), pos.end());

	// 가장 인접한 공유기 거리의 최댓값 -> 최적화 -> 탐색 범위가 넓다(0 ~ 10억) -> 이분 탐색
	int start = 1;
	int end = 1000000000;
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;	// 중간 값으로 조건을 만족하는지 검사
		if (check(mid))		// mid 인접 거리로 C개의 공유기를 다 설치할 수 있는가?
		{
			answer = mid - 1;	// 정답 후보
			start = mid + 1;	// 오른쪽 범위 탐색(최대값 구해야 함)
		}
		else
		{
			end = mid - 1;		// 왼쪽 범위 탐색
		}
	}

	cout << answer + 1 << endl;
}