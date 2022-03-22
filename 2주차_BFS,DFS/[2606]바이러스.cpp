/* 바이러스 */

// DFS 풀이

#include <iostream>

using namespace std;

bool connected[101][101];
bool visited[101];
int N, C, result;

int logic(int cur)
{
	int i;
	visited[cur] = true;
	for (i = 1; i < N + 1; i++)
		if (visited[i] == false && connected[cur][i] == true)
		{
			logic(i);
			result++;
		}
	return (result);
}

int main()
{
	int i, a, b;

	cin >> N >> C;
	for (i = 0; i < C; i++)
	{
		cin >> a >> b;
		connected[a][b] = true;
		connected[b][a] = true;
	}
	cout << logic(1);
}