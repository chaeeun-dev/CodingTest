#include <iostream>
#include <string>

int main(void)
{
	int N;
	std::string str;

	std::cin >> N >> str;
	
	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		result += str[i] - '0';
	}

	std::cout << result << std::endl;
}

// 숫자의 아스키 값은 48번부터 0~9를 할당함 
// -> 문자열에서 48을 빼주면 숫자가 되는데, 가독성 측면에서 - '0' 해주면 됨