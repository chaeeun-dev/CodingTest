// 가장 큰 증가하는 부분 수열(TUKorea, 백준11055, DP) 
// http://210.93.60.51/problem/0185
// https://www.acmicpc.net/problem/11055
// * 점화식을 그림으로 이해하기!!!

// 증가하는 부분 수열 중 합이 가장 큰 것을 구하기
// 수열 입력과 dp 테이블을 따로 받기(오염돼서)

// dp[i]: i번째 원소를 포함한 가장 큰 증가하는 부분 수열의 합
// dp[i] 초기값: 입력으로 받은 array[i]로 설정
// dp[i] = max(dp[i], dp[j] + array[i]) if array[j] < array[i] (0<=j<i) 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// input
	int N;
	cin >> N;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	// dp 테이블 초기화
	vector<int> dp = arr;
	for (int i = 1; i < N; ++i)	// i = 1, 2, ..., N-1
	{
		for (int j = 0; j < i; ++j)	// j = 0, 1, 2, ..., i-1
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}