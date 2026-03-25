#include <iostream>
#include <vector>

int main(void)
{
	int N, X;
	std::cin >> N >> X;

	std::vector<int> A;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;

		A.push_back(input);
	}

	for (int a : A)
	{
		if (a < X)
			std::cout << a << " ";
	}

	return 0;
}