/* 이동하기 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, M, i, j;

	cin >> N >> M;
	int candy[N + 1][M + 1];
	int dp[N + 1][M + 1];

	bzero(candy, sizeof(candy));
	bzero(dp, sizeof(dp));

	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < M + 1; j++)
			cin >> candy[i][j];
	}

	dp[1][1] = candy[1][1];
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < M + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j])) + candy[i][j];
		}
	}
	cout << dp[N][M];
}