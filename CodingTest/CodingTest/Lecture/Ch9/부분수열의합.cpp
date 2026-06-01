#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> data = { 1,2,3,2,5 };

	int n = 5;
	int m = 5;

	int count = 0;
	int interval_sum = 0;
	int end = 0;

	// start를 차례로 증가
	for (int start = 0; start < n; ++start)
	{
		while (interval_sum < m && end < n)
		{
			interval_sum += data[end];
			end++;
		}
		if (interval_sum == m)	// 부분합이 m일 때 count 증가
			count++;

		interval_sum -= data[start];
	}

	cout << count << endl;

	return 0;
}
