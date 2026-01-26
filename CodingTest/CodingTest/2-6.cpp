#include <iostream>

int main(void)
{
	int A, B, C;
	std::cin >> A >> B >> C;

	int H, M;

	if (B + C < 60)
	{
		H = A;
		M = B + C;
	}
	else
	{
		H = A + ((B + C) / 60);
		M = (B + C) % 60;

		if (H > 23)
			H %= 24;
	}

	std::cout << H << ' ' << M << std::endl;

	return 0;
}