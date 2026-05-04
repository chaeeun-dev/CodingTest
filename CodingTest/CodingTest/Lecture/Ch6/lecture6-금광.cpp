#include <iostream>
#include <vector>

int main(void)
{
	int n, m;

	// 다이나믹 프로그래밍
	for (int c = 1; i < m; ++i)
	{
		for (int r = 0; r < n; ++r)
		{
			// 왼쪽 위
			if (r == 0)
				left_up = 0;
			else
				left_up = dp[r - 1][c - 1];

			// 왼쪽 아래
			if (r == n - 1)
				left_down = 0;
			else
				left_down = dp[r + 1][c - 1];

			// 왼쪽
			left = dp[r][c - 1];
			dp[r][c] = dp[r][c] + max(left_upp, left_down, left);

		}
	}

}
