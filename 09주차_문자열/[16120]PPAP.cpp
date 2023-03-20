/* PPAP */

#include <iostream>

using namespace std;

int main()
{
	int i, stack;
	string input;

	i = 0;
	stack = 0;
	/* 
	stack 에는 p 또는 ppap 의 갯수가 담김
	p를 담다가 a를 만나면 ppap 여부를 확인하고 스택조정
	마지막에 스택에 ppap(stack = 1)이 남으면 성공
	*/
	cin >> input;
	while (input[i])  
	{
		if (input[i] == 'P')
			stack++;
		else if (input[i] == 'A' && stack > 1 && input[i + 1] == 'P')
		{
			stack = stack + 1 - 3 + 1;
			i++;
		}
		else
		{
			cout << "NP";
			return 0;
		}
		i++;
	}
	if (stack == 1)
		cout << "PPAP";
	else
		cout << "NP";
	return 0;
}