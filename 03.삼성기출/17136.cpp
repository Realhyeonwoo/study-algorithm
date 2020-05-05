#include<iostream> 
#include<queue>
#define MAX 10
using namespace std;

typedef struct {
	int width, height;
}Info;

int map[MAX][MAX];
bool visited[MAX][MAX];
vector<Info> v;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int a, int b) {
	int width = 0, height = 0;
	
	visited[a][b] = true;
	queue<pair<int, int> > 	q;
	q.push(make_pair(a, b));
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=10 || nx<0 || nx>=10) continue;
			if(visited[ny][nx] || map[ny][nx] == 0) continue;
			
			visited[ny][nx] = true;
			if(dir == 0 || dir == 1) width++;
			else if(dir == 2 || dir == 3) height++;
			q.push(make_pair(ny, nx));
		}
	}
	v.push_back({width, height});
}

int main(void) {
	// INPUT
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			if(map[y][x] == 1 && !visited[y][x]) bfs(y, x); 
		}
	}
	
	for(int i=0; i<v.size(); i++) {
		printf("%d %d \n", v[i].width, v[i].height);
	}
	// OUTPUT
	if(v.size() == 0) printf("0\n");
	else {
		
	}
	return 0;
}
