/* 여러분의 다리가 되어 드리겠습니다! */

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
	int i, N, x, y;

	cin >> N;
	for (i = 1; i < N + 1; i++)
		Parent[i] = i;

	for (i = 1; i < N - 1; i++)
	{
		cin >> x >> y;
		Union(x, y);
	}

	cout << 1 << ' ';
	int root = Find(1);

	for(i = 2; i < N + 1; i++)
	{
		if (root != Find(i))
		{
			cout << i;
			break;
		}
	}
}