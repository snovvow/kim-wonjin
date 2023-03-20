/* 소셜 네트워킹 어플리케이션 */

#include <iostream>

using namespace std;

int Parent[1000001];

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

	int t, test_case, i, n, k, a, b, m, u, v;

	cin >> test_case;
	for (t = 0; t < test_case; t++)
	{
		cin >> n >> k;
		for (i = 1; i < n + 1; i++)
			Parent[i] = i;

		for (i = 0; i < k; i++)
		{
			cin >> a >> b;
			Union(a, b);
		}
		cout << "Scenario " << t + 1  << ':' << '\n';
		cin >> m;
		for (i = 0; i < m; i++)
		{
			cin >> u >> v;
			if (Find(u) == Find(v))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		if (t != test_case - 1)
			cout << '\n';
	}

}