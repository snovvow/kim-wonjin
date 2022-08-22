/* 장난꾸러기 영훈 */

#include <iostream>
#include <cmath>

using namespace std;

string code;
bool answer[60];

int main()
{
	int i, size, count, j;
	long long k;

	cin >> code;
	cin >> k;

	size = code.length();
	count = 0;

	for (i = 0; i < size; i++)
	{
		if (code[i] == '1' || code[i] == '6' || code[i] == '2' || code[i] == '7')
			count++;
	}

	if (pow(2, count) < k || k < 1)
	{
		cout << -1;
		return 0;
	}
	j = 0;
	for (int i = count - 1; i >= 0; i--)
    {
        int temp = ((k - 1) >> i) & 1;
        answer[j++] = temp;
    }

	j = 0;

	for (i = 0; i < size; i++)
	{
		if (code[i] == '1' || code[i] == '6' || code[i] == '2' || code[i] == '7')
		{
			if (answer[j] == 1 && code[i] == '1')
				cout << 6;
			else if (answer[j] == 0 && code[i] == '6')
				cout << 1;
			else if (answer[j] == 1 && code[i] == '2')
				cout << 7;
			else if (answer[j] == 0 && code[i] == '7')
				cout << 2;
			else
				cout << code[i];
			j++;
		}
		else
			cout << code[i];
	}
}

/*
0000  
0001  
0010  
0011 
0100  
0101  
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/