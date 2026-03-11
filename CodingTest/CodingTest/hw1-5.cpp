#include <iostream>
#include <string>

int main(void)
{
	std::string A, B;
	std::cin >> A >> B;

	size_t ALen = A.length(), BLen = B.length();

	int crossA = 0, crossB = 0;
	bool flag = false;
	for (int i = 0; i < ALen; ++i)
	{
		if (flag)
			break;

		for (int j = 0; j < BLen; ++j)
		{
			if (A[i] == B[j])
			{
				crossA = i;
				crossB = j;
				flag = true;
				break;
			}
		}
	}

	// 출력
	for (int i = 0; i < BLen; ++i)
	{
		for (int j = 0; j < ALen; ++j)
		{
			if (j == crossA)	// 열 B 출력
				std::cout << B[i];
			else if (i == crossB)	// 행 A 출력
				std::cout << A[j];
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}

	return 0;
}