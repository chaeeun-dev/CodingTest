// RGB거리(TUKorea, 백준1149, DP) 
// http://210.93.60.51/problem/0141
// https://www.acmicpc.net/problem/1149

// 금광문제 변형
// 입력받은 수열 그대로 dp 테이블로 사용(오염 안 됨)

// dp[i][j]: i 번째 집에서 j 색을 칠한 경우 비용 합계의 최소값
// dp[i][j] = array[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	// 2차원 벡터
	vector<vector<int>> arr(N, vector<int>(3, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}
	vector<vector<int>> dp(N, vector<int>(3, 0));
	dp = arr;

	for (int i = 1; i < N; ++i)	// i = 1, 2, ..., N-1
	{
		for (int j = 0; j < 3; ++j)	// j = 0, 1, 2
		{
			dp[i][j] = arr[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}

	cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());
}