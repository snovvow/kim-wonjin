/* 빙산 */

// DFS 풀이

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[300][300];
int new_map[300][300];
bool visited[300][300];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int i, int j)
{
	visited[i][j] = true;

	for (int idx = 0; idx < 4; idx++)
	{
		int next_i = i + dy[idx];
		int next_j = j + dx[idx];

		if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M)      // 인덱스 범위 체크	
			if (visited[next_i][next_j] == false && new_map[next_i][next_j] != 0)
				DFS(next_i, next_j);
	}
}

void melt()
{
	int i, j, idx, sea;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			sea = 0;
			for (idx = 0; idx < 4; idx++)
			{
				int next_i = i + dy[idx];
				int next_j = j + dx[idx];

				if (map[next_i][next_j] == 0)
					sea++;
			}
			new_map[i][j] -= sea;
			if (new_map[i][j] < 0)
				new_map[i][j] = 0;
		}
	}
}

int main()
{
	int i, j, cnt, year;

	year = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> map[i][j];
	memcpy(new_map, map, sizeof(map));
	
	while (1)
	{
		// 빙산 녹이기
		melt();
		year++;
		memcpy(map, new_map, sizeof(new_map));   

		// 빙산 개수 체크
		bzero(visited, sizeof(visited));
		cnt = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (new_map[i][j] != 0 && visited[i][j] == false)
				{
					if (cnt != 0)   // 섬 하나 더 발견
					{
						cout << year;
						return (0);
					}
					DFS(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0)   // 빙산 다 녹아서 섬 0개
		{
			cout << 0;
			return (0);
		}
	}
}