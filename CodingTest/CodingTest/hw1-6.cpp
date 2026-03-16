#include <iostream>
#include <string>
#include <cmath>

int main(void)
{
	std::string str;
	std::cin >> str;

	size_t size = str.length();
	size_t firstIndex = 0, lastIndex = 0;	// 숫자 인덱스(10 구분 위해)
	int inputVal, preVal = 0;
	int result = 0;
	bool isMultiply = false, isSubtract = false;

	for (size_t i = 0; i < size; ++i)
	{
		isMultiply = false, isSubtract = false;

		// 숫자 - 제곱 - (옵션)
		// 제곱 전까지 숫자로 변환
		if (str[i] == 'S' || str[i] == 'D' || str[i] == 'T')
		{
			lastIndex = i - 1;
			
			// 숫자 str -> int
			if (firstIndex == lastIndex)	// 한 자리 숫자일 떄
			{
				std::string toInt = str.substr(firstIndex, 1);
				inputVal = std::stoi(toInt);

				firstIndex++;
			}
			else  // 숫자가 10일 떄
			{
				inputVal = 10;

				firstIndex += 2;
			}
			preVal = inputVal;

			// 옵션
			if (str[i + 1] == '*')
			{
				isMultiply = true;
				firstIndex++;
			}
			else if (str[i + 1] == '#')
			{
				isSubtract = true;
				firstIndex++;
			}

			// 바로 전에 얻은 점수 + 해당 점수를 곱하기
			if (isMultiply)
			{
				if (str[i] == 'S')
					result += inputVal * 2 + preVal * 2;
				else if (str[i] == 'D')
					result += pow(inputVal, 2) * 2 + preVal * 2;
				else if (str[i] == 'T')
					result += pow(inputVal, 3) * 2 + preVal * 2;
			}
			if (isSubtract)
			{
				if (str[i] == 'S')
					result -= inputVal;
				else if (str[i] == 'D')
					result -= pow(inputVal, 2);
				else if (str[i] == 'T')
					result -= pow(inputVal, 3);
			}
			if (!isMultiply && !isSubtract)
			{
				if (str[i] == 'S')
					result += inputVal;
				else if (str[i] == 'D')
					result += pow(inputVal, 2);
				else if (str[i] == 'T')
					result += pow(inputVal, 3);
			}
	
			firstIndex++;
		}
	}

	std::cout << result;
	return 0;
}