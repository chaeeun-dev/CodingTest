// 다트게임(Programmers)?
// https://school.programmers.co.kr/learn/courses/30/lessons/17682

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
	int answer = 0;
	
	size_t strSize = dartResult.length();
	int initVal[3]{};
	int order = 0;

	for (size_t i = 0; i < strSize; ++i)
	{
		// 숫자
		if (isdigit(dartResult[i]))
		{
			if (isdigit(dartResult[i + 1]))	// 10
			{
				initVal[order] = 10;
				i++;
			}
			else  // 0 ~ 9
			{
				initVal[order] = dartResult[i] - '0';	// stoi 대신
			}

			if (dartResult[i + 1] == 'D')
			{
				initVal[order] = pow(initVal[order], 2);
			}
			else if (dartResult[i + 1] == 'T')
			{
				initVal[order] = pow(initVal[order], 3);
			}

			// 옵션
			if (dartResult[i + 2] == '*')
			{
				if (order == 0)
				{
					initVal[order] *= 2;
				}
				else
				{
					initVal[order - 1] *= 2;
					initVal[order] *= 2;
				}
			}
			else if (dartResult[i + 2] == '#')
			{
				initVal[order] *= -1;
			}

			order++;
		}
	}

	answer = initVal[0] + initVal[1] + initVal[2];
	return answer;
}

int main(void)
{
	cout << solution("1S2D*3T") << endl;
	cout << solution("1D2S#10S") << endl;
	cout << solution("1D2S0T") << endl;
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;

	return 0;
}

// isdigit(str[i]) -> 문자열에 숫자가 있는지? 있으면 1 없으면 0 반환
// str to int -> stoi 말고 - '0'로 해도 됨.