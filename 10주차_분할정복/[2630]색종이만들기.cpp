/* 색종이 만들기 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int map[128][128];
int count_[2];

void recursive(int len, int y, int x)
{
	int i, j;
	int flag = 0;
	bool color = map[y][x];
	for (i = y; i < y + len; i++)
	{
		for (j = x; j < x + len; j++)
		{
			if (map[i][j] != color)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		count_[color]++;
		return;
	}
	int next = len / 2;
	recursive(next, y, x);
	recursive(next, y + next, x);
	recursive(next, y, x + next);
	recursive(next, y + next, x + next);
}

int main()
{
	int i, j;

	cin >> N;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			cin >> map[i][j];
	}
	recursive(N, 0, 0);
	cout << count_[0] << '\n' << count_[1];
}