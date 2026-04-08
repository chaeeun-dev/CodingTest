// 알파벳(백준, DFS재귀, 백트레킹, 비트마스킹)
// https://www.acmicpc.net/problem/1987
// 시간 제한이 타이트한 문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> board;
vector<bool> visited(26, false);
int maxDistance = 0;
int R, C;

// 상 하 좌 우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

// DFS 재귀, 백트레킹, preorder traversal, node -> left subtree -> right subtree
void DFS_Rec(int r, int c, int dist)
{
	// 최댓값이라면 끝
	if (dist == 26)
	{
		maxDistance = 26;
		return;
	}
	maxDistance = max(maxDistance, dist);	// 최대 거리 갱신

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr < R && nc >= 0 && nc < C)
		{
			if (!visited[board[nr][nc]])
			{
				visited[board[nr][nc]] = true;	// 방문 처리
				DFS_Rec(nr, nc, dist + 1);
				visited[board[nr][nc]] = false;	// 백트레킹 - 이전 방문 표시 해제
			}
		}
	}
}

int main(void)
{

	cin >> R >> C;

	board.assign(R, vector<int>(C));

	// 입력
	for (int i = 0; i < R; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < C; ++j)
		{
			board[i][j] = str[j] - 'A';		// 입력 받을 때 ASCII 코드로 저장(매번 ord하는 것 방지)
		}
	}

	// [0][0]에서 시작
	visited[board[0][0]] = true;

	// DFS
	DFS_Rec(0, 0, 1);

	cout << maxDistance << endl;
}