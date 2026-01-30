#include <iostream>

int main(void)
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N - i; ++j)
		{
			std::cout << " ";
		}
		for (int k = 1; k <= i; ++k)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	return 0;
}