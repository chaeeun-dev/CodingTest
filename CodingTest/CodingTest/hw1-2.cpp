#include <iostream>

int main(void)
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int H, W, N;
		std::cin >> H >> W >> N;

		// 층수
		int floor = N % H;
		int room = N / H + 1;
		if (floor == 0)	// H층일 경우 예외 처리
		{
			floor = H;
			room--;		// 몫이 1이 증가되므로 빼줌
		}

		std::cout << floor * 100 + room << std::endl;
	}

	return 0;
}