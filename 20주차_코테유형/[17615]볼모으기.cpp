/* 볼 모으기 */

#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, i, count, flag, result;
	string ball;

	cin >> N;
	cin >> ball;

	// 빨간공 이동
	// 왼쪽
	count = 0;
	flag = 0;
	if (ball[0] == 'B') flag = 1;
	for (i = 1; i < N; i++) {
		if (ball[i] == 'R' && flag == 1) count++;
		else if (ball[i] == 'B') flag = 1;
	}
	result = count;
	// 오른쪽
	count = 0; 
	flag = 0;
	if (ball[N-1] == 'B') flag = 1;
	for (i = N - 2; i >= 0; i--) {
		if (ball[i] == 'R' && flag == 1) count++;
		else if (ball[i] == 'B') flag = 1;
	}
	result = min(count, result);
	// 파란공 이동
	// 왼쪽
	count = 0;
	flag = 0;
	if (ball[0] == 'R') flag = 1;
	for (i = 1; i < N; i++) {
		if (ball[i] == 'B' && flag == 1) count++;
		else if (ball[i] == 'R') flag = 1;
	}
	result = min(count, result);

	// 오른쪽
	count = 0; 
	flag = 0;
	if (ball[N-1] == 'R') flag = 1;
	for (i = N - 2; i >= 0; i--) {
		if (ball[i] == 'B' && flag == 1) count++;
		else if (ball[i] == 'R') flag = 1;
	}
	result = min(count, result);
	cout << result;
}