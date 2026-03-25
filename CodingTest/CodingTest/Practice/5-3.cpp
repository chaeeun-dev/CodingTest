#include <iostream>
#include <string>

int main(void)
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		std::string input;
		std::cin >> input;

		std::cout << input[0] << input[input.size() - 1] << std::endl;
	}
	
	return 0;
}