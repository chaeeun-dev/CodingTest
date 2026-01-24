#include <iostream>

int main(void)
{
	int A, B;
	std::cin >> A >> B;

	std::cout.precision(15);
	std::cout << (double)A / (double)B << std::endl;

	return 0;
}

// float로 하니까 1 / 3 = 0.33334786 이렇게 나옴
// double로 하니까 0.3333333333 올바르게 나옴
// cout.precision 해야 오차 X
// -> float보다 double이 훨씬 정밀하다.