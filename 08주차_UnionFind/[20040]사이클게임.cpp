/* 사이클 게임 */
#include <iostream>

using namespace std;

int Parent[500000];

int Find(int x)
{
	if (x == Parent[x])
		return x;
	return Parent[x] = Find(Parent[x]);
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y)
		return (1);
	Parent[y] = x;
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i, n, m, x, y;

	cin >> n >> m;
	for (i = 0; i < n; i++)
		Parent[i] = i;

	for (i = 1; i < m + 1; i++)
	{
		cin >> x >> y;
		if (Union(x, y) == 1)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	
}