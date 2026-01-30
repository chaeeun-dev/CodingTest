#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 9; ++i)
	{
		int input;
		std::cin >> input;

		vec.push_back(input);
	}
	
	std::cout << *max_element(vec.begin(), vec.end()) << std::endl;
	std::cout << max_element(vec.begin(), vec.end()) - vec.begin() + 1 << std::endl;

	return 0;
}

// max_element
// 1. 값 구하기: max_element는 위치를 반환하기 때문에 포인터로 값 구함
// 2. 인덱스 구하기: 최대값을 가리키는 반복자 - 맨 처음 가리키는 begin