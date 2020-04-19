#include<iostream>
#include<queue>
#include<cstring>

#define INF 987654321
using namespace std;

int R, C, N;
char map[101][101];
bool visited[101][101];
bool clusterVisited[101][101];
vector<pair<int, int> > airMineral;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool destroyMineral(char from, int height) {
	if(from == 'L') {
		for(int x=1; x<=C; x++) {
			if(map[height][x] == 'x') {
				map[height][x] = '.';
				return true;
			}
		}
	} else { 
		for(int x=C; x>=1; x--) {
			if(map[height][x] == 'x') {
				map[height][x] = '.';
				return true;
			}
		}
	}
	return false;
}

void check_bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<1 || ny>R || nx<1 || nx>C) continue;
			if(!visited[ny][nx] && map[ny][nx] == 'x') {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int calcGapHeight(int y, int x) {
	int count = 1;
	for(int height = y+1; height<=R; height++) {
		if(map[height][x] == 'x') {
			if(clusterVisited[height][x]) return INF;
			else return count-1;
		} else {
			count++;
		}
	}
	return count-1;
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	scanf("%d", &N);
	// SIMULATION
	int num;
	for(int i=0; i<N; i++) {
//		INIT
		scanf("%d", &num);
		int h = R - num + 1;
		memset(visited, false, sizeof(visited));
		memset(clusterVisited, false, sizeof(clusterVisited));
		airMineral.clear();
		
//		printf("#####################[ %d ]###################\n", num);
//		DESTROY_MINERAL
		bool isDestroy = destroyMineral(i%2==0 ? 'L' : 'R', h);
		
//		printf("\n\n DESTROY STATUS\n");
//		for(int y=1; y<=R; y++) {
//			for(int x=1; x<=C; x++) {
//				printf("%c", map[y][x]);
//			}
//			printf("\n");
//		}		

//		CHECK_DESTORY
		if(!isDestroy) continue;
		
//		MOVE_DESTROY
		for(int x=1; x<=C; x++) {
			if(!visited[R][x]) check_bfs(R, x);
		}
		
		for(int y=1; y<=R; y++) {
			for(int x=1; x<=C; x++) {
				if(map[y][x] == 'x' && !visited[y][x]) {
					airMineral.push_back(make_pair(y, x));
					clusterVisited[y][x] = true;
				}
			}
		}
		
		int minHeight = INF;
		for(int i=0; i<airMineral.size(); i++) {
			int y = airMineral[i].first;
			int x = airMineral[i].second;
			minHeight = min(minHeight, calcGapHeight(y, x));
//			printf("%d %d %d \n", y, x, minHeight);
		}
		
		if(minHeight != INF) {
			for(int i=airMineral.size()-1; i>=0; i--) {
				int y = airMineral[i].first;
				int x = airMineral[i].second;
			
				map[y+minHeight][x] = 'x';
				map[y][x] = '.';
				
			}
		}
//		printf("\n\n MOVE STATUS\n");
//		for(int y=1; y<=R; y++) {
//			for(int x=1; x<=C; x++) {
//				printf("%c", map[y][x]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	
	// OUTPUT
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
	
	return 0;
}
