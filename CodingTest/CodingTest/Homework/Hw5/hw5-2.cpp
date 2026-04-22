// 사칙연산(TUKorea, 백준, 구현)
// http://210.93.60.51/problem/0181
// https://www.acmicpc.net/problem/13420

#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		long a, b, inputAnswer;
		char op, equal;

		cin >> a >> op >> b >> equal >> inputAnswer;

		long answer;
		switch (op)
		{
		case '+':
			answer = a + b;
			break;
		case '-':
			answer = a - b;
			break;
		case '*':
			answer = a * b;
			break;
		case '/':
			answer = a / b;
			break;
		}

		if (inputAnswer == answer)
			cout << "correct" << endl;
		else
			cout << "wrong answer" << endl;
	}

	return 0;
}