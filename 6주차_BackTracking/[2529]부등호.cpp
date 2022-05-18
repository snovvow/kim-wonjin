/* 부등호 */
#include <iostream>
#include <cstring>

using namespace std;

int k;
char sign[9];
bool used[10];
int num[10];
int max_[10];
int min_[10];

void check_max(int *num)
{
	int i;
	for (i = 0; i < k + 1; i++)
	{
		if (num[i] > max_[i])
		{
			memcpy(max_, num, sizeof(int) * (k + 1));
			break;
		}
		else if (num[i] < max_[i])
			break;
	}
}

void check_min(int *num)
{
	int i;
	for (i = 0; i < k + 1; i++)
	{
		if (num[i] < min_[i])
		{
			memcpy(min_, num, sizeof(int) * (k + 1));
			break;
		}
		else if (num[i] > min_[i])
			break;
	}
}

void backTrack(int cur, int n)
{
	int i;
	if (n == k + 1)
	{
		check_max(num);
		check_min(num);
	}
	else
	{
		for (i = 0; i < 10; i++)   // 뽑는거면 cur부터 순서가 중요하면 0부터
		{
			if (used[i] == true)
				continue;
			num[n] = i;
			used[i] = true;
			if (n == 0)
				backTrack(i + 1, n + 1);
			else if (sign[n - 1] == '<' && num[n - 1] < num[n])
				backTrack(i + 1, n + 1);
			else if (sign[n - 1] == '>' && num[n - 1] > num[n])
				backTrack(i + 1, n + 1);
			used[i] = false;
		}
	}
}

int main()
{
	int i;
	cin >> k;
	for (i = 0; i < k; i++)
		cin >> sign[i];
	memset(min_, 9, sizeof(int) * (k + 1));
	backTrack(0, 0);
	for (i = 0; i < k + 1; i++)
		cout << max_[i];
	cout << '\n';
	for (i = 0; i < k + 1; i++)
		cout << min_[i];
}