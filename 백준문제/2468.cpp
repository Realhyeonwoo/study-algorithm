#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

int n;
int map[100][100];
int minValue = 9999, maxValue = -9999;
int clone[100][100];
int visited[100][100] = {false, };
vector<int> answer; 

void dfs(int y, int x) {
	clone[y][x] = -1;
	visited[y][x] = true;
	
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
		if(!visited[ny][nx] && clone[ny][nx]>0) {
			dfs(ny, nx);
		}
	}
}

void pour(int height) {
	memset(clone, 0, sizeof(clone));
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	// บนป็ 
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(map[y][x] <= height) {
				clone[y][x] = 0;
			} else {
				clone[y][x] = map[y][x];	
			}
		}
	}
	
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(!visited[y][x] && clone[y][x] > 0) {
				cnt++;
				dfs(y, x);
			}
		}
	}
	answer.push_back(cnt);
}

int main(void) {
	scanf("%d", &n);
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			scanf("%d", &map[y][x]);
			if(minValue > map[y][x]) minValue = map[y][x];
			if(maxValue < map[y][x]) maxValue = map[y][x];
		}
	}
	for(int h=0; h<=maxValue; h++) {
		pour(h);
	}
	
	sort(answer.begin(), answer.end());
	printf("%d\n", answer[answer.size()-1]);
	return 0;
}
