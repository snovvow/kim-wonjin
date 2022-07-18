/* 트리의 순회 */

#include <iostream>

using namespace std;
 
int postOrder[100001];
int inOrder[100001];
int position[100001];
int n;

void recursive(int inOrderStart, int inOrderEnd, int postStart, int postEnd){
    if(inOrderStart > inOrderEnd) 
		return; 
    int root = postOrder[postEnd];
    cout << root << " ";
    int pos = position[root];
    recursive(inOrderStart, pos - 1, postStart, postStart+ (pos - 1 - inOrderStart));   //left
    recursive(pos + 1, inOrderEnd, postStart + pos - inOrderStart, postEnd- 1);      //right
    return; 
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) { 
		cin >> inOrder[i];   // 인오더는 루트를 기준으로 반갈됨
        position[inOrder[i]] = i;  
	}
	for (int i = 0; i < n; ++i) 
		cin >> postOrder[i];  // 포스트오더는 마지막이 루트

	recursive(0, n - 1, 0, n - 1); 
}