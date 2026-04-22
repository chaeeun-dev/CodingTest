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
	string str;

	cin >> str;
	
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
			s.push(string{ str[i] });	// 생성자로
		else
		{
			//b = s.pop();
		}

	}
}

//