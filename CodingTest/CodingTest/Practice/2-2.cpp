#include <iostream>

int main(void)
{
	int grade;
	std::cin >> grade;

	if (grade >= 90)
		std::cout << 'A' << std::endl;
	else if (grade >= 80 && grade <= 89)
		std::cout << 'B' << std::endl;
	else if (grade >= 70 && grade <= 79)
		std::cout << 'C' << std::endl;
	else if (grade >= 60 && grade <= 69)
		std::cout << 'D' << std::endl;
	else
		std::cout << 'F' << std::endl;

	return 0;
}