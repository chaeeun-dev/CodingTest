#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N, 0);
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		// vec[a-1] ~ vec[b-1]까지 c로 채워주면 됨
		// 왜 b-1로 하면 안 되지??? 
		// -> std::fill이 [시작, 끝) 임!! 그래서 b-1이 포함되도록 b로 넣어줘야 함
		std::fill(vec.begin() + a - 1, vec.begin() + b, c);
	}

	// 출력
	for (int i = 0; i < N; ++i)
	{
		std::cout << vec[i] << " ";
	}
}

// ?: C++에서 vector는 뭘로 초기화 되나? 0으로?? -> ㅇㅇ
// ?: vector를 0으로 초기화하지 않았더라면, 채워지지 않은 곳은 어떻게 확인하지? nullptr로 체크 안 되던디..
//		-> 애초에 백터는 다 0으로 초기화되고, nullptr은 전혀 관계가 없다.