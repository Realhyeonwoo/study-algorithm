#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N;
int map[100][100];
int copyMap[100][100];
bool visited[100][100];
int max_height = -1;
void copy(void) {
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			copyMap[y][x] = map[y][x];
		}
	}
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	copyMap[y][x] = 0;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(visited[ny][nx] || copyMap[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			copyMap[ny][nx] = 0;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
			copyMap[y][x] = map[y][x];
			max_height = max(max_height, map[y][x]);
		}
	}
	
	int count, answer=-987654321;
	for(int rain=0; rain<=max_height; rain++) {
		copy();
		memset(visited, false, sizeof(visited));
		
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(copyMap[y][x] <= rain) {
					copyMap[y][x] = 0;
				}
			}
		}
		count = 0;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(copyMap[y][x] != 0) {
					count++;
					bfs(y, x);
				}
			}
		}
		answer = max(answer, count);
	}
	
	printf("%d\n", answer);
	return 0;
}
