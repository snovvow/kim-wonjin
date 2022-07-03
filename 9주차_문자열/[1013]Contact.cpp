/* Contact */

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	int T, t, i;
	string input;
	regex re("(100+1+|01)+");  

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> input;
		if (regex_match(input, re))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	} 
	return 0;
}