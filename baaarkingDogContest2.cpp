#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, G, R;
int map[50][50];
int redMap[50][50], greenMap[50][50];

vector<pair<int, int> > v,  red, green;
vector<int> all, all2;
bool visited[10];
bool visitedR[50][50];
bool visitedG[50][50];

int answer = -987654321;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void copyMap() {
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			redMap[y][x] = map[y][x];
			greenMap[y][x] = map[y][x];
		}
	}
}

void dfsGreen(int start, int cnt) {
	if(cnt == G) {
		for(int i=0; i<v.size(); i++) {
			if(visited[i]) {
				green.push_back(make_pair(v[i].first, v[i].second));
			}
		}
		
		// RED(3), GREEN(4) BFS
		memset(redMap, 0, sizeof(redMap));
		memset(greenMap, 0, sizeof(greenMap));
		copyMap();
		
		queue<pair<int, int> > rq;
		for(int i=0; i<red.size(); i++) {
			int y = red[i].first;
			int x = red[i].second;
			redMap[y][x] = 3;
			visitedR[y][x] = true;
			rq.push(make_pair(y, x));
		}
		
		queue<pair<int, int> > gq;
		for(int i=0; i<green.size(); i++) {
			int y = green[i].first;
			int x = green[i].second;
			greenMap[y][x] = 4;
			visitedG[y][x] = true;
			gq.push(make_pair(y, x));
		}
		
		int count = 0;
		while(!rq.empty()) {
			int qSize = rq.size();
			
			for(int i=0; i<qSize; i++) {
				int y = rq.front().first;
				int x = rq.front().second;
				rq.pop();
			
				for(int dir=0; dir<4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
				
					if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
					if(visitedR[ny][nx] || redMap[ny][nx] == 0) continue;
					visitedR[ny][nx] = true;
					redMap[ny][nx] = 4;
					rq.push(make_pair(ny, nx));
				}	
			}
			if(rq.size() != 0) count++;
		}
		
		count = 0;
		while(!gq.empty()) {
			int qSize = gq.size();
			
			for(int i=0; i<qSize; i++) {
				int y = gq.front().first;
				int x = gq.front().second;
				gq.pop();
			
				for(int dir=0; dir<4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
				
					if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
					if(visitedR[ny][nx] || greenMap[ny][nx] == 0) continue;
					visitedG[ny][nx] = true;
					greenMap[ny][nx] = 3;
					gq.push(make_pair(ny, nx));
				}	
			}
			if(gq.size() != 0) count++;
		}
		
		int result = 0;
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(redMap[y][x] != 0 && greenMap[y][x] != 0 && (redMap[y][x] == greenMap[y][x])) {
					result++;
				}
			}
		}
		answer = max(answer, result);
		
		green.clear();
		return;
	}
	
	for(int i=start; i<all.size(); i++) {
		if(visitedR[i]) continue;
		visited[i] = true;
		dfsGreen(i, cnt+1);
		visited[i] = false;
	}
}

void dfsRed(int start, int cnt) {
	if(cnt == R) {
		for(int i=0; i<v.size(); i++) {
			if(visited[i]) {
				red.push_back(make_pair(v[i].first, v[i].second));
			} else {
				all2.push_back(i);
			}
		}
		
		dfsGreen(0, 0);
		
		red.clear();
		all2.clear();
		
		return;
	}
	for(int i=start; i<all.size(); i++) {
		if(visitedR[i]) continue;
		visited[i] = true;
		dfsRed(i, cnt+1);
		visited[i] = false;
	}
}
void dfs(int start, int cnt) {
	if(cnt == R+G) {
		for(int i=0; i<v.size(); i++) {
			if(visited[i]) {
				all.push_back(i);
			}
		}
		
		dfsRed(0, 0);
		all.clear();
		return;
	}
	for(int i=start; i<v.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		dfs(i, cnt + 1);
		visited[i] = false;;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d %d", &N, &M, &G, &R);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) { // È£¼ö(0), X(1), O(2) 
			scanf("%d", &map[y][x]);
			if(map[y][x] == 2) v.push_back(make_pair(y, x));
		}
	}
	
	// SIMULATION
	dfs(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
}

