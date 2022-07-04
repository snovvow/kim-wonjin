/* 암호 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string set;
	string code;
	int i, codelen, setlen, index;
	long long count;
	long long pownum;

	cin >> set;	
	cin >> code;

	codelen = code.length();
	setlen = set.length();

	count = 0;
	pownum = 1;
	for (i = codelen; i > 0; i--)
	{
		index = set.find(code[i - 1]);
		count = (count + ((index + 1) * pownum)) % 900528;
		pownum = pownum * setlen % 900528;
	}
	cout << count;
	return 0;
}