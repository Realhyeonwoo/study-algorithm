#include<iostream> 
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[1000][1000];
bool visited[1000][1000];
//int value[1000][1000];
int answer;
queue<pair<int, int> > q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs() {
	while(!q.empty()) {
		int q_size = q.size();
		
		for(int i=0; i<q_size; i++)	 {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<0 || ny>=N || nx<0 || nx>=M)continue;
				if(visited[ny][nx] || map[ny][nx] != 0) continue;
				
				visited[ny][nx] = true;
				map[ny][nx] = 1;
				q.push(make_pair(ny, nx));	
			}
		}
		if(!q.empty()) answer++;
	}
}

int main(void) {
	scanf("%d %d", &M, &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) {
				q.push(make_pair(y, x));
				visited[y][x] = true;
			}
		}
	}
	
	bfs();
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == 0) {
				printf("-1\n");				
				return 0;
			}
		}
	}
	
	printf("%d\n", answer);
	
	return 0;
}
