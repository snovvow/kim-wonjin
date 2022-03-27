/* 벽 부수고 이동하기 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct spot
{

};

int main()
{
	int N, M, i , j, cur_i, cur_j;

	cin >> N >> M;
	int map[N][M];
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> map[i][j];

	queue<pair<int, int> > q;

	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		cur_i = q.front().first;
		cur_j = q.front().second;
		for (i = 0; i < 4; i++)
		{
			if (map[cur_i + dy[i]][cur_j + dx[i]] == )
		}
	}
	cout << '-1';
}