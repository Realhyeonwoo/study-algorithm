#include<iostream>
#include<queue>
#define MAX 300
using namespace std;

int N, M, Answer; // За(N) ї­(M) 
int map[MAX][MAX], cpyMap[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > Q;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void copyMap(int map[][MAX], int temp[][MAX]) {
	for(int y=0; y<MAX; y++){
		for(int x=0; x<MAX; x++) {
			map[y][x] = temp[y][x];
		}
	}
}

void meltIceberg(void) {
	queue<pair<int, int> > nextQ;
	
	copyMap(cpyMap, map);
	
	while(!Q.empty())	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		int Miuns = 0;
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(map[ny][nx] == 0) Miuns++;
		}
		cpyMap[y][x] -= Miuns;
		
		if(cpyMap[y][x]> 0) nextQ.push(make_pair(y, x));
		else cpyMap[y][x] = 0;
	}
	
	copyMap(map, cpyMap);
	Q = nextQ;
}

bool isSeperate(void) {
	bool visit[MAX][MAX];
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			visit[y][x] = false;
		}
	}
	int sum = 0;
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] != 0 && !visit[y][x]) {
				queue<pair<int, int> > tq;
				tq.push(make_pair(y, x));
				visit[y][x] = true;
				
				while(!tq.empty()) {
					int cy = tq.front().first;
					int cx = tq.front().second;
					tq.pop();
					
					for(int dir=0; dir<4; dir++) {
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];
						
						if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
						if(visit[ny][nx] || map[ny][nx] == 0) continue;
						
						visit[ny][nx] = true;
						tq.push(make_pair(ny, nx));
					}
				}
				sum++;
			}
			if(sum >= 2) return true;
		}
	}
	return false;
}

bool isAllmelt(void) {
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] > 0) return false;
		}
	}
	return true;
}

int main(void) {
	// INPUT
	cin >> N >> M;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			cin >> map[y][x];
			if(map[y][x] != 0) {
				Q.push(make_pair(y, x));
				visited[y][x] = true;
			}
		}
	}
	
	// SIMULATION
	while(1) {
		if(isSeperate()) break;
		if(isAllmelt()) {
			Answer = 0;
			break;
		}
		meltIceberg();
		Answer++;
	}
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}
