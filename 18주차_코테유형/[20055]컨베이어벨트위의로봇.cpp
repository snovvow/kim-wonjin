/* 컨베이어 벨트 위의 로봇 */

#include <iostream>

using namespace std;

int N, K;
int A[201];
bool robot[201];

int main() {

	int i, turn, load, unload;
	cin >> N >> K;
	for (i = 1; i < 2 * N + 1; i++)
		cin >> A[i];
	
	turn = 1;
	load = 1;
	unload = N;
	while (1) {

		// 벨트 회전
		// 올리는 위치
		if (load == 1)
			load = 2 * N;
		else
			load--;
		
		// 내리는 위치 
		if (unload == 1)
			unload = 2 * N;
		else
			unload--;

		if (robot[unload])
			robot[unload] = false;
		
		// 로봇 이동
		int to = unload;
		int from = unload;
		for (i = 0; i < N - 2; i++)
		{
			to = from;
			if (to == 1)
				from = 2 * N;
			else 
				from = to - 1;

			if (robot[from] && !robot[to] && A[to] > 0)
			{
				robot[from] = false;
				robot[to] = true;
				A[to]--;
				// 이동한 위치가 [내리는 위치]면 이동 후 바로 내리기
				if (to == unload)
					robot[to] = false;				
			}		
		}
		// 로봇 올리기
		if (A[load] > 0)
		{
			robot[load] = true;
			A[load]--;
		}
		// 내구도 확인
		int count = 0;
		for (i = 1; i < 2 * N + 1; i++)
			if (A[i] < 1) count++;

		if (count >= K)
			break;

		turn++;
	}
	cout << turn;
}