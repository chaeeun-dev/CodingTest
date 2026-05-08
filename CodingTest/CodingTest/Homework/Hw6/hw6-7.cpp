// 1로 만들기 (TUKorea, 백준1463, DP) 
// http://210.93.60.51/problem/0183
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

// dp[i]: i를 1로 만드는 최소 연산 횟수
// dp[i] = min(dp[i-1], dp[i/2], dp[i/3]) + 1

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> dp(N + 1, 0);
	for (int i = 2; i < N + 1; ++i)
	{
		// X가 3으로 나누어 떨어지면 3으로 나눈다.
		// X가 2로 나누어 떨어지면 2로 나눈다
		// 1을 뺀다

		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];
}