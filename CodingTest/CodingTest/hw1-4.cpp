// 문자열 폭발(TUKorea)
// http://210.93.60.51/problem/0079

#include <iostream>
#include <string>

int main(void)
{
	std::string input, bomb;
	std::cin >> input >> bomb;

	while (true)
	{
		size_t index = input.find(bomb);
		if (index == std::string::npos)
			break;

		size_t bombLen = bomb.length();

		input.erase(index, bombLen);
	}

	std::cout << input << std::endl;

	return 0;
}

// erase 함수
// str.erase(index, len)
// index부터 len까지 삭제