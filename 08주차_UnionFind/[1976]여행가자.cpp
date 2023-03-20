/* 여행 가자 */

#include <iostream>

using namespace std;

int Parent[300001];

int Find(int x)
{
	if (x == Parent[x])
		return x;
	return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y)
		return;
	Parent[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i, j, N, M, c, x, y, t;

	cin >> N >> M;
	for (i = 1; i < N + 1; i++)
		Parent[i] = i;

	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < N + 1; j++)
		{
			cin >> c;
			if (c)
				Union(i, j);
		}
	}

	cin >> t;
	int group = Find(t);
	for (i = 2; i < M + 1; i++)
	{
		cin >> t;
		if (Find(t) != group)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}