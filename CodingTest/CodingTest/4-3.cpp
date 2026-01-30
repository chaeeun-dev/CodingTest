#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N;
	std::cin >> N;

	std::vector<int> vec;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;

		vec.push_back(input);
	}

	std::cout << *min_element(vec.begin(), vec.end()) << " " << *max_element(vec.begin(), vec.end());

	return 0;
}