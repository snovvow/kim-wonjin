/* 가희와 키워드 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_set<string> keywords;
	unordered_set<string>::iterator it;

	int N, M, i;
	cin >> N >> M;

	string word;
	for (i = 0; i < N; i++)
	{
		cin >> word;
		keywords.insert(word);
	}

	string usage;
	for (i = 0; i < M; i++)
	{
		cin >> usage;
		int seperator, p = 0;
		while (1)
		{
			seperator = usage.find(",", p);
			if (seperator == string::npos) break;
			int len = seperator - p;
			string usedWord = usage.substr(p, len);
			it = keywords.find(usedWord);
			if (it != keywords.end()) 
				keywords.erase(usedWord);
			p = seperator + 1;
		}
		
		string usedWord = usage.substr(p);
		it = keywords.find(usedWord);
		if (it != keywords.end()) 
			keywords.erase(usedWord);
		cout << keywords.size() << '\n';
	}
}