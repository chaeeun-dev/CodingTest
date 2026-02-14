#include <iostream>
#include <vector>

int main(void)
{
	std::vector<std::vector<int>> vec(9, std::vector(9, 0));
	int max = -1;
	int M = 0, N = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cin >> vec[i][j];
			if (vec[i][j] > max)
			{
				max = vec[i][j];
				M = i + 1, N = j + 1;
			}
		}
	}

	std::cout << max << std::endl;
	std::cout << M << " " << N;

	return 0;
}