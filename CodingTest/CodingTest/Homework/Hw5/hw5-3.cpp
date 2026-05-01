// Postfix 표현식(TUKorea, 스택) 
// http://210.93.60.51/problem/0059

// stack 활용하기
// a, b 넣고 + 나오면 꺼내서 (a + b) 넣고 ~ 반복
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	stack<string> s;
	string input;

	cin >> input;
	
	for (char c : input)
	{
		// 알파벳
		if (c >= 'a' && c <= 'z')
		{
			string ctos = string(1, c);
			s.push(ctos);
		}
		// 부호
		else
		{
			// 스택에서 꺼냄 - top과 pop은 쌍으로!
			string s2 = s.top();
			s.pop();
			string s1 = s.top();
			s.pop();

			string str = "(" + s1 + c + s2 + ")";

			// 스택에 결과를 넣음
			s.push(str);
		}
	}

	cout << s.top() << endl;
}