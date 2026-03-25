// 블랙잭(백준, Bruteforce, 조합)
// https://www.acmicpc.net/problem/2798
// C++은 Combination 라이브러리가 없으므로, 재귀함수 구현해야 함

#include <iostream>
#include <vector>
#include <numeric>	// accumulate
using namespace std;

// lst에서 n개를 뽑는 모든 조합의 경우를 2차원 벡터로 반환
vector<vector<int>> combi(vector<int>lst, int n)
{
	vector<vector<int>> ret;

	if (n > lst.size())
		return ret;

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
				vector<int> temp2 = {lst[i]};
				temp2.insert(temp2.end(), temp.begin(), temp.end());
				ret.push_back(temp2);
			}
		}
	}

	return ret;
}

int main(void)
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> cards;

	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		cards.push_back(t);
	}

	int answer = 0;
	for (vector<int> c : combi(cards, 3))
	{
		int acc = accumulate(c.begin(), c.end(), 0);
		if (acc <= M)
			answer = max(answer, acc);	// 최대값 갱신
	}

	cout << answer;
}