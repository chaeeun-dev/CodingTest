#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	// 회원 점수
	// 회장 입력
	vector<int> firstInput(N, 0);
	// 회원 입력
	vector<int> secondInput(N, 0);

	// 회장 입력
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		firstInput[input - 1] += N - i;	// input 값이 회원의 번호임
	}

	// 회원 입력
	vector<int> score(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> score[i];
	}

	for (int i = 0; i < N; ++i)
	{
		// 최대 점수의 index 구함
		int maxIndex = max_element(score.begin(), score.end()) - score.begin();

		// secondInput에 점수 넣기
		secondInput[maxIndex] = N - 1;

		// 최대 점수를 음수 값으로 초기화
		score[maxIndex] = - 10;
	}

	// 총점
	vector<int> sumScore(N, 0);
	for (int i = 0; i < N; ++i)
	{
		sumScore[i] = firstInput[i] + secondInput[i];
	}

	// 점수 내림차순 정렬
	vector<int> sortScore = sumScore;
	sort(sortScore.begin(), sortScore.end());

	for (int i = 0; i < N; ++i)
	{
		// i. kod Index (index에 해당하는 점수)
		int index = find(sumScore.begin(), sumScore.end(), sortScore[i]) - sumScore.begin();
		cout << "kod" << index << " " << sortScore[i] << endl;
	}
}