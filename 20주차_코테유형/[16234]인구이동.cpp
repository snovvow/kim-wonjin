/* 인구 이동 */

#include <iostream>
#include <cstring>

using namespace std;

int N, L, R, country, sum, result, cnt;
int popul[50][50];
bool visited[50][50];
bool unionn[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void logic(int i, int j)
{
	visited[i][j] = true;

	for (int idx = 0; idx < 8; idx++)
	{
		int next_i = i + dy[idx];
		int next_j = j + dx[idx];

		if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N)      // 인덱스 범위 체크	
			if (visited[next_i][next_j] == false && abs(popul[next_i][next_j] - popul[i][j]) >= L && abs(popul[next_i][next_j] - popul[i][j]) <= R) {
				country++;
				sum += popul[next_i][next_j];
				unionn[next_i][next_j] = true;
				logic(next_i, next_j);
			}
	}
}

int main() {

	int i, j, k, r;
	cin >> N >> L >> R;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> popul[i][j];
		}
	}
	while (1) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (visited[i][j] == false)
				{
					logic(i,j);
					if (country > 0) { // 맨처음 시작한 나라 처리
						country++;
						sum += popul[i][j];
						unionn[i][j] = true;
					
						for (k = 0; k < N; k++)
							for (r = 0; r < N; r++) {
								if (unionn[k][r]) {
									popul[k][r] = sum / country;
								}
							}
						cnt++;
					}
					country = 0; 
					sum = 0;
					memset(unionn, 0, sizeof(unionn));
				}
			}
		}
		result++;
		if (cnt == 0) break;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	cout << result - 1;
}