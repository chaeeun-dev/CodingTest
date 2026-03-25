#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	int i;

	std::cin >> str >> i;

	std::cout << str[i - 1] << std::endl;

	return 0;
}