/* 숨바꼭질 3 */

#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];
priority_queue<pair<int, int> > q; // (-시간, 현위치)

int main()
{
    cin >> N >> K;
    int cur, time, i;

    q.push(make_pair(0, N));
    visited[N] = true;
	
    while (!q.empty())
    {
        time = -q.top().first;
        cur = q.top().second;
        cout << time << ' ' <<cur << '\n';

        q.pop();

        if (cur == K) {cout << time; return 0;}
        // if (cur + 1 == K || cur - 1 == K) {
        //     cout << time + 1;
        //     return 0;
        // }
        // if (cur * 2 == K) {
        //     cout << time;
        //     return 0;
        // }
        if (cur * 2 <= 100000 && cur * 2 >= 0 && visited[cur * 2] == false) {
            q.push(make_pair(-time, cur * 2));
            visited[cur * 2] = true;
        }
        if (cur + 1 <= 100000 && cur + 1 >= 0 && visited[cur + 1] == false) {
            q.push(make_pair(-(time + 1), cur + 1));
            visited[cur + 1] = true;
        }
        if (cur - 1 <= 100000 && cur - 1 >= 0 && visited[cur - 1] == false) {
            q.push(make_pair(-(time + 1), cur - 1));
            visited[cur - 1] = true;
        }

    }
}
