#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[25][25];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void makeGroup_dfs(int number, int y, int x) {
	map[y][x] = number;
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		if(map[ny][nx] == 0 || map[ny][nx] == number) continue;
//		map[ny][nx] = 0;
		makeGroup_dfs(number, ny, nx);
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	// HOUSE_CHECK(DFS)
	int number = 0;
	int count = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 1) {
				count++;
				number--;
				makeGroup_dfs(number, y, x);
			}
		}
	}
	
	// RESULT COUNT
	vector<int> house;
	for(int c=-1; c>=number; c--) {
		int num = 0;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(map[y][x] == c) {
					num++;
				}
			}
		}	
		house.push_back(num);
	}
	
	// SORT
	sort(house.begin(), house.end());
	
	// OUTPUT
	printf("%d\n", count);
	for(int i=0; i<house.size(); i++) {
		printf("%d\n", house[i]);
	}
	
	return 0;
}
