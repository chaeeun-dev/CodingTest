// 회의실 배정(백준, 정렬, 그리디)
// https://www.acmicpc.net/problem/1931

#include <iostream>

using namespace std;

int main(void)
{
	// N: 회의 수
	int N;
	cin >> N;

	// 회의 끝나는 시간, 회의 시작 시간의 2가지 기준으로 오름차순 정렬
	// 정렬의 기준을 2가지로(우선순위)
	// 첫 번째 회의는 무조건 배정
	// 앞 회의의 끝나는 시간 설정
	//i = 1 ~ N에 대해 i 번째 회의 시작 시간이 이전 회의 끝나는 시간보다 크거나 같으면 배정

	// * 정렬의 기준이 여러 개일 때!!! 정렬을 어떻게 할지 알아야 함.
	for (int i = 0; i < N; ++i)
	{

	}
}