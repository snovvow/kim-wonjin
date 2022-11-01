/* 차의 개수 */

#include <iostream>

using namespace std;

int main() {

	int N, i, n;
	cin >> N;

	n = 1;
	cout << N * (N - 1) / 2 << '\n';
	for (i = 0; i < N; i++)
	{
		cout << n << ' ';
		n *= 2;
	}

	cout << '\n' << N - 1 << '\n';
	for (i = 1; i < N + 1; i++)
		cout << i << ' ';

	return 0;

}