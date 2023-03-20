/* 소가 길을 건너간 이유 3 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct cow
{
	int arrive;
	int check;
} cow;

bool cmp(cow a, cow b)
{
	return (a.arrive < b. arrive);
}

int main()
{
	int N, i, time;
	
	cin >> N;
	cow cow[N];

	for (i = 0; i < N; i++)
		cin >> cow[i].arrive >> cow[i].check;

	sort(cow, cow + N, cmp);   // 도착 시간 순으로 정렬

	time = 0;
	for (i = 0; i < N; i++)
	{
		if (time < cow[i].arrive)   // 웨이팅 안 한 소
			time = cow[i].arrive;
		time += cow[i].check;
	}
	cout << time;
}