/* 벽 부수고 이동하기 */

// BFS

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

// 좌표에 모든 정보를 담고 있음
struct spot
{
	int i;
	int j;
	bool break_wall;
	int move;
};

int main()
{
	int N, M, i , j, cur_i, cur_j, next_i, next_j, if_breaked, move;

	cin >> N >> M;

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	
	int map[N][M];
	bool visited[N][M][2];   // (벽 부순적 있음 / 벽 부순적 없음) 에 따른 방문 여부

	bzero(map, sizeof(map));
	bzero(visited, sizeof(visited));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	queue<spot> q;  // 좌표값을 담는 큐
	visited[0][0][0] = true;
	struct spot new_ = {0, 0, 0, 1};
	q.push(new_);

	while (!q.empty())
	{
		cur_i = q.front().i;  
		cur_j = q.front().j;  
		if_breaked = q.front().break_wall;
		move = q.front().move;
		q.pop();

		if (cur_i == N - 1 && cur_j == M - 1)  // 도착점 도달
		{
			cout << move;
			return (0);
		}

		for (i = 0; i < 4; i++)
		{
			next_i = cur_i + dy[i];
			next_j = cur_j + dx[i];

			if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M)  // 인덱스 범위 체크
			{
				if (visited[next_i][next_j][if_breaked] == false)    // 벽부숨 여부와 상관없이 방문 체크
				{
					if (map[next_i][next_j] == 0)      // 벽부숨 없이 갈 수 있는 곳
					{
						visited[next_i][next_j][if_breaked] = true;
						struct spot new_ = {next_i, next_j, if_breaked, move + 1};
						q.push(new_);
					}

					else if (if_breaked == 0 && map[next_i][next_j] == 1)    // 벽 부수고 지나가야 하는 곳
					{
						visited[next_i][next_j][1] = true;
						struct spot new__ = {next_i, next_j, 1, move + 1};
						q.push(new__);
					}
				}
			}
		}
	}
	cout << -1;
}