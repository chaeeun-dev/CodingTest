#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	getline(std::cin, str);	// 공백 포함 입력

	int result = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
			result++;
	}

	if (str[0] == ' ')
		result--;
	if (str[str.length() - 1] == ' ')
		result--;

	std::cout << result + 1 << std::endl;

	return 0;
}