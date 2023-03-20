/* 진우의 달 여행 */

#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int N, M;
int map[7][7];
int dp[7][7][4];   // 마지막은 세가지 방향

int logic(int i, int j, int d)
{
    if(i == N)
    {
        return 0;
    }
    
    if(dp[i][j][d] != INT_MAX)
    {
        return dp[i][j][d];
    }
    
    if(d != 0 && j - 1 >= 0) // 왼쪽
    {
        dp[i][j][d] = logic(i + 1, j - 1, 0) + map[i][j];     
    } 
    
    // 중앙 
    if(d != 1)
    {
        dp[i][j][d] = min(dp[i][j][d], logic(i + 1, j, 1) + map[i][j]);    
    }
    
    // 오른쪽
    if(d != 2 && j + 1 < M)
    {
        dp[i][j][d] = min(dp[i][j][d], logic(i + 1, j + 1, 2) + map[i][j]); 
    } 

    return dp[i][j][d];
}
 
int main()
{
	int i, j;

	cin >> N >> M;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> map[i][j];
			
	}

	memset(dp, INT_MAX, sizeof(dp));
	int min_ = INT_MAX;

	for (j = 0; j < M; j++)
	{
		min_ = min(min_, logic(0, j, 3));
		cout << min_;
	}

	cout << min_;
}