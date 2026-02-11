#include <iostream>
#include <string>

int main(void)
{
	int N;
	std::string str;

	std::cin >> N;

	int result = N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> str;

		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == str[j + 1])
			{
				j++;
			}
			else
			{
				// str[j]가 이후 str[j+1] ~ str[끝] 사이에 있는지 확인
				std::string checkStr = str.substr(j + 1);
				if (checkStr.find(str[j]))
					result--;
			}

		}
	}

	std::cout << result;

	return 0;
}