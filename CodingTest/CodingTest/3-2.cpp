#include <iostream>
#include <vector>

int main(void)
{
	int T;
	std::cin >> T;

	std::vector<int> vecA;
	std::vector<int> vecB;

	// 입력
	for (int i = 0; i < T; ++i)
	{
		int A, B;
		std::cin >> A >> B;
	
		vecA.push_back(A);
		vecB.push_back(B);
	}

	// 출력
	for (int i = 0; i < T; ++i)
	{
		std::cout << vecA[i] + vecB[i] << std::endl;
	}

	return 0;
}

// 입력 - 출력 형태로 for문을 돌려도 되지만
// 한 번에 출력하기 위해 Vector를 사용함