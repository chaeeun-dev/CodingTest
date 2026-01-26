#include <iostream>

int main(void)
{
	int A, B;
	std::cin >> A >> B;

	if (A > 0)
	{
		if (B > 0)
			std::cout << '1' << std::endl;
		else
			std::cout << '4' << std::endl;
	}
	else
	{
		if (B > 0)
			std::cout << '2' << std::endl;
		else
			std::cout << '3' << std::endl;
	}

	return 0;
}