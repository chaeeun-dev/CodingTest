#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N);
	
	// 초기화
	for (int i = 0; i < N; ++i)
	{
		vec[i] = i + 1;
	}

	// 교환
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;

		std::swap(vec[a - 1], vec[b - 1]);
	}

	// 출력
	for (int i = 0; i < N; ++i)
	{
		std::cout << vec[i] << " ";
	}

	return 0;
}

// vector의 swap