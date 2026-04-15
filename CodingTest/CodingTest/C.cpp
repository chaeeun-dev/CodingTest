#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = { 0, 0, -1, 1 };
int N;

vector<vector<char>> graph;
vector<vector<char>> graph2;

void DFS_Stack(int r, int c, char curChar, int n)
{
	stack<pair<int, int>> s;
	s.push({ r, c });
	graph[r][c] = ' ';

	while (!s.empty())
	{
		int cur_r = s.top().first;
		int cur_c = s.top().second;
		s.pop();	
		
		for (int i = 0; i < 4; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			if (nr >= 0 && nr < n && nc >= 0 && nc < n)
			{
				if (graph[nr][nc] == curChar)
				{
					graph[nr][nc] = ' ';
					s.push({ nr, nc });
				}
			}
		}
	}
}
void DFS_Stack2(int r, int c, char curChar, int n)
{
	stack<pair<int, int>> s;
	s.push({ r, c });
	graph2[r][c] = ' ';

	while (!s.empty())
	{
		int cur_r = s.top().first;
		int cur_c = s.top().second;
		s.pop();	
		
		for (int i = 0; i < 4; ++i)
		{
			int nr = cur_r + dr[i];
			int nc = cur_c + dc[i];

			if (nr >= 0 && nr < n && nc >= 0 && nc < n)
			{
				if (graph2[nr][nc] == curChar)
				{
					graph2[nr][nc] = ' ';
					s.push({ nr, nc });
				}
			}
		}
	}
}
int main(void)
{
	int N;
	cin >> N;

	graph.assign(N, vector<char>(N, ' '));

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = str[j];
		}
	}

	int count1 = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] == 'R')
			{
				count1++;
				DFS_Stack(i, j, 'R', N);
			}
			else if (graph[i][j] == 'G')
			{
				count1++;
				DFS_Stack(i, j, 'G', N);
			}
			else if (graph[i][j] == 'B')
			{
				count1++;
				DFS_Stack(i, j, 'B', N);
			}
		}
	}	
	
	int count2 = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] == 'R' || graph[i][j] == 'B')
			{
				count2++;
				DFS_Stack2(i, j, 'R', N);
			}
			else if (graph[i][j] == 'B')
			{
				count2++;
				DFS_Stack2(i, j, 'B', N);
			}
		}
	}

	cout << count1 << " " << count2;
}