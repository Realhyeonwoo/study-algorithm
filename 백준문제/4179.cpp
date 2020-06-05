#include<iostream>
#include<queue>
#include<string>
#define MAX 1000
#define INF 987564321
using namespace std;

int R, C, map[MAX][MAX], fireMap[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > Q;
pair<int, int> Jihun;
int Answer;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void spreadFire(void) {
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(visited[ny][nx] || fireMap[ny][nx] == -1) continue;
			
			fireMap[ny][nx] = fireMap[y][x] + 1;
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
}

int moveJihun(int a, int b) {
	while(!Q.empty()) Q.pop();
	
	Q.push(make_pair(a, b));
	visited[a][b] = true;
	
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;	
		Q.pop();
		
//		if(y == 0 || y == R-1 || x == 0 || x == C-1) return map[y][x] + 1;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) {
				return map[y][x] + 1;
			}
			
			if(visited[ny][nx] || map[ny][nx] == -1) continue;
			if(fireMap[ny][nx] >= 0 && fireMap[ny][nx] <= map[y][x] + 1) continue; 
			
			map[ny][nx] = map[y][x] + 1;
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
	
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	string str;
	cin >> R >> C;
	for(int y=0; y<R; y++) {
		fill(fireMap[y], fireMap[y]+C, INF);
	}
	for(int y=0; y<R; y++) {
		cin >> str;
		for(int x=0; x<C; x++) {
			if(str[x] == '#') {
				map[y][x] = -1;
				fireMap[y][x] = -1;
			} else if(str[x] == 'J') Jihun = {y, x};
			else if(str[x] == 'F') {
				Q.push(make_pair(y, x));
				fireMap[y][x] = 0;
				visited[y][x] = true;
			}
		}
	}
	
	// SIMULATION
	spreadFire();
	for(int y=0; y<R; y++) fill(visited[y], visited[y] + C, false);
	Answer = moveJihun(Jihun.first, Jihun.second);
	
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			cout << fireMap[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			cout << map[y][x] << ' ';
		}
		cout << '\n';
	}
	
	// OUTPUT
	if(Answer == 0) cout << "IMPOSSIBLE" << '\n';
	else cout << Answer << '\n';
	return 0;
}

