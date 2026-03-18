#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> coinTypes(N);
	for (int i = 0; i < N; ++i)
	{
		int value;
		std::cin >> value;

		coinTypes[i] = value;
	}

	// 오름차순 -> 내림차순 정렬로 바꿈
	reverse(coinTypes.begin(), coinTypes.end());

	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cnt += K / coinTypes[i];
		K %= coinTypes[i];
	}

	std::cout << cnt << std::endl;
	return 0;
}