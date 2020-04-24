#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 26
using namespace std;

typedef struct {
	int y, x;
	char p;	
}Ans;

typedef struct {
	int y, x, dir;
} Gas;

int R, C;
char map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int> > v;
pair<int, int> Start, End;
Ans answer;

char pipe[] = {'|', '-', '+', '1', '2', '3', '4'};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool useAllPipe(void) {
	for(int i=0; i<v.size(); i++)	 {
		if(!visited[v[i].first][v[i].second]) return false;
	}
	return true;
}

int setDirection(char p, int dir) {
	int nd = -1;
	if(p == '|') {
		if(dir == 2 || dir == 3) nd = dir;
	} else if(p == '-') {
		if(dir == 0 || dir == 1) nd = dir;
	} else if(p == '+') {
		nd = dir;
	} else if(p == '1') {
		if(dir == 3) nd = 0;
		else if(dir == 1) nd = 2;
	} else if(p == '2') {
		if(dir == 2) nd = 0;
		else if(dir == 1) nd = 3;
	} else if(p == '3') {
		if(dir == 0) nd = 3;
		else if(dir == 2) nd = 1;
	} else if(p == '4') {
		if(dir == 0) nd = 2;
		else if(dir == 3) nd = 1;
	}
	return nd;
}
pair<int, int> bfs(void) {
	queue<Gas> q;
	q.push({Start.first, Start.second, 0});
	visited[Start.first][Start.second] = true;
	
	int ny, nx;
	bool isFind = false;
	
	while(!q.empty()) {
		if(isFind) break;
		
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		
		if(map[y][x] == 'M') {
			for(int i=0; i<4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				
				if(ny<1 || ny>R || nx<1 || nx>C) continue;
				if(map[ny][nx] == '.' || map[ny][nx] == 'Z') continue;
				
				dir = setDirection(map[ny][nx], i);
				if(dir != -1) {
					if(!visited[ny][nx]) visited[ny][nx] = true;
					q.push({ny, nx, dir});
				}
			}	
			
			if(q.size() == 0) {
				for(int i=0; i<4; i++) {
					memset(visited, false, sizeof(visited));
					if(isFind) break;
					
					ny = y + dy[i];
					nx = x + dx[i];
					
					if(ny<1 || ny>R || nx<1 || nx>C) continue;
					for(int j=0; j<7; j++) {
						memset(visited, false, sizeof(visited));
						
						map[ny][nx] = pipe[j];
						pair<int, int> Temp = bfs();
						if(Temp.first == -1 && Temp.second == -1) {
							if(useAllPipe()) {
								isFind = true;
								printf("%d %d %c\n", ny, nx, pipe[j]);
								exit(0);
//								answer = {ny, nx, pipe[j]};
//								break;
							}
						}
						map[ny][nx] = '.';
					}
				}
			}
		} else {
			ny = y + dy[dir];
			nx = x + dx[dir];
			
			if(ny<1 || ny>R || nx<1 || nx>C) continue;
			if(map[ny][nx] == '.') return {ny, nx};
			if(map[ny][nx] == 'Z') return {-1, -1};
			
			dir = setDirection(map[ny][nx], dir);
			if(dir == -1) return {ny, nx};
			if(!visited[ny][nx]) visited[ny][nx] = true;
			q.push({ny, nx, dir});
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == 'M') {
				Start.first = y;
				Start.second = x;
			}
			if(map[y][x] != '.' && map[y][x] != 'Z' && map[y][x] != 'M') {
				v.push_back(make_pair(y, x));
			}
		}
	}
	
	// SIMULATION
	pair<int, int> Before, After;
	Before = bfs();
	int y = Before.first;
	int x = Before.second;
	
	for(int i=0; i<7; i++) {
		map[y][x] = pipe[i];
		memset(visited, false, sizeof(visited));
		After = bfs();
		
		if(After.first == -1 && After.second == -1) {
			if(useAllPipe()) {
				printf("%d %d %c\n", y, x, pipe[i]);
				return 0;
//				answer = {y, x, pipe[i]};
//				break;
			}
		}
	}
	
	// OUTPUT
	printf("%d %d %c\n", answer.y, answer.x, answer.p);
}
