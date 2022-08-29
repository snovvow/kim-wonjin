/* 소가 길을 건너간 이유 5 */

#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
	int N, K, B, i, b, num, min_, result;
	cin >> N >> K >> B;

	bool broken[N + 1];
	memset(broken, 0, sizeof(broken));

	for (i = 0; i < B; i++)
	{
		cin >> b;
		broken[b] = 1;
	}

	num = 0;
	min_ = 0;
	result = INT_MAX;
	for (i = 1; i < K + 1; i++)
	{
		if (broken[i] == 1)
				min_++;
	}
	for (i = K + 1; i < N + 1; i++)
	{	
		if (broken[i] == 1) min_++;
		if (broken[i - K] == 1) min_--;
		if (result > min_) result = min_;
	}
	cout << result;
}