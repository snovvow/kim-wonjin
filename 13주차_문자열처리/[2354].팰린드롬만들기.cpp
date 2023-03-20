/* 팰린드롬 만들기*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string S;
	cin >> S;
	int len = S.size();
	int i, j;
	bool isP;
	for(i = 0; i < len; i++)
	{
		isP = true;
		for(j = i; j < len; j++)
		{
			if(S[j]!=S[len-1-(j-i)]){
				isP = false;
				break;
			}		 
		}
		if(isP){
			printf("%d",len + i);
			break;
		}
	}
}
