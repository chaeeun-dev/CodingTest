// 행렬 게임(TUKorea, 구현) 
// http://210.93.60.51/problem/0063

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
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

			cout << M[i][j] << ' ';
		}
		cout << "\n";
	}

	// 오른쪽 회전 행렬
	cout << 'R' << endl;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 2; j >= 0; --j)
		{
			cout << M[j][i] << ' ';
		}
		cout << '\n';
	}

	//왼쪽 회전 행렬
	// 하는 중!!!!
	cout << 'L' << endl;
	for (int i = 4; i >= 0; --i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			cout << M[j][i] << ' ';
		}
		cout << '\n';
	}

}