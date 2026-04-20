// 소가 길을 건너간 이유 3(백준, 정렬, 그리디)
// https://www.acmicpc.net/problem/14469

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	std::vector<pair<int, int>> v;	// [도착 시간, 검문 시간]
	for(int i = 0; i < N; ++i)
	{
		int arrive, check;
		cin >> arrive >> check;

		v.push_back(make_pair(arrive, check));
	}

	// 도착 시간을 기준으로 정렬
	sort(v.begin(), v.end());

	// Test
	for (pair<int, int> p : v)
	{
		cout << p.first << ' ' << p.second << endl;
	}

	int clock = 0;
	for (pair<int, int> p : v)
	{
		if (clock < p.first)	// 현재 시각 < 소의 도착 시간
			clock = p.first;	// -> 현재 시각을 소의 도착 시간으로 설정

		// 도착 시간으로 더하기
	}
}

// 0
// 1
// 2	[2, 1]
// 3
// 5	[5, 7]
// 12	[8, 3]
// 15

