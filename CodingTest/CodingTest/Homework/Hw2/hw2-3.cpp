// 자산증감 (TUKorea, 구현) 
// http://210.93.60.51/problem/0067

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	string str;

	cin >> n >> str;
	
	int index = 0;
	int maxIndex = 0, minIndex = 0;
	vector<int> rowIndex(n);
	
	for (size_t i = 0; i < str.length(); ++i)
	{
		// 첫 날
		if (i == 0)
		{
			rowIndex[i] = index;
		}
		else
		{
			// 나머지 날
			// -는 위로 상향, +는 아래로 하향
			if (str[i - 1] == '+')
			{
				if (str[i] == '+' || str[i] == '=')
					index--;
			}
			else if (str[i - 1] == '-')
			{
				if (str[i] == '-')
					index++;
			}
			else if (str[i - 1] == '=')
			{
				if (str[i] == '-')
					index++;
			}
		}
		maxIndex = max(maxIndex, index);
		minIndex = min(minIndex, index);
		rowIndex[i] = index;
	}

	// 인덱스를 0을 기준으로 맞춤
	for (int& i : rowIndex)
	{
		i -= minIndex;
	}

	// 몇 행인지?
	if (minIndex < 0)
	{
		maxIndex -= minIndex;
		minIndex += minIndex * (-1);
	}

	int row = maxIndex - minIndex + 1;

	// char 행렬 생성 및 초기화
	vector<vector<char>> result(row, vector<char>(n, '.'));
	// 값 채우기
	for (size_t i = 0; i < n; ++i)
	{
		if (str[i] == '+')
			result[rowIndex[i]][i] = '/';
		else if (str[i] == '-')
			result[rowIndex[i]][i] = '\\';
		else if (str[i] == '=')
			result[rowIndex[i]][i] = '_';
	}

	// 출력
	for (int i = 0; i < row; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			cout << result[i][k];
		}
		cout << endl;
	}
}