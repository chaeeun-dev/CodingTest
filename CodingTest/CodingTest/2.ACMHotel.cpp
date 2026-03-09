#include <iostream>

int main(void)
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int H, W, N;
		std::cin >> H >> W >> N;

		// Ãþ¼ö
		int floor = N % H;
		// È£¼ö
		int room = N / H + 1;

		std::cout << floor * 100 + room << std::endl;
	}

	return 0;
}