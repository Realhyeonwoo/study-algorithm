#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int Bigger(int A, int B) { if (A > B) return A; return B; }

int bfs(int y, int x) {
	int roomSize = 1;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		int wall = 1;
		for(int dir=0; dir<4; dir++) {
			if((map[cy][cx] & wall) != wall) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				
				if(ny>=0 && ny<m && nx>=0 && nx<n) {
					if(!visited[ny][nx]) {
						roomSize++;
						visited[ny][nx] = true;
						q.push(make_pair(ny, nx));
					}
				}
			}
			wall *= 2;
		}
	}
	return roomSize;
}

int main(void) {
	// INPUT
	scanf("%d %d", &n, &m);
	for(int y=0; y<m; y++) {
		for(int x=0; x<n; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	int roomCount = 0;
	int biggestRoom = 0;
	int breakRoom = 0;
	
	for(int y=0; y<m; y++) {
		for(int x=0; x<n; x++) {
			if(visited[y][x]) continue;
			int temp = bfs(y, x);
			printf("temp: %d\n", temp);
			biggestRoom = Bigger(biggestRoom, temp);
			roomCount++;
		}
	}
	
	for(int y=0; y<m; y++)	 {
		for(int x=0; x<n; x++) {
			memset(visited, false, sizeof(visited));
			for(int wall=1; wall<=8; wall*=2) {
				if((map[y][x] & wall) == wall) {
					map[y][x] -= wall;
					breakRoom = max(breakRoom, bfs(y, x));
					map[y][x] += wall;
				}				
			}
		}
	}
	
	// OUTPUT
	printf("%d\n", roomCount);
	printf("%d\n", biggestRoom);
	printf("%d\n", breakRoom);
	
	return 0;
}
