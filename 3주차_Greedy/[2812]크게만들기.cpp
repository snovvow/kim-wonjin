/* 크게 만들기 */

#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int main()
{
	int N, K, num, i, tmp;
	deque<int> dq;

	cin >> N >> K;
	num = N - K;

	for (i = 0; i < N; i++)
	{
		scanf("%1d", &tmp);

		if (dq.empty())
			dq.push_back(tmp);
		else
		{
			while (!dq.empty() && dq.back() < tmp && num - dq.size() < N - i)    // 마지막 조건 : 남은 자리 수 < 남은 숫자 
				dq.pop_back();
			dq.push_back(tmp);
		}
	}

	for (i = 0; i < num; i++)
		cout << dq[i];
}