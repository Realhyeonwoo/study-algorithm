#include<iostream>
#include<queue>
#define MAX 501
using namespace std;

int n, m; // 세로(n) 가로(m)
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visited[a][b] = true;
	
	int sum = 0;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		sum++;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(map[ny][nx] == 0 || visited[ny][nx]) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return sum;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// INPUT
	cin >> n >> m;
	for(int y=0; y<n; y++) {
		for(int x=0; x<m; x++) {
			cin >> map[y][x];
		}
	}
	
	// SIMULATION
	int count = 0, size = -987654321;
	for(int y=0; y<n; y++) {
		for(int x=0; x<m; x++) {
			if(map[y][x] == 1 && !visited[y][x]) {
				size = max(size, bfs(y, x));
				count++;
			}
		}
	}
	
	// OUTPUT
	cout << count << '\n';
	cout << (count == 0 ? 0 : size) << '\n';
	
	return 0;
}
