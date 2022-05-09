/* 근손실 */

#include <iostream>
#include <cstring>

using namespace std;

struct kit
{
	int w;
	bool used;
};

int N, K;
int plan[8];
int muscle;
int result;
struct kit kit[8];


void BackTrack(int cur, int n)
{
	int i;

	if (n == N)	// 계획 다 짜고 확인
	{
		for (i = 0; i < N; i++)
		{
			muscle = muscle - K + plan[i];
			if (muscle < 500)
			{
				muscle = 500;
				return;
			}
		}
		result++;
		muscle = 500;
	}
	else
	{
		for (i = 0; i < N; i++)   // 뽑는거면 cur부터 순서가 중요하면 0부터
		{
			if (kit[i].used == true)
				continue;
			plan[n] = kit[i].w;
			kit[i].used = true;
			BackTrack(i + 1, n + 1); 
			kit[i].used = false;
		}
	}
}

int main()
{
	int i;
	muscle = 500;
	cin >> N >> K;
	for (i = 0; i < N; i++)
		cin >> kit[i].w;
	BackTrack(0, 0);
	cout << result;
}