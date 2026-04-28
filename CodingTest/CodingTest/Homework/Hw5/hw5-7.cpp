// 예산 (이분탐색)
// http://210.93.60.51/problem/0260
// https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> request;

bool check(int mid)
{
	int total = 0;
	for (int r : request)
	{
		if (r < mid)
		{
			total += r;
		}
		else
		{
			total += mid;
		}
	}

	if (total <= M)
		return true;
	
	return false;
}

int main(void)
{
	cin >> N;
	request.assign(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> request[i];
	}

	cin >> M;

	int start = 0;
	int end = *max_element(request.begin(), request.end());		// 상한을 1'000'000'000으로 하면 안 됨, 요청된 예산 중에 최대값
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (check(mid))		// 중간 값으로 예산 배정했을 때 배정된 예산 총액이 M 이하인가?
		{
			answer = mid;	// 정답 후보
			start = mid + 1;	// 오른쪽 범위 탐색
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << answer << endl;
}

