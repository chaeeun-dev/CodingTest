#include <iostream>
#include <string>

int main(void)
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int R;
		std::string S;

		std::cin >> R >> S;

		for (int j = 0; j < S.length(); ++j)
		{
			for (int k = 0; k < R; ++k)
			{
				std::cout << S[j];
			}
		}

		std::cout << std::endl;
	}

	return 0;
}