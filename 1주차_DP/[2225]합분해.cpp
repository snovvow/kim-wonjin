#include <iostream>
#include <cstring>
#define div 1000000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K, i, j;

	cin >> N >> K;
	int dp[N + 1][K + 1];         //  dp[i][j] = 숫자 j개 뽑아서 i 만드는 경우의 수
	
	bzero(dp, sizeof(dp));

	dp[0][0] = 1;                 //  숫자 0개 뽑아서 0 만들기

	for (j = 0; j < K + 1; j++)
		dp[0][j] = 1;             //  숫자 j개 뽑아서 0 만들기 (다 0 으로만)
	
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < K + 1; j++)
		{
			dp[i][j] = (dp[i - 1][j] % div) + (dp[i][j - 1] % div); 
		}
	}
	cout << dp[N][K] % div;
}