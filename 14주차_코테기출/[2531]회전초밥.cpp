/* 회전 초밥 */

#include <iostream>
#include <cstring>

using namespace std;

bool sushi[3001];
int N, d, k, c;
int max_;

int main()
{
    cin >> N >> d >> k >> c;
	int i, j;
	int belt[N];
	memset(belt, 0, sizeof(belt));

	for (i = 0; i < N; i++)
		cin >> belt[i];
	
	for (i = 0; i < N; i++)
	{
		memset(sushi, 0, sizeof(sushi));
		sushi[c] = true;
		int count = 1;
		for (j = i; j < i + k; j++)
		{	
			int num = j;
			if (j >= N) num = j - N; 
			if (sushi[belt[num]] == false) 
			{
				sushi[belt[num]] = true;
				count++;
			}
			if (max_ < count) max_ = count;
		}
	}
	cout << max_;
}