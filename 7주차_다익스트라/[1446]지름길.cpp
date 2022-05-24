/* 지름길 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct shortcut
{
	int start;
	int end;
	int len;
};

bool cmp(shortcut sc1, shortcut sc2)
{
	if (sc1.start == sc2.start)
		return (sc1.end < sc2.end);
	else
		return(sc1.start < sc2.start);
}

int main()
{
	int N, D, i, j;

	cin >> N >> D;
	int dp[N + 1][D + 1];
	struct shortcut sc[N + 1];
	memset(sc, 0, sizeof(sc));
	memset(dp, 0, sizeof(dp));

	for (i = 1; i < N + 1; i++)
		cin >> sc[i].start >> sc[i].end >> sc[i].len;

	sort(sc, sc + N + 1, cmp);

	for (j = 1; j < D + 1; j++)
	{
		dp[0][j] = j;
	}
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < D + 1; j++)
		{
			if (sc[i].end > j || sc[i].end - sc[i].start <= sc[i].len)
				dp[i][j] = dp[i - 1][j];
			else if (sc[i].end == j)
			{
				dp[i][j] = min(dp[i - 1][sc[i].start] + sc[i].len , dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = min(dp[i][sc[i].end] + j - sc[i].end , dp[i - 1][j]);
			}
		}
	} 
	
	cout << dp[N][D];
	

}