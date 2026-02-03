#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N, 0);

	// 바구니 값 초기화
	for (int i = 0; i < N; ++i)
	{
		vec[i] = i + 1;
	}

	// 역순으로 바꾸기
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;
	
		int swapNum = 0;
		if ((b - a) % 2 == 1)
			swapNum = (b - a) / 2 + 1;
		else
			swapNum = (b - a) / 2;
		
		a--, b--;	// 인덱스 조정
		for (int j = 0; j < swapNum; ++j)
		{
			std::swap(vec[a + j], vec[b - j]);
		}
	}

	// 출력
	for (int v : vec)
	{
		std::cout << v << " ";
	}

	return 0;
}

// 아직은 배열 인덱스 계산이 헷갈린다..
// 익숙해져야지