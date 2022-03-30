/* 겹치는 선분 */

 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <algorithm>

using namespace std;

int main()
{
	int N, i, tmp1, tmp2;

	cin >> N;
	vector<pair<int, int> > line;
	for (i = 0; i < N; i++)
	{
		cin >> tmp1 >> tmp2;
		line.push_back(make_pair(tmp1, tmp2));
	}

	cout << 
}