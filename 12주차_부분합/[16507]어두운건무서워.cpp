/* 어두운 건 무서워 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int R, C, Q;
	cin >> R >> C >> Q;
	int map[R + 1][C + 1];
	int sum[R + 1][C + 1];
	memset(sum, 0, sizeof(sum));

    for(int i = 1; i < R + 1; i++){
        for(int j = 1; j < C + 1; j++){
            cin >> map[i][j];
        } 
    }
    
    //가로 
    for(int i = 1; i < R + 1; i++){
        for(int j = 1; j < C + 1; j++){
            sum[i][j] = sum[i][j-1] + map[i][j];
        }
    }
    //세로 
    for(int i = 1; i < C + 1; i++){
        for(int j = 1; j < R + 1; j++){
            sum[j][i] = sum[j-1][i] + sum[j][i];
        }
    }
    
    while(Q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]) / ((r2 - r1 + 1) * (c2- c1 + 1)) << '\n';
    }
}