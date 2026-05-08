// 설탕배달(TUKorea, 백준2839, DP) 
// http://210.93.60.51/problem/0182

#include <iostream>
#include <vector>

using namespace std;

// 설탕 배달 N kg을 3, 5 kg 봉지를 최소한으로 사용해서 배달
// dp[i]: ikg을 3, 5kg 봉지로 만드는 최소 봉지 개수
// dp[0] = 0, 나머지 dp[i] = INF 초기화

// 점화식
// 모든 k (3, 5)에 대해서 dp[i-k]가 INF가 아니면,
// dp[i] = min(dp[i], dp[i-k] + 1)

int main(void)
{
	int N;
	cin >> N;

	int x = 1000'000'000;
	vector<int> dp(N + 1, x);
	dp[0] = 0;

	for (int k : {3, 5})
	{
		for (int i = k; i < N + 1; ++i)
		{
			if (dp[i - k] != x)
				dp[i] = min(dp[i], dp[i - k] + 1);
		}
	}

	// 정확하게 N kg을 만들 수 없다면 -1 출력
	if (dp[N] != x)
		cout << dp[N] << endl;
	else
		cout << -1 << endl;
}