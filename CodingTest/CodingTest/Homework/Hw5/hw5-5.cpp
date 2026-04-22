// 어두운 굴다리(TUKorea, 백준, 이분탐색)
// http://210.93.60.51/problem/0180
// https://www.acmicpc.net/problem/17266

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> pos;

bool check(int mid)
{
	int p = 0;	// 굴다리 시작 위치로 초기화

	for (int lightPos : pos)	// 가로등의 각 위치를 가져와서
	{
		if (lightPos - mid > p)	// 현재 가로등 왼쪽 비추는 범위가 p를 포함하지 않으면
			return false;

		p = lightPos + mid;		// 현재 가로등 오른쪽이 비추는 범위로 p 설정
	}

	if (p >= N)	// 마지막 가로등 오른쪽 비추는 범위가 N을 포함해야 함
		return true;
	else
		return false;
}

int main(void)
{
	// N 굴다리 거리, M 가로등 개수
	cin >> N >> M;

	// 가로등의 위치
	pos.assign(M, 0);
	for (int i = 0; i < M; ++i)
	{
		cin >> pos[i];
	}
	
	int start = 1;
	int end = N;
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;	// 중간 값
		if (check(mid))
		{
			answer = mid;
			end = mid - 1;	// 왼쪽 범위 탐색
		}
		else
		{
			start = mid + 1;	// 오른쪽 범위 탐색
		}
	}

	cout << answer;
	return 0;
}