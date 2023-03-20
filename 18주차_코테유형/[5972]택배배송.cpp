/* 택배 배송 */

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int main() 
{
	cin >> N >> M;
	int i, from, to, cow;
	vector<pair<int, int> > road[N + 1];
	for (i = 0; i < M; i++)
	{
		cin >> from >> to >> cow;
		road[from].push_back(make_pair(to, cow));
		road[to].push_back(make_pair(from, cow));
	}

	int shortest[N + 1];
	// memset 왜 안댐??
	// The second parameter to memset() is a single byte. 
	// memset() does not fill the specified area of memory with ints, but with single bytes.
	// "int값을 16진수로 나타냈을 때 동일한 바이트 패턴이 4번 반복되는 값" 만 가능
	for (i = 0; i < N + 1; i++) shortest[i] = INT_MAX;

	int cur, next, cur_cow, next_cow;
	priority_queue<pair<int, int>, vector<pair<int,int> >, greater <pair<int,int> > > pq;
	shortest[1] = 0;
	pq.push(make_pair(1, 0));
	while (!pq.empty())
	{
		cur = pq.top().first;
		cur_cow = pq.top().second;
		pq.pop();
		for (i = 0; i < road[cur].size(); i++)
		{
			next = road[cur][i].first;
			next_cow = road[cur][i].second;
			if (shortest[next] > shortest[cur] + next_cow)
			{
				shortest[next] = shortest[cur] + next_cow;
				pq.push(make_pair(next, next_cow));
			}
		}
	}
	cout << shortest[N];
}