#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	std::cin >> str;

	int result = 0;
	for (int i = 0; i < str.length() / 2; ++i)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			std::cout << result << std::endl;
			return 0;
		}
	}

	result = 1;
	std::cout << result << std::endl;

	return 0;
}