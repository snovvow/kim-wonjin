#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, i, j;

	cin >> n >> k;
	int value[n + 1];
	int dp[k + 1];

	bzero(dp, sizeof(dp));

	for (i = 1; i < n + 1; i++)
		cin >> value[i];

	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < k + 1; j++)
		{
			if (value[i] == j)
				dp[j]++;
			else if (j > value[i])
				dp[j] += dp[j - value[i]];
		}
	}
	cout << dp[k];
}