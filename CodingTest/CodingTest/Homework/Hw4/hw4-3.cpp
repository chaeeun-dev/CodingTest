// 행렬 게임(TUKorea, 구현) 
// http://210.93.60.51/problem/0063

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// A 행, B 열
	int A, B;
	cin >> A >> B;

	vector<vector<int>> M(A, vector<int>(B, 0));

	// 벡터 초기화
	cout << 'M' << endl;
	int count = 0;
	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			M[i][j] = ++count;

			cout << M[i][j];

			if (j != B - 1)
				cout << ' ';
		}
		cout << "\n";
	}

	// 오른쪽 회전 행렬
	cout << 'R' << endl;
	for (int i = 0; i < B; ++i)
	{
		for (int j = A - 1; j >= 0; --j)
		{
			cout << M[j][i];

			if (j != 0)
				cout << ' ';
		}
		cout << '\n';
	}

	//왼쪽 회전 행렬
	cout << 'L' << endl;
	for (int i = B - 1; i >= 0; --i)
	{
		for (int j = 0; j <= A - 1; ++j)
		{
			cout << M[j][i];
			
			if (j != A - 1)
				cout << ' ';
		}
		cout << '\n';
	}

	// 전치행렬
	cout << 'T' << endl;
	for (int i = 0; i < B; ++i)
	{
		for (int j = 0; j < A; ++j)
		{
			cout << M[j][i];

			if (j != A - 1)
				cout << ' ';
		}

		if (i != B - 1)
			cout << "\n";
	}

	return 0;
}