#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec(50, 0);

	for (int i = 0; i < 10; ++i)
	{
		int input;
		std::cin >> input;

		int result = input % 42;
		vec[result] += 1;
	}

	int result = 0;
	for (int a : vec)
	{
		if (a != 0)
			result++;
	}

	std::cout << result << std::endl;

	return 0;
}

// 문제 이해를 제대로 못해서 시간 오래걸림