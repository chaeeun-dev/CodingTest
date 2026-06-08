#include <iostream>
#include <vector>

using namespace std;

int n = 5;
vector<int> input = { 10, 20, 30, 40, 50 };

// 누적합(prefix sum) = dp
// dp[i] = 1부터 i번째 항까지 누적 합
// 점화식 dp[i] = dp[i-1] + data[i]

vector<int> dp(n + 1, 0);

int main(void)
{
	for (int i = 1; i < n + 1; ++i)	// i = 1, 2, ..., n
	{
		dp[i] = dp[i - 1] + input[i - 1];
	}

	int right = 4, left = 3;
	cout << dp[right] - dp[left - 1] << endl;

	return 0;

}