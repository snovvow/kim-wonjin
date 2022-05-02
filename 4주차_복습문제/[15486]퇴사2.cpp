/* 퇴사 2 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, i;
	cin >> N;
	int day[N + 1];
	int pay[N + 1];
	int dp[N + 2];

	memset(dp, 0, sizeof(dp));

	for (i = 1; i < N + 1; i++)
		cin >> day[i] >> pay[i];
	
	for (i = N; i > 0; i--)
	{
		if (i + day[i] - 1 <= N) // 퇴사 전에 끝낼 수 있는가
		{
			dp[i] = max(dp[i + day[i]] + pay[i], dp[i + 1]);
		}
		else
			dp[i] = dp[i + 1];
	}
	cout << dp[1];
}