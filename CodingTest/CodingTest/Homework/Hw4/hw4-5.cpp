// 소가 길을 건너간 이유 3(백준, 정렬, 그리디)
// https://www.acmicpc.net/problem/14469
// http://210.93.60.51/problem/0205

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

	long long clock = 0;

	for (pair<int, int> p : v)
	{
		int arrive = p.first;
		int check = p.second;

		// 아직 소가 안 왔으면 기다림
		if (clock < arrive)
			clock = arrive;

		// 검문 진행
		clock += check;
	}

	cout << clock;

	return 0;
}

// 0
// 1
// 2	[2, 1]
// 3
// 5	[5, 7]
// 12	[8, 3]
// 15

