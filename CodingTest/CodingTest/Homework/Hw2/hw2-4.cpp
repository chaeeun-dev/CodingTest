// 균형 잡힌 영양소 (TUKorea, 조합) 
// http://210.93.60.51/problem/0099

#include <iostream>
#include <vector>
using namespace std;

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
		for (int i = 0; i < lst.size() - n + 1/*전체 - 뽑을 개수 + 1 => 첫 번째 카드 제한*/; ++i)
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

	vector<vector<int>> food(N, vector<int>(4));	// [탄, 단, 지, 열량]

	for (int i = 0; i < N; ++i)
	{
		// 입력
		cin >> food[i][0] >> food[i][1] >> food[i][2];

		// 열량 저장
		food[i][3] = food[i][0] * 4 + food[i][1] * 4 + food[i][2] * 9;
	}

	// 기준치 입력
	vector<int> standard(4);
	cin >> standard[0] >> standard[1] >> standard[2] >> standard[3];

	// 음식의 조합을 만들 food의 행 인덱스
	vector<int> idx;
	for (int i = 0; i < N; ++i)
	{
		idx.push_back(i);
	}

	int result = 0;
	for (int i = 1; i <= 3; ++i)		// 1~3개의 조합을 순서대로 뽑음
	{
		for (vector<int> v : combi(idx, i))	// 조합을 하나씩 살펴봄
		{
			vector<int> sum(4);	// 초기화

			for (int id : v)
			{
				sum[0] += food[id][0];
				sum[1] += food[id][1];
				sum[2] += food[id][2];
				sum[3] += food[id][3];
			}

			// 조건 검사
			if (sum[0] <= standard[0] && sum[1] >= standard[1]
				&& sum[2] <= standard[2] && sum[3] <= standard[3])
			{
				result++;
			}
		}
	}

	cout << result;
}