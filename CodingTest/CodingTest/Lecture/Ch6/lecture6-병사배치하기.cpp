// 감소하는 부분 수열의 길이의 최대값
// dp[i]: i번 원소를 포함해서 가장 긴 감소하는 부분 수열의 길이
// 점화식: dp[i] = max(dp[i], dp[j] + 1) if array[j] > array[i] (0<=j<i)

// 증가하는 것은 if (array ~) 이 부분의 부등호를 바꿔주면 됨 
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// input
	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;
		
		arr.push_back(a);
	}

	// dp 테이블 1로 초기화
	vector<int> dp(N, 1);

	for (int i = 0; i < N; ++i)	// i = 1, 2, ..., n-1
	{
		for (int j = 0; j < i; ++j)	// j = 0, 1, 2, ..., i-1
		{
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
}