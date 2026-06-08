// 두수의합 (TUKorea, 백준, 투포인터, 정렬)
// http://210.93.60.51/problem/0192

// 먼저 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;

	// 오름차순 정렬
	sort(arr.begin(), arr.end());

	// 두 개의 합이 x보다 작으면 end++, 크면 end--
	int start = 0, end = 1;	// end는 start보다 크다
	// ai + aj = x인 쌍의 개수
	int answer = 0;

	for (int start = 0; start < n-1; ++start)	// start = 0, 1, 2, ..., n - 2 <- end 자리를 위해 
	{
		// 두 포인터가 같다면(start와 end는 같으면 안 됨)
		if (start == end)
			end++;

		// if (a[start] + a[end] < X) -> end를 가능한 오른쪽으로 이동
		while (arr[start] + arr[end] < x && end < n - 1)
		{
			end++;
		}

		// if (a[start] + a[end] > X) -> end를 가능한 왼쪽으로 이동
		while (arr[start] + arr[end] > x && end > start + 1)
		{
			end--;
		}

		if (arr[start] + arr[end] == x)
			answer++;
	}
}