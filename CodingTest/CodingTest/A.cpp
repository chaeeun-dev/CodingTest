#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	string str;
	cin >> str;

	int holderCount = 0;

	for (int i = 0; i < N; ++i)
	{
		// 맨 앞 자리와 맨 끝자리 컵홀더 
		if (i == 0)
			holderCount++;
		
		if (str[i] == 'S')
		{
			holderCount++;
		}
		else if (str[i] == 'L')
		{
			holderCount++;
			i++;
		}
	}
	
	int result = min(holderCount, N);
	cout << result;

	return 0;
}
