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

/*

ex) dp(2,3) = dp(2,2) + dp(1,3)

	3개를 뽑아 2를 만드는 경우의수  = 
		(2개를 뽑아 2를 만드는 경우의 수에 추가로 0 뽑기) +        ex) [2, 0] -> [2, 0, 0]
		(3개를 뽑아 1을 만드는 경우의 수에 크기 1늘리기)		   ex) [1, 0, 0] -> [1, 0, 1]

	중복 제거를 위해 위를 실행할 때는 무조건 0은 마지막에 추가하고, 1늘리는 건 마지막 수에 대해서만
*/