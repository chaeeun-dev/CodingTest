#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N;
	std::cin >> N;

	std::vector<int> num;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;

		num.push_back(input);
	}

	int v;
	std::cin >> v;
	std::cout << std::count(num.begin(), num.end(), v) << std::endl;

	return 0;
}