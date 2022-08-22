/* 러버덕을 사랑하는 모임 */

#include <iostream>
#include <cstring>

using namespace std;

int N, P, E;
int x[20];
int y[20];
bool pick[20];
int sum_x, sum_y;

void print_result()
{
	int i;
	int n = 0;
	int result[P];

	E  -= sum_x;

	for (i = 0; i < N; i++)
	{
		if (pick[i] == 0)
		{
			cout << 0 << ' ';
			continue;
		}
		if (y[i] - x[i] <= E)
		{
			E -= (y[i] - x[i]);
			cout << y[i] << ' ';
		}
		else
		{
			cout << x[i] + E << ' ';
			E = 0;
		}

	}
	exit(0);
}

void Backtrack(int cur, int num)
{
	int i;

	if (num == P)
	{
		for (i = 0; i < N; i++)
		{
			if (pick[i] == 1)
			{
				sum_x += x[i];
				sum_y += y[i];
			}
		}
		if (sum_x <= E && sum_y >= E)
			print_result();
		num = 0;
		sum_x = 0;
		sum_y = 0;
	}
	else
	{
		for (i = cur; i < N; i++)
		{
			pick[i] = 1;
			Backtrack(i + 1, num + 1);
			pick[i] = 0;
		}
	}
}

int main()
{
	int i;
	cin >> N >> P >> E;

	for (i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	Backtrack(0, 0);
	cout << -1;
}