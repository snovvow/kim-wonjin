/*  저울  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, i, tmp, result;

	cin >>	N;
	vector <int> w;
	for (i = 0; i < N; i++)
	{			
		cin >> tmp;
		w.push_back(tmp);
	}
	sort(w.begin(), w.end());

	result = 1;

	for (i = 0; i < N; i++)
	{
		if (w[i] > result)
			break;
		result += w[i];
	}
	cout << result;
}