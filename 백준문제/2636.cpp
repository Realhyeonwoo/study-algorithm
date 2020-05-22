#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 100
using namespace std;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

vector<pair<int, int> > air;
queue<pair<int, int> > nq;

void First_Air_State() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(map[ny][nx] == 0 && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void Divide_Air() {
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(visited[y][x] == 1) {
				for(int dir=0; dir<4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
					if(map[ny][nx] == 1) {
						nq.push(make_pair(y, x));
						break;
					}
				}
			}
			
		}
	}
}

bool Check() {
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == 1) return false;
		}
	}
	return true;
}

void Melting_Cheese() {
	queue<pair<int, int> > q = nq;
	while(!nq.empty()) nq.pop();
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
			if(map[ny][nx] == 1) {
				map[ny][nx] = 0;
				nq.push(make_pair(ny, nx));
			}
		}
	}
}

void Add_Air() {
	queue<pair<int, int> > q = nq;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if(ny<0 || nx<0 || ny>=M || nx>=N) continue;
			if(visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push(make_pair(ny, nx));
				nq.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) visited[y][x] = -1;
		}
	}
	
	// SIMULATION
	First_Air_State();
	Divide_Air();
	
	int Time = 0;
	int Final_Size = 0;
	
	while(1) {
		if(Check()) break;
		
		Melting_Cheese();
		Final_Size = nq.size();
		
		Add_Air();
		Time++;
	}
	
	// OUTPUT
	printf("%d\n%d\n", Time, Final_Size); 
	
	return 0;
}
