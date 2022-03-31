/* 겹치는 선분 */

// 스위핑 알고리즘  -> 빗자루 처럼 쓸면서 훑기

 #include <iostream>
 #include <algorithm>

using namespace std;

typedef struct point
{
	int		pos;
	int		status;    // 시작점 : 1   끝점 : -1
} point;

bool cmp(point a, point b)
{
	if (a.pos != b.pos)
		return (a.pos < b.pos);
	return (a.status < b.status);   // 끝점이 겹칠 경우 포함 시키지 않기 위해
}

int main()
{
	int N, i, line, max;

	cin >> N;
	point point[2 * N];   // 모든 시작점 끝점 저장

	for (i = 0; i < 2 * N; i += 2)
	{
		cin >> point[i].pos;
		point[i].status = 1;

		cin >> point[i + 1].pos;
		point[i + 1].status = -1;
	}

	sort(point, point + 2 * N, cmp);
	line = 0;
	max = 0;

	for (i = 0; i < 2 * N; i++)
	{
		line += point[i].status;   //  ++ or --
		if (max < line)
			max = line;
	}
	cout << max;
}