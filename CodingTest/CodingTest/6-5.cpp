#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void)
{
	std::string str;
	std::vector<int> num('Z' - 'A' + 1);

	std::cin >> str;

	for (size_t i = 0; i <= str.length() - 1; ++i)
	{
		for (int j = 'A'; j <= 'Z'; ++j)
		{
			if (str[i] == j || str[i] == j + 'a' - 'A')
			{
				num[j - 'A']++;
			}
		}
	}

	int maxNum = 0;
	auto it = std::max_element(num.begin(), num.end());
	for (auto i = num.begin(); i != num.end(); ++i)
	{
		if (*i == *it)
			maxNum++;
	}

	if (maxNum == 1)
	{
		int index = it - num.begin();
		std::cout << (char)(index + 'A');
	}
	else
		std::cout << "?";
}