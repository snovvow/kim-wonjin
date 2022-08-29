/* 주지수 */

#include <iostream>
#include <cstring>

using namespace std;

int map[1025][1025];
int sum[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M;
	
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
			cin >> map[i][j];
            sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    
	cin >> K;
    while(K--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]) << '\n';
    }
}