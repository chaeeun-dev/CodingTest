#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N;
	std::cin >> N;

	std::vector<double> vec(N, 0.f);

	for (int i = 0; i < N; ++i)
	{
		double result;
		std::cin >> result;

		vec[i] = result;
	}

	double maxResult = *max_element(vec.begin(), vec.end());
	// 과목별 점수 변경
	for (double& v : vec)
	{
		double change = v / maxResult * 100;
		v = change;
	}

	// 평균 점수
	double result = 0;
	for (double& v : vec)
	{
		result += v;
	}
	result /= vec.size();
	
	std::cout << result << std::endl;

	return 0;
}

// 자꾸 변경된 점수가 저장이 안 돼서 봤더니.. for(double v : vec)이게 복사라는 걸 알아차림..
// 아 미쳤나봐!! 제일 기본인데^^ 그래도 지금이라도 깨달아서 다행
// for (double& v : vec)로 변경했더니 해결