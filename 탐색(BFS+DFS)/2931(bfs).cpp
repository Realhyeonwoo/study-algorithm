#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef struct {
	int y, x;
	char p;
} Answer;

typedef struct {
	int y, x, dir;
} Gas;

int R, C;
char map[26][26];
bool visited[26][26];
pair<int, int> Start;
vector<pair<int, int> > vPipe;
Answer answer;

char pipe[] = {'|', '-', '+', '1', '2', '3', '4'};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int setDirection(int dir, char C) {
	int nd = -1;
	if (C == '|')
    {
        if (dir == 2 || dir == 3) nd = dir;
    }
    else if (C == '-')
    {
        if (dir == 0 || dir == 1) nd = dir;
    }
    else if (C == '+') nd = dir;
    else if (C == '1')
    {
        if (dir == 3) nd = 0;
        else if (dir == 1) nd = 2;
    }
    else if (C == '2')
    {
        if (dir == 2) nd = 0;
        else if (dir == 1) nd = 3;
    }
    else if (C == '3')
    {
        if (dir == 0) nd = 3;
        else if (dir == 2) nd = 1;
    }
    else if (C == '4')
    {
        if (dir == 0) nd = 2;
        else if (dir == 3) nd = 1;
    }

	return nd;	
}

bool isPassAllPipe() {
	for(int i=0; i<vPipe.size(); i++) {
		if(!visited[vPipe[i].first][vPipe[i].second]) return false;
	}
	return true;
}

pair<int, int> bfs() {
	queue<Gas> q;
	q.push({Start.first, Start.second, 0});
	
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
				if(map[ny][nx] == 'Z' || map[ny][nx] == '.') continue;
				
				dir = setDirection(i, map[ny][nx]);
				if(dir != -1) {
					q.push({ny, nx, dir});
					visited[ny][nx] = true;
				}
			}
			
			if(q.size() == 0) {
				for(int i=0; i<4; i++) {
					memset(visited, false, sizeof(visited));
					ny = y + dy[i];
					nx = x + dx[i];
					
					if(isFind) break;
					for(int p=0; p<7; p++) {
						memset(visited, false, sizeof(visited));
						map[ny][nx] = pipe[p];
						pair<int, int> Temp = bfs();
						if(Temp.first == -1 && Temp.second == -1) {
							if(isPassAllPipe()) {
								answer = {ny, nx, pipe[p]};
								isFind = true;
								break;
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
			if(map[ny][nx] == 'Z') return {-1, -1};
			if(map[ny][nx] == '.') return {ny, nx};
			
			dir = setDirection(dir, map[ny][nx]);
			if(dir == -1) return {ny, nx};
			q.push({ ny, nx, dir });
			visited[ny][nx] = true;
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
			if(map[y][x] != 'M' && map[y][x] != 'Z' && map[y][x] != '.') {
				vPipe.push_back(make_pair(y, x));
			}
		}
	}
	
	// SIMULATION
	pair<int, int> Before, After;
	Before = bfs();
	int y = Before.first;
	int x = Before.second;
	
	for(int p=0; p<7; p++) {
		map[y][x] = pipe[p];
		
		memset(visited, false, sizeof(visited));
		pair<int, int> temp = bfs();
		if(temp.first == -1 && temp.second == -1) {
			if(isPassAllPipe()) {
				answer = {y, x, pipe[p]};
				break;
			}
		}
	}
	
	// OUTPUT
	printf("%d %d %c\n", answer.y, answer.x, answer.p);
	
	return 0;
}
