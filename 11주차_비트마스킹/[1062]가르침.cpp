/* 가르침 */

#include <iostream>

using namespace std;

int N, K;
string words[50];
bool ascii[123];
int result, min_;

void check()
{
	int i, j, flag;

	for (i = 0; i < N; i++)
	{
		flag = 1;
		for(j = 0; j < words[i].length(); j++)
		{
			if (ascii[words[i][j]] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			result++;
	}
	if (min_ < result)
		min_ = result;
	result = 0;
}

void Backtrack(int cur, int num)
{
	int i;

	if (num == K - 5)
	{
		check();
		num = 0;
	}
	else
	{
		for (i = cur; i <= 'z'; i++)
		{
			if (i == 'a' || i == 'n' || i == 't' || i == 'i' || i == 'c')
				continue;
			ascii[i] = 1;
			Backtrack(i + 1, num + 1);
			ascii[i] = 0;
		}
	}
}

int main()
{
	int i;
	cin >> N >> K;

	for (i = 0; i < N; i++)
		cin >> words[i];

	if (K < 5)
	{
		cout << 0;
		return 0;
	}

	ascii['a'] = 1; 
	ascii['n'] = 1;
	ascii['t'] = 1;
	ascii['i'] = 1;
	ascii['c'] = 1;

	if (K == 5)
		check();
	else
		Backtrack('b', 0);
	
	cout << min_;
}