#include <iostream>

int main(void)
{
	int N;
	std::cin >> N;

	// 1 ~ N - 1 มู
	for (int i = 1; i <= N - 1; ++i)
	{
		for (int j = 0; j < N - i; ++j)
		{
			std::cout << " ";
		}
		for (int k = 0; k < i * 2 - 1; ++k)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	// N ~ 2N - 1 มู
	for (int i = N; i >= 0; --i)
	{
		for (int j = N - i; j > 0; --j)
		{
			std::cout << " ";
		}
		for (int k = i * 2 - 1; k > 0; --k)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}