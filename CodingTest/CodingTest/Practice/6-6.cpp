#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	std::cin >> str;

	size_t num = str.length();

	for (size_t i = 0; i <= str.length(); ++i)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == '=' || str[i + 1] == '-')
			{
				num--;
				i++;
			}
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				num -= 2;
				i += 2;
			}
			else if (str[i + 1] == '-')
			{
				num--;
				i++;
			}
		}
		else if ((str[i] == 'l' && str[i + 1] == 'j') || (str[i] == 'n' && str[i + 1] == 'j')
			|| (str[i] == 's' && str[i + 1] == '=') || (str[i] == 'z' && str[i + 1] == '='))
			{
				num--;
				i++;
			}
	}

	std::cout << num;

	return 0;
}