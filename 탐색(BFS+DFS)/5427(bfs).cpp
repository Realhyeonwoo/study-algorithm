#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int T, w, h;
int start_y, start_x;
char map[1000][1000];
bool visited[1000][1000];
queue<pair<int, int> >fireQ;
int fireMap[1000][1000];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
void makeFire() {
	int count = 1;
	while(!fireQ.empty()) {
		int qSize = fireQ.size();
		for(int i=0; i<qSize; i++) {
			int y = fireQ.front().first;
			int x = fireQ.front().second;
			visited[y][x] = true;
			fireQ.pop();
		
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
				if(map[ny][nx] == '*' || visited[ny][nx] || map[ny][nx] == '#') continue;
			
				fireMap[ny][nx] = count;
				visited[ny][nx] = true;
				fireQ.push(make_pair(ny, nx));
			}			
		}
		count++;
	}
}

int move_bfs(int sy, int sx) {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(sy, sx), 0));
	visited[sy][sx] = true;
	
	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int moveTime = q.front().second;
		q.pop();
		
		if(y==0 || y==h-1 || x==0 || x==w-1) return moveTime + 1;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
			if(map[ny][nx] == '*' || map[ny][nx] == '#' || visited[ny][nx]) continue;
			if(fireMap[ny][nx] >=0 && fireMap[ny][nx] <= moveTime + 1) continue;
			
			visited[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), moveTime + 1));
		}
	}
	
	return -1;
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		while(!fireQ.empty()) {
			fireQ.pop();	
		} 
		memset(fireMap, -1, sizeof(fireMap));
		memset(visited, false, sizeof(visited));
		
		// INPUT
		scanf("%d %d", &w, &h);
		for(int y=0; y<h; y++) {
			for(int x=0; x<w; x++) {
				scanf(" %c", &map[y][x]);
				if(map[y][x] == '*') {
					fireMap[y][x] = 0;
					fireQ.push(make_pair(y, x));	
				}
				if(map[y][x] == '@') {
					start_y = y;
					start_x = x;
				}
			}
		}
		
		// SIMULATION
		makeFire();
		memset(visited, false, sizeof(visited));
		int answer = move_bfs(start_y, start_x);
		
		// OUTPUT
		if(answer == -1) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", answer);
		}
	}
	return 0;
}
