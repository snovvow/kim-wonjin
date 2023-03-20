/* 민준이와 마산 그리고 건우 */

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

vector <pair<int, int> > adj[10001];
int min_[5001];

void dijkstra(int start)
{
	int cur, cur_cost, i, next, next_cost;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		cur = pq.top().second;
		cur_cost = -pq.top().first;

		pq.pop();

		if (min_[cur] < cur_cost)
			continue;    // 굳이 인접 노드들을 확인 할 필요가 없는 경우

		for (i = 0; i < adj[cur].size(); i++)
		{
			next = adj[cur][i].second;
			next_cost = cur_cost + adj[cur][i].first;
			if (min_[next] > next_cost)
			{
				min_[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}
}

int main()
{
	int V, E, P, i;
	int start, end, cost;
	int PtoM;

	cin >> V >> E >> P;
	for (i = 1; i < E + 1; i++)
	{
		cin >> start >> end >> cost;
		adj[start].push_back(make_pair(cost, end));
		adj[end].push_back(make_pair(cost, start));
	}
	for (i = 1; i < V + 1; i++)
		min_[i] = INT_MAX;

	min_[P] = 0;

	dijkstra(P);
	PtoM = min_[V];

	for (i = 1; i < V + 1; i++)
		min_[i] = INT_MAX;

	min_[1] = 0;
	dijkstra(1);
	
	if(min_[P] + PtoM == min_[V])
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
	return 0;
}