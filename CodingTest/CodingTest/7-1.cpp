#include <iostream>
#include <vector>

int main(void)
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
	std::vector<std::vector<int>> B(N, std::vector<int>(M, 0));

	// 입력
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> B[i][j];
		}
	}

	// 더하기와 출력
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << A[i][j] + B[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}