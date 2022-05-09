/* 넴모넴모 (Easy) */

#include <iostream>

using namespace std;

int N, M;
int map[25][25];
long long result;

int check(int y, int x)
{
	if (x < 1 || y < 1)
		return 0;
	if (map[y - 1][x - 1] && map[y][x - 1] && map[y - 1][x])
		return 1;
	return 0;
}

void BackTrack(int n)
{
	int i, j;
	int x = n / M;
	int y = n % M;

	if (n == N * M) 
	{
		result++;
	}
	else
	{
		map[y][x] = 1;
		if (check(y, x) == 0)
			BackTrack(n + 1);
		map[y][x] = 0;
		BackTrack(n + 1);
	}
}

int main()
{
	int i, j;
	cin >> N >> M;
	BackTrack(0);
	cout << result;
}