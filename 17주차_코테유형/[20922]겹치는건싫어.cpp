/* 창고 다각형 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

	int N, K, i, j;
	cin >> N >> K;
	int num[N + 1];
	int count[200001];
	memset(num, 0, sizeof(num));
	memset(count, 0, sizeof(count));

	for (i = 0; i < N; i++)
		cin >> num[i];
	
	i = 0;
	j = 1;
	int result = 1;
	int max_ = 1;
	count[num[0]]++;

	while (num[j] != 0) {
		count[num[j]]++;
		if (count[num[j]] <= K) {
			result++;
		} else {
			if (max_ < result) max_ = result;
			while (result != 0) {
				count[num[i]]--;
				i++;
				result--;
				if (count[num[j]] <= K) break;
			}
			result++;
		}
		j++;
	}
	if (max_ < result) max_ = result;
	cout << max_;
}