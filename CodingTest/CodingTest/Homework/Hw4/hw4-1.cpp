// 주식투자 (백준, 구현) 
// https://www.acmicpc.net/problem/13416

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T, N;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{	
		cin >> N;

		int profit = 0;

		for (int i = 0; i < N; ++i)
		{
			int A, B, C;
			cin >> A >> B >> C;

			int maxVal = max({ A, B, C });
			if (maxVal > 0)
			{
				profit += maxVal;
			}
		}

		cout << profit << endl;
	}

	return 0;
}