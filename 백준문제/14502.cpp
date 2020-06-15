#include<iostream>
#include<queue>
#include<vector>
#define MAX 8
using namespace std;

int N, M, Answer = -987654321; // 세로(N) 가로(M)
int map[MAX][MAX], cpyMap[MAX][MAX]; // 빈칸(0) 벽(1) 바이러스(2) 
bool visited[MAX][MAX], visit[MAX*MAX];
queue<pair<int, int> > virusQ;
vector<pair<int, int> > emptyV;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void copyMap(void) {
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			cpyMap[y][x] = map[y][x];
		}
	}
}

void spreadVirus(void) {
	queue<pair<int, int> > Q = virusQ;
	
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(cpyMap[ny][nx] == 1 || visited[ny][nx]) continue;
			
			cpyMap[ny][nx] = 1;
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
}

int countSafeArea(void) {
	int res = 0;
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++) {
			if(cpyMap[y][x] == 0) res++;
		}
	}
	return res;
}

void putWall_dfs(int start, int cnt) {
	if(cnt == 3) {
		copyMap();
		for(int i=0; i<emptyV.size(); i++) {
			if(visit[i]) {
				int y = emptyV[i].first;
				int x = emptyV[i].second;
				cpyMap[y][x] = 1;
			}
		}
		spreadVirus();		
		Answer = max(Answer, countSafeArea());
		for(int y=0; y<N; y++) fill(visited[y], visited[y] + MAX, false);
		return; 
	}
	
	for(int i=start; i<emptyV.size(); i++) {
		if(visit[i]) continue;
		visit[i] = true;
		putWall_dfs(i, cnt + 1);
		visit[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N >> M;
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++) {
			cin >> map[y][x];
			if(map[y][x] == 0) emptyV.push_back(make_pair(y, x));
			else if(map[y][x] == 2) {
				virusQ.push(make_pair(y, x));
				visited[y][x] = true;
			}
		}
	}
	
	// SIMUALATION
	putWall_dfs(0, 0);
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}
