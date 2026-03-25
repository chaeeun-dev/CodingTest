#include <iostream>

int main(void)
{
	int H, M;
	std::cin >> H >> M;

	if (M < 45)
	{
		if (H == 0)
			H = 23;
		else
			H--;
	
		M = M + 15;
	}
	else
	{
		M = M - 45;
	}

	std::cout << H << ' ' << M << std::endl;

	return 0;
}