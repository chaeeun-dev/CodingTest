// 균형 잡힌 영양소 (TUKorea, 조합) 
// http://210.93.60.51/problem/0099

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combi(vector<int>lst, int n)
{
	vector<vector<int>> ret;

	if (n == 1)
	{
		for (int i : lst)
		{
			vector<int> temp = { i };
			ret.push_back(temp);
		}
	}
	else if (n > 1)
	{
		for (int i = 0; i < lst.size() - n + 1; ++i)
		{
			vector<int> slice(lst.begin() + i + 1, lst.end());
			for (vector<int> temp : combi(slice, n - 1))
			{
				vector<int> temp2 = { lst[i] };
				temp2.insert(temp2.end(), temp.begin(), temp.end());
				ret.push_back(temp2);
			}
		}
	}

	return ret;
}

int main(void)
{
	int N;
	cin >> N;

	vector<vector<int>> food;	// 음식 N개<탄, 단, 지>
	for (int i = 0; i < N; ++i)
	{
		std::cin >> food[i][1] >> food[i][2] >> food[i][3];
	}

	vector<int> standard(4, 0);	// 탄수, 단백질, 지방, 열량
	cin >> standard[0] >> standard[1] >> standard[2] >> standard[3];

	// 1~N 개를 뽑는 조합의 기준치 & 열량 확인하기
	for (int i = 1; i <= N; ++i)
	{
		combi(foodOrder, i)
	}
}