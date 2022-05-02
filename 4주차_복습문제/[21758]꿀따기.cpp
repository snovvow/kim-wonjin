/* 꿀 따기 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, i, tmp, res;

	cin >> N;
	vector<int> map(N);
	vector<int> sum(N);    // 누적합 배열

	tmp = 0;
	for (i = 0; i < N; i++)
	{
		cin >> map[i];
		tmp += map[i];
		sum[i] = tmp;
	}
	// 	벌통이 두 벌 가운데 있는 경우
	res = sum.back() - map.front() - map.back() + *max_element(map.begin(), map.end());  

	// 벌통이 두 벌 오른쪽에 있는 경우
	for(i = 1; i < N - 1; i++)
	{
		tmp = sum.back() - map.front() - map[i] + sum.back() - sum[i];
		if (tmp > res)
			res = tmp;
	}
	// 벌통이 두 벌 왼쪽에 있는 경우
		for(i = 1; i < N - 1; i++)
	{
		tmp = sum.back() - map.back() - map[i] + sum[i - 1];
		if (tmp > res)
			res = tmp;
	}
	cout << res;
}