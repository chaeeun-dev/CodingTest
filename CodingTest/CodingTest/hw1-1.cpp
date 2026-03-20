// ж擔蘊(寥遽)
// https://www.acmicpc.net/problem/1100

#include <iostream>

int main(void)
{
	int result = 0;

	for (int i = 0; i < 8; ++i)
	{
		std::string input;
		std::cin >> input;

		// 礎熱 還
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (j % 2 == 0 && input[j] == 'F')
					result++;
			}
		}
		// �汝� 還
		else
		{
			for (int k = 0; k < 8; ++k)
			{
				if (k % 2 == 1 && input[k] == 'F')
				result++;
			}
		}
	}

	std::cout << result << std::endl;
	return 0;
}

