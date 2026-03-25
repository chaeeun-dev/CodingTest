#include <iostream>

int main(void)
{
	int X, N, a, b;
	int sum = 0;

	std::cin >> X >> N;

	for (int i = 0 ; i < N; ++i)
	{
		std::cin >> a >> b;
		sum += a * b;
	}

	if (X == sum)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}