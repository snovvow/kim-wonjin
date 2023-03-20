/* 싸이버개강총회 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int timeInput()
{
	int i, result;
	string time;
	if (cin.eof()) return -1;
	cin >> time;
	if (time == "\0") return (-1);
	result = time[0] * 1000 + time[1] * 100 + time[2] * 10 + time[3];
	return result;
}

int main()
{
	int S, E, Q, i, result;
	string t;
	vector <string> student;
	vector<string>::iterator iter;

	S = timeInput();
	E = timeInput();
	Q = timeInput();
	
	result = 0;
	while (1)
	{
		int time = timeInput();
		if (time == -1) break;
		string name;
		cin >> name;
		if (time <= S)
		{
			iter = find(student.begin(), student.end(), name);
			if (iter == student.end())
				student.push_back(name);
			else
				student.erase(iter);
		}
		else if (time >= E && time <= Q)
		{
			iter = find(student.begin(), student.end(), name);
			if (iter != student.end())
			{
				student.erase(iter);
				result++;
			}
		}
	}
	cout << result;
}