#include<iostream>
#include<queue>
#define MAX 50
using namespace std;

typedef struct {
	int y, x, cnt, key;
} Pos;

int N, M; // N(세로) M(가로)
char map[MAX][MAX];
bool visited[MAX][MAX][1 << 6]; 
pair<int, int> Start;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool haveThisKey(int k, char d) {
	int res = k & (1 << int(d - 'A'));
	return res != 0 ? true : false;
}

int move_bfs(void) {
	queue<Pos> q;
	q.push({Start.first, Start.second, 0, 0});
//	queue<pair<pair<int, int>, pair<int, int> > > q;
//	q.push(make_pair(make_pair(Start.first, Start.second), make_pair(0, 0)));
	visited[Start.first][Start.second][0] = true;
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int key = q.front().key;
//		int y = q.front().first.first;
//		int x = q.front().first.second;
//		int cnt = q.front().second.first;
//		int key = q.front().second.second;
		q.pop();
		
		if(map[y][x] == '1') return cnt;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx][key] || map[ny][nx] == '#') continue;
			
			if(map[ny][nx] == '.' || map[ny][nx] == '1'){
				q.push({ny, nx, cnt+1, key});
//				q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, key)));
				visited[ny][nx][key] = true;
			} else if('a'<=map[ny][nx] && map[ny][nx]<='f') {
				int newKey = key | (1 << (int(map[ny][nx] - 'a')));
				q.push({ny, nx, cnt+1, newKey});
//				q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, newKey)));
				visited[ny][nx][newKey] = true;
			} else if('A'<=map[ny][nx] && map[ny][nx]<='F') {
				if(haveThisKey(key, map[ny][nx])) {
					q.push({ny, nx, cnt+1, key});
//					q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, key)));
					visited[ny][nx][key] = true;
				}
			} 
		}
	}
	return -1;
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == '0') {
				Start.first = y;
				Start.second = x;
				map[y][x] = '.';
			}
		}
	}
	
	// SIMULATION
	int answer = move_bfs();
	
	// OUTPUT
	printf("%d\n", answer);
	return 0; 
}
