/* 섬의 개수 */

// DFS 풀이

#include <iostream>
#include <cstring>

using namespace std;

bool map[50][50];
bool visited[50][50];
int w, h, result;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};    // 다방향 재귀 시 dx dy 설정해주는게 실수 방지에 좋음 + 간결한 코드

void logic(int i, int j)
{
	visited[i][j] = true;

	for (int idx = 0; idx < 8; idx++)
	{
		int next_i = i + dy[idx];
		int next_j = j + dx[idx];

		if (next_i >= 0 && next_i < h && next_j >= 0 && next_j < w)      // 인덱스 범위 체크	
			if (visited[next_i][next_j] == false && map[next_i][next_j] == 1)
				logic(next_i, next_j);
	}
}

int main()
{
	int i, j;
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		/* 초기화 */
		bzero(map, sizeof(map));
		bzero(visited, sizeof(visited));
		result = 0;

		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				cin >> map[i][j];

		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (visited[i][j] == false && map[i][j] == 1)
				{
					logic(i,j);
					result++;
				}
		cout << result << '\n';
	}
}