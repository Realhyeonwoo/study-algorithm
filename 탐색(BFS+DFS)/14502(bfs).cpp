#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M; // 세로(N), 가로(M)
int map[8][8];
int copyMap[8][8];
vector<pair<int, int> > wall;
bool visited_wall[64];
int answer;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void copy() {
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			copyMap[y][x] = map[y][x];
		}
	}
}

void spreadVirus() {
	queue<pair<int, int> > q;
	bool visited[8][8];
	memset(visited, false, sizeof(visited));
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(!visited[y][x] && copyMap[y][x] == 2) {
				q.push(make_pair(y, x)); 
			}
		}
	}
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop(); 
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx] || copyMap[ny][nx] != 0) continue;
			
			visited[ny][nx] = true;
			copyMap[ny][nx] = 2;
			q.push(make_pair(ny, nx));
		}
	}
	
	// check	
	int sum = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(copyMap[y][x] == 0) sum++;
		}
	}
	
	answer = max(answer, sum);
}

void setWall(int start, int cnt) {
	if(cnt == 3) {
		copy();
		for(int i=0; i<wall.size(); i++) {
			if(visited_wall[i]) {
				copyMap[wall[i].first][wall[i].second] = 1;
			}
		}
		spreadVirus();
		return;
	}
	
	for(int i=start; i<wall.size(); i++) {
		if(visited_wall[i]) continue;
		visited_wall[i] = true;
		setWall(i, cnt + 1);
		visited_wall[i] = false;
	}
}

int main(void) {
	//INPUT ( 빈칸(0), 벽(1), 바이러스(2) )  
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0) wall.push_back(make_pair(y, x));
		}
	}
	
	// SIMULATION
	setWall(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0; 
	
}
