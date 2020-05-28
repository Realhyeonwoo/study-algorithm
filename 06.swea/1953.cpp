#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 50
using namespace std;

typedef struct {
	int y, x, shape;
}Info;

int N, M, R, C, L;
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<Info> q;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

vector<int> getDirection(int num) {
	vector<int> v;
	if(num == 1) {
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
	} else if(num == 2) {
		v.push_back(2);
		v.push_back(3);
	} else if(num == 3) {
		v.push_back(0);
		v.push_back(1);
	} else if(num == 4) {
		v.push_back(0);
		v.push_back(3);
	} else if(num == 5) {
		v.push_back(0);
		v.push_back(2);
	} else if(num == 6) {
		v.push_back(1);
		v.push_back(2);
	} else if(num == 7) {
		v.push_back(1);
		v.push_back(3);
	}
	return v;
}

bool canGo(int shape, int newShape, int dir) {
		if(shape == 1) {
			if(dir == 0) {
				if(newShape == 1 || newShape == 3 || newShape == 6 || newShape == 7) return true;
			} else if(dir == 1) {
				if(newShape == 1 || newShape == 3 || newShape == 4 || newShape == 5) return true;
			} else if(dir == 2) {
				if(newShape == 1 || newShape == 2 || newShape == 4 || newShape == 7) return true;
			} else if(dir == 3) {
				if(newShape == 1 || newShape == 2 || newShape == 5 || newShape == 6) return true;
			}
		} else if(shape == 2) {
			if(dir == 2) {
				if(newShape == 1 || newShape == 2 || newShape == 4 || newShape == 7) return true;
			} else if(dir == 3) {
				if(newShape == 1 || newShape == 2 || newShape == 5 || newShape == 6) return true;
			}
		} else if(shape == 3) {
			if(dir == 0) {
				if(newShape == 1 || newShape == 3 || newShape == 6 || newShape == 7) return true;
			} else if(dir == 1) {
				if(newShape == 1 || newShape == 3 || newShape == 4 || newShape == 5) return true;
			}
		} else if(shape == 4) {
			if(dir == 0) {
				if(newShape == 1 || newShape == 3 || newShape == 6 || newShape == 7) return true;
			} else if(dir == 3) {
				if(newShape == 1 || newShape == 2 || newShape == 5 || newShape == 6)	return true;
			}
		} else if(shape == 5) {
			if(dir == 0) {
				if(newShape == 1 || newShape == 3 || newShape == 6 || newShape == 7) return true;			
			} else if(dir == 2) {
				if(newShape == 1 || newShape == 2 || newShape == 4 || newShape == 7) return true;
			}
		} else if(shape == 6) {
			if(dir == 1) {
				if(newShape == 1 || newShape == 3 || newShape == 4 || newShape == 5) return true;
			} else if(dir == 2) {
				if(newShape == 1 || newShape == 2 || newShape == 4 || newShape == 7) return true;
			}
		} else if(shape == 7) {
			if(dir == 1) {
				if(newShape == 1 || newShape == 3 || newShape == 4 || newShape == 5) return true;
			} else if(dir == 3) {
				if(newShape == 1 || newShape == 2 || newShape == 5 || newShape == 6) return true;
			}
		} 
		return false;
}

int main(void) {
	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		while(!q.empty()) q.pop();
		
		// INPUT
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				scanf("%d", &map[y][x]); 
			}
		}
		visited[R][C] = true;
		q.push({R, C, map[R][C]});
		
		// SIMULATION
		int count = 1;
		for(int l=1; l<L; l++) {
//			printf("====================== %d ========================\n", l);
			int qSize = q.size();
			for(int i=0; i<qSize; i++) {
				int y = q.front().y;
				int x = q.front().x;
				int shape = q.front().shape;
				q.pop();
				
				vector<int> d = getDirection(shape);
				
//				printf("πÊ«‚\n");
//				for(int k=0; k<d.size(); k++) printf("%d ", d[k]);
//				printf("\n");
				for(int i=0; i<d.size(); i++) {
					int ny = y + dy[d[i]];
					int nx = x + dx[d[i]];
					
					if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
					if(visited[ny][nx] || map[ny][nx] == 0) continue;
					if(!canGo(map[y][x], map[ny][nx], d[i])) continue;
					
					visited[ny][nx] = true;
					q.push({ny, nx, map[ny][nx]});
					count++;
//					printf("%d %d %d \n", ny, nx, map[ny][nx]);
				}
			}
//			printf(">> count: %d\n", count);
		}
		
		// OUTPUT
		printf("#%d %d\n", tc, count);
	}
	return 0;
}
