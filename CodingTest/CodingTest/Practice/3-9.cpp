#include <iostream>

int main(void)
{
	int N;
	std::cin >> N;

	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}