// 회의실 배정(백준, 정렬, 그리디)
// https://www.acmicpc.net/problem/1931
// http://210.93.60.51/problem/0204

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// N: 회의 수
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);	// [시작 시간, 끝나는 시간]
	// 입력
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)	// 끝나는 시간이 같다면 -> 시작 시간이 빠른 순서대로 정렬
			return a.first < b.first;

		return a.second < b.second;	// 끝나는 시간 기준으로 정렬
	});

	int count = 1;	// 처음 회의 개수 1
	int curEnd = v[0].second;	// 처음 인덱스의 끝나는 시간 저장
	for (int i = 0; i < N; ++i)
	{
		if (i < N - 1 && curEnd <= v[i + 1].first)	// 현재 회의 끝 <= 다음 회의 시작 시간
		{
			count++;
			curEnd = v[i + 1].second;	// 현재 끝 갱신
		}
	}

	cout << count;

	return 0;
}