#include<iostream>
#include<queue>
#define MAX 100
using namespace std;

int N, Height, map[MAX][MAX], cpyMap[MAX][MAX];
bool visited[MAX][MAX];
int Answer;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int a, int b) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;
	
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(cpyMap[ny][nx] == -1 || visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
}

void setMap(int height) {
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			cpyMap[y][x] = map[y][x];
			if(cpyMap[y][x] <= height) cpyMap[y][x] = -1;
		}
	}
}

int checkArea(int height) {
	setMap(height);
	for(int y=0; y<N; y++) fill(visited[y], visited[y] + N, false);
	
	int count = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(cpyMap[y][x] != -1 && !visited[y][x]) {
					bfs(y, x);
					count++;
			}
		}
	}
	return count;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N;
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			cin >> map[y][x];
			Height = max(Height, map[y][x]);
		}
	}
	
	// SIMULATION
	for(int i=1; i<Height; i++) {
		Answer = max(Answer, checkArea(i));
	}
	
	// OUTPUT	
	if(Answer == 0) cout << 1 << '\n';
	else cout << Answer << '\n';
	
	return 0;
}
