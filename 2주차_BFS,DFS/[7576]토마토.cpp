/* 토마토 */

// BFS

#include <iostream>
#include <queue>

using namespace std;

struct tomato
{
	int status;
	int day;  
};

int M, N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct tomato tomato[1000][1000];
queue<pair<int, int> > q;

int logic()
{
	int i ,x, y, next_x, next_y, result;

	while (!q.empty())
	{
		y = q.front().first;     // i
		x = q.front().second;    // j
		result = tomato[y][x].day;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next_y = y + dy[i];
			next_x = x + dx[i];
			if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M)  // 인덱스 범위 체크
				if (tomato[next_y][next_x].status == 0 && tomato[next_y][next_x].day == -1)  // 방문하지 않은 안익은 토마토
			 	{
					 tomato[next_y][next_x].day = tomato[y][x].day + 1;
					 q.push(make_pair(next_y, next_x));
				 }
		}
	}
	return result;
}

int main()
{
	int i, j, result;

	cin >> M >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> tomato[i][j].status;
			tomato[i][j].day = -1;
			if (tomato[i][j].status == 1)  // 첨부터 익어있던 토마토
			{	
				q.push(make_pair(i, j));
				tomato[i][j].day = 0;
			}
		}
	}
	result = logic();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j].status != -1 && tomato[i][j].day == -1)  // 방문하지 못한 토마토가 있는 경우 -1 출력
			{
				cout << "-1";
				return (0);
			}
		}
	}
	cout << result;
}
