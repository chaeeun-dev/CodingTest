#include <iostream>

int main(void)
{
	int n;
	std::cin >> n;

	int result = 0;
	for (int i = 0; i <= n; ++i)
	{
		result += i;
	}

	std::cout << result << std::endl;

	return 0;
}