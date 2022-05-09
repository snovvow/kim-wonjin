/* 소문난 칠공주 */

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char girl[5][5];
bool gongju[25];
bool gongju_[5][5];
bool visit[5][5];
int result;
int cnt;

void DFS(int i, int j)
{
	if (visit[i][j] == 0)
	{
		visit[i][j] = 1;
		cnt++;
		
		if (j < 4 && gongju_[i][j + 1] == 1)
			DFS(i, j + 1);
		if (j > 0 && gongju_[i][j - 1] == 1)
			DFS(i, j - 1);
		if (i < 4 && gongju_[i + 1][j] == 1)
			DFS(i + 1, j);
		if (i > 0 && gongju_[i - 1][j] == 1)
			DFS(i - 1, j);
	}
}

void Backtrack(int cur, int n, int s, int y_)
{
	int i, j, x, y, flag;

	if (n == 7)
	{
		memset(gongju_, 0, sizeof(gongju_));
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		flag = 0;
		if (s < 4)	// 이다솜파 4명 미만
			return;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				gongju_[i][j] = gongju[i * 5 + j];
				if (flag == 0 && gongju_[i][j] == 1)
				{
					y = i;
					x = j;
					flag = 1;
				}
			}
		}
		DFS(y, x);
		if (cnt != 7) // 7명 자리 인접 여부
			return;
		result++;
	}
	else
	{
		for (i = cur; i < 25; i++)
		{
			gongju[i] = true;
			if (girl[i / 5][i % 5] == 'S')
				Backtrack(i + 1, n + 1, s + 1, y_);
			else
				Backtrack(i + 1, n + 1, s, y_ + 1);
			gongju[i] = false;
		}
	}
}

int main()
{
	int i, j;
	char endl;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			scanf("%1c", &girl[i][j]);
		scanf("%1c", &endl);
	}
	Backtrack(0, 0, 0, 0);
	cout << result;
}


