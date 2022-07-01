/* LCS (최장 공통 부분 수열) */

#include <iostream>

using namespace std;

int LCS[1001][1001];

int main()
{
	int asize, bsize, i, j;
	string a, b;
	
	cin >> a >> b;
	asize = a.size();
	bsize = b.size();

	for (i = 1; i < asize + 1; i++)
	{
		for (j = 1; j < bsize + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
	cout  << LCS[asize][bsize] << '\n';	

	return 0;
}