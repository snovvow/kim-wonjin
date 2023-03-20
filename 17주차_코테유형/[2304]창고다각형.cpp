/* 창고 다각형 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

	int N, i, num, height, max_num, max_height, top;
	cin >> N;
	int map[1001];
	max_num = 0;
	max_height = 0;
	memset(map, 0, sizeof(map));

	for (i = 0; i < N; i++) {
		cin >> num >> height;
		map[num] = height;
		if (num > max_num) max_num = num;
		if (height > max_height) {
			max_height = height;
			top = num;
		}
	}

	int totalLeft = 0;
	int current = 0;
	i = 1;
	while (i != top) 
	{
		if (current < map[i]) current = map[i];
		totalLeft += current;
		i++;
	}
	
	int totalRight = 0;
	i = max_num;
	current = 0;
	while (i != top)
	{
		if (current < map[i]) current = map[i];
		totalRight += current;
		i--;
	}
	cout << totalLeft + totalRight + max_height;
}