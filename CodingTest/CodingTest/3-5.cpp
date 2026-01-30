#include <iostream>

int main(void)
{
	int N;
	std::cin >> N;

	int longNum = N / 4;
	for (int i = 0; i < longNum; ++i)
	{
		std::cout << "long ";
	}

	std::cout << "int" << std::endl;

	return 0;
}