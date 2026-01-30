#include <cstdio>
#include <iostream>

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T, A, B;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		std::cin >> A >> B;
		std::cout << A + B << "\n";
	}

	return 0;
}