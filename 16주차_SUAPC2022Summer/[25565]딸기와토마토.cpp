/* 딸기와 토마토 */

#include <iostream>
#include <cstring>


using namespace std;

int main() {

	int N, M, K, i, j;
	cin >> N >> M >> K;

	int map[N + 1][M + 1];
	memset(map, 0, sizeof(map));

	for (i = 1; i < N + 1; i++)
		for (j = 1; j < M + 1; j++)
			cin >> map[i][j];

	int num = 0;
	for (i = 1; i < N + 1; i++)
	{
		for (j = 1; j < M + 1; j++)
		{
			int count = 0;
			if (map[i][j] == 1) 
			{
				bool right;
				if (j == M) right = 0; else right = map[i][j + 1];
				bool down;
				if (i == N) down = 0; else down = map[i + 1][j];

				if (right && down)
				{
					if (K == 2) {
						if (map[i + 1][j + 1])
						{
							cout << 0;
							exit(0);
						}
					}
					if (i + K - 1 <= N && j + K - 1 <= M && map[i + K - 1][j] && map[i][j + K - 1]) // 십자가
					{
						cout << 1 << '\n' << i << ' ' << j;
						exit(0);
					}
					else // 평행
					{
						cout << 0;
						exit(0);
					}


					
				} 
				else if (right)
				{
					if (j + K <= M && map[i][j + K]) // 한줄로 겹침 (완전 일치 x)
					{
						int n = j + K;
						
						while (n <= M && map[i][n])
							n++;
						int length = n - j;
						int count = K - (length - K);

						cout << count << '\n';
						j = j + ((length - count) / 2);
						while (count--)
							cout << i << ' ' << j++ << '\n';
						exit(0);
						
					}
					else // 해당 줄 십자가 찾기
					{
						int t;
					
						for (t = j + 1; t < j + K; t++)
						{
							if ((i < N && map[i + 1][t]) || (i > 1 && map[i - 1][t]))
							{
								cout << 1 << '\n' << i << ' ' << t;
								exit(0);
							}
						}
						
					}
					// 한뭉텅이 더 나오면 완전 안겹침 
					//		  안나오면 완전 일치
					int k, l;
					for (k = i + 1; k < N + 1; k++)
					{
						for (l = 1; l < M + 1; l++)
						{
							if (map[k][l]) 
							{
								cout << 0;
								exit(0);
							}
						}
					}
					cout << K << '\n';
					while (K--)
						cout << i << ' ' << j++ << '\n';
					exit(0);



				}
				else if (down)
				{
					if (i + K <= N && map[i + K][j]) // 한줄로 겹침 (완전 일치 x)
					{
						int n = i + K;
					
						while (n <= N && map[n][j])
							n++;
						int length = n - i;
						int count = K - (length - K);

						cout << count << '\n';
						i = i + ((length - count) / 2);
						while (count--)
							cout << i++ << ' ' << j << '\n';
						exit(0);
					}
					else // 해당 줄 십자가 찾기
					{
						int t;
						
						for (t = i + 1; t < i + K; t++)
						{
							if ((j < M && map[t][j + 1]) || (j > 1 && map[t][j - 1]))
							{
								cout << 1 << '\n' << t << ' ' << j;
								exit(0);
							}
						}
						
					}
					// 한뭉텅이 더 나오면 완전 안겹침 
					//		  안나오면 완전 일치
					int k, l;
					for (k = i; k < N + 1; k++)
					{
						for (l = 1; l < M + 1; l++)
						{
							if (map[k][l] && (!(k < i + K && l == j))) 
							{
								cout << 0;
								exit(0);
							}
						}
					}
					cout << K << '\n';
					while (K--)
						cout << i++ << ' ' << j << '\n';
					exit(0);
				
				}
				else
				{
					if (K == 1)
					{
						for (int k = i; k < N + 1; k ++)
						{
							for (int l = 1; l < M + 1; l++)
							{
								if (map[k][l] == 1 && k != i && l != j)
								{
									cout << 0;
									exit(0);
								}
							}
						}
						cout << 1 << '\n' << i << ' ' << j;
					}
				}
			}
		}
	} 
}

