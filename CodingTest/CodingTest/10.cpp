#include <iostream>

int main(void)
{
	int A, B;
	std::cin >> A >> B;

	// (3)
	std::cout << A * (B % 10) << std::endl;
	// (4)
	std::cout << A * ((B % 100) / 10) << std::endl;
	// (5)
	std::cout << A * (B / 100) << std::endl;
	// (6)
	std::cout << A * B << std::endl;

	return 0;
}