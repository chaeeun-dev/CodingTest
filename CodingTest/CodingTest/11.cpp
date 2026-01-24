#include <iostream>

int main(void)
{
	unsigned int A, B, C;
	std::cin >> A >> B >> C;

	std::cout << A + B + C << std::endl;

	return 0;
}

// 입력 값이 큰 경우를 미쳐 생각하지 못함.
// 10^12까지 커버되는 long -> OK (아마 8바이트)