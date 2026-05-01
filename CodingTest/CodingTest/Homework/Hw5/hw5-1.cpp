// 나무 자르기(TUKorea0070, 백준, 이분탐색)
// http://210.93.60.51/problem/0070

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

// N: 나무 수, M 가져가려는 길이
int N, M; 

bool check(int mid)
{
	// *** long long으로 써야 오버플로우 안 남!!!
	long long total = 0;	// 자투리의 총합

	for (int height : v)
	{
		if (height > mid)
			total += (height - mid);
	}

	if (total >= M)
		return true;
	else
		return false;
}

int main(void)
{

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int h;
		cin >> h;

		v.push_back(h);
	}

	int start = 1;
	int end = 2'000'000'000;
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (check(mid))
		{
			// 최대값
			answer = mid;
			start = mid + 1;
		}
		else
		{
			// 최소값
			end = mid - 1;
		}
	}

	cout << answer << endl;
}