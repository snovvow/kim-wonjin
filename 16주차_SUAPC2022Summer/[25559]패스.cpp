/* 패스 */

#include <iostream>

using namespace std;

int main() {

	int N , i;
	cin >> N;

	int num = N;
	int odd = 1;
	int even = 2;

	if (N == 1)
	{
		cout << 1;
		exit(0);
	}

	if (N % 2 != 0) 
	{
		cout << -1;
		exit(0);
	}

	cout << N << ' ';
	for (i = 2; i < N + 1 ; i++)
	{
		if (i % 2 == 0)
		{
			cout << N - odd;
			odd += 2;
		}
		else
		{
			cout << even;
			even += 2;
		}
		cout << ' ';
	}
}