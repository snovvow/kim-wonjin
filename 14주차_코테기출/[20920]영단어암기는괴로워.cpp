/* 영단어 암기는 괴로워 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <string, int> voca;
vector <pair<string, int> > v;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	if (a.second != b.second)
		return (a.second > b.second);
    else if (a.first.length() != b.first.length())
        return (a.first.length() > b.first.length());
    else
        return (a.first < b.first);
}

int main()
{
    int N, M, i, j;
    map<string, int>::iterator iter;
    vector <pair<string, int> >::iterator iter_v;

    cin >> N >> M;

    for (i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        if (word.length() >= M)
        {
            iter = voca.find(word);
            if (iter == voca.end()) // 없으면
                voca.insert(make_pair(word, 1));
            else // 이미 있으면
                iter->second++;
        }
    }
    // 정렬 위해 벡터로 옮기기 ㅠㅠ
    for (iter = voca.begin(); iter != voca.end(); iter++)
        v.push_back(make_pair(iter->first, iter->second));

    sort(v.begin(), v.end(), cmp);

    for (iter_v = v.begin(); iter_v != v.end(); iter_v++)
        cout << iter_v->first << '\n';

}