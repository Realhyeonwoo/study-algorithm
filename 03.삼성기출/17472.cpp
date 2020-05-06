#include<iostream>
#include<queue>
#include<algorithm>

#define MAX 10
#define INF 987564321
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int island[7][7];
int num[7];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

class Edge {
	public:
		int a, b, value;
		Edge(int a, int b, int value) {
			this->a = a;
			this->b = b;
			this->value = value;
		}
		bool operator < (Edge& e) {
			return this->value < e.value;
		}
};

int getParent(int x) {
	if(x == num[x]) return x;
	return getParent(num[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if(a < b) num[b] = a;
	else num[a] = b;
}

bool isCycle(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b ? true : false;
}

void bfs(int a, int b, int cnt) {
	visited[a][b] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		map[y][x] = cnt;
		
		for(int dir=0; dir<4; dir++ ){
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx] || map[ny][nx] != -1) continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}	
	}
}

void calcDistanceToOtherIslands(int y, int x, int num) {
	int ny, nx;
	// 동 
	nx = x + 1;
	while(1) {
		if(nx >= M) break;
		if(map[y][nx] == num) break;
		if(map[y][nx] != 0) {
			if(nx-x-1 >= 2) {
				island[num][map[y][nx]] = min(island[num][map[y][nx]], nx - x - 1);
				island[map[y][nx]][num] = island[num][map[y][nx]];
			}
			break;
		}
		nx++;
	}
	// 서
	nx = x - 1;
	while(1) {
		if(nx < 0) break;
		if(map[y][nx] == num) break;
		if(map[y][nx] != 0) {
			if(nx-x-1 >= 2) {
				island[num][map[y][nx]] = min(island[num][map[y][nx]], nx - x -1);
				island[map[y][nx]][num] = island[num][map[y][nx]];
			}
			break;
		}
		nx--;
	}
	// 남
	ny = y + 1;
	while(1) {
		if(ny >= N) break;
		if(map[ny][x] == num) break;
		if(map[ny][x] != 0) {
			if(ny-y-1 >= 2) {
				island[num][map[ny][x]] = min(island[num][map[ny][x]], ny - y - 1);
				island[map[ny][x]][num] = island[num][map[ny][x]];
			}
			break;
		}
		ny++;
	}
	// 북 
	ny = y - 1;
	while(1) {
		if(ny < 0) break;
		if(map[ny][x] == num) break;
		if(map[ny][x] != 0) {
			if(ny-y-1 >= 2) {
				island[num][map[ny][x]] = min(island[num][map[ny][x]], ny - y - 1);
				island[map[ny][x]][num] = island[num][map[ny][x]];
			}
			break;
		}
		ny--;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) map[y][x] = -1;
		}
	}
	
	// SIMULATION
	int islandNum = 1;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == -1 && !visited[y][x]) {
				bfs(y, x, islandNum);
				islandNum++;
			}
		}
	}
	
	// KRUSUKAL 변수 셋팅 	
	for(int i=1; i<7; i++) num[i] = i;
	for(int y=1; y<7; y++) {
		for(int x=1; x<7; x++) {
			island[y][x] = INF;
			if(y == x) island[y][x] = 0; 
		}
	}
	 
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] != 0) calcDistanceToOtherIslands(y, x, map[y][x]);
		}
	}
	
	vector<Edge> v;
	for(int i=1; i<islandNum; i++) {
		for(int j=1; j<islandNum; j++) {	
			if(island[i][j] != 0 && island[i][j] != INF) {
				v.push_back({i, j, island[i][j]});
				island[j][i] = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	
	int sum = 0;
	for(int i=0; i<v.size(); i++) {
		if(!isCycle(v[i].a, v[i].b)) {
			sum += v[i].value;
			unionParent(v[i].a, v[i].b);
		}
	}
	int count = 0;
	for(int i=1; i<islandNum; i++) {
		if(num[i] == i) count++;
	}
	
	// OUTPUT
	if(count > 1 || sum == 0) printf("-1\n");
	else printf("%d\n", sum);
	
	return 0;
}
