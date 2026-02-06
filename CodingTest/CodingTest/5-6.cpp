#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	std::cin >> str;

	for (int i = 'a'; i <= 'z'; ++i)
	{
		int result;

		if (str.find(i) != std::string::npos)
			result = str.find(i);
		else
			result = -1;

		std::cout << result << " ";
	}

	return 0;
}