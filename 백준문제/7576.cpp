#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 1000
using namespace std;

int M, N;
int map[MAX][MAX];
queue<pair<int, int> > Q;
int Answer = 0;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	bool isEmpty = true;
	cin >> M >> N;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			cin >> map[y][x];
			if(map[y][x] == 0) isEmpty = false;
			if(map[y][x] == 1) {
				Q.push(make_pair(y, x));
			}
		}
	}
	
	// SIMULATION
	if(!isEmpty) {
		while(!Q.empty()) {
			int qSize = Q.size();
			for(int i=0; i<qSize; i++) {
				int y = Q.front().first;
				int x = Q.front().second;
				Q.pop();
				
				for(int dir=0; dir<4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					
					if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
					if(map[ny][nx] != 0) continue;
					
					map[ny][nx] = 1;
					Q.push(make_pair(ny, nx));
				}
			}
			if(!Q.empty()) Answer++;
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == 0) {
				Answer = -1;
				break;
			}
		}
		if(Answer == -1) break;
	}
	
	// OUTPUT
	cout << Answer << '\n';
	return 0;
}
