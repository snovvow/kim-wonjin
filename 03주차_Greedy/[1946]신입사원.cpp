/* 신입 사원 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct applicant
{
	int document;
	int interview;
};

bool cmp(struct applicant a, struct applicant b)
{
	return (a.document < b.document);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, i, j, result, min;
	cin >> T;

	while (T--)
	{
		cin >> N;
		struct applicant a[N];

		for (i = 0; i < N; i++)
		{
			cin >> a[i].document >> a[i].interview;
		}
		sort(a, a + N, cmp);     // 서류 성적 등수 순으로 정렬 (1등부터)
		min = a[0].interview;
		result = 1;              // 서류 1등은 일단 합격

		// 나보다 서류 등수 높은 사람 중에 면접 등수 젤 높으면 합격
		for (i = 1; i < N; i++)
		{
			if (min > a[i].interview)
			{
				min = a[i].interview;
				result++;
			}
		}
		cout << result << '\n';
	}
}