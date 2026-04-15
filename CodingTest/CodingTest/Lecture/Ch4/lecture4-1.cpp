// 두 배열의 원소 교체
// A 배열 오름차순 정렬, B 배열 내림차순 정렬해서 swap

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// n: 원소 개수, k: 최대 바꿔치기 개수
	int n, k;
	cin >> n, k;

	vector<int> a(n, 0);
	vector<int> b(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	// 교체
	for (int i = 0; i < k; ++i)
	{
		if (a[i] < b[i])
		{
			// 바꿔치기
		}
		else
			break;
	}

}