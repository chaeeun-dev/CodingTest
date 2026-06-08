// 소수회문 (TUKorea, 소수, 구현) 
// http://210.93.60.51/problem/0001

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int N)
{
	for (int i = 2; i < sqrt(N) + 1; ++i)	// 소수 판별: 2부터 N의 제곱근까지
	{
		if (N % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	int N;
	cin >> N;

	while (true)
	{
		string str = to_string(N);
		reverse(str.begin(), str.end());
		if (to_string(N) == str && isPrime(N))
		{
			cout << N;
			break;
		}
		N++;
	}
}