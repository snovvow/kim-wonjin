/* 0 만들기 */

#include <iostream>
#include <cmath>

using namespace std;

char fun[3] = {' ', '+', '-'};
char exps[9];
int N;

void check() {
	int i, result, number;
	result = 0;
	number = 1;
	for (i = -1; i < N - 1; i++) {
		if (number == 1 && (i == N - 2 || exps[i+1] != ' ')) result = 1;
		else if (exps[i] == '+' && (i == N - 2 || exps[i+1] != ' ')) {
			result += number;
		}
		else if (exps[i] == '-' && (i == N - 2 || exps[i+1] != ' ')) {
			result -= number;
		}
		else {
			int bc = 0;
			int j = i +1;

			while (exps[j++] == ' ')
				bc++;
			if (exps[i] == '-') {
				while (bc--) {
					result = result - (number++) * pow(10, bc+1);
				}
				result -= number;
			}
			else {
				while (bc--) {
					result = result + (number++) * pow(10, bc+1);
				}
				result += number;
			}
			i = j-2;
		}
		number++;
	}
	if (result == 0)
	{
		for (int k = 1; k < N; k++) {
			cout << k;
			cout << exps[k-1];
		}
		cout << N << '\n';
	}
	
}

void Backtrack(int num)
{
	int i;

	if (num == N - 1) {
		check();
	}
	else 
	{
		for (i = 0; i < 3; i++)
		{
			exps[num] = fun[i];
			Backtrack(num + 1);
		}
	}
}

int main()
{
	int t, i;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> N;
		Backtrack(0);
		cout << '\n';
	}
}