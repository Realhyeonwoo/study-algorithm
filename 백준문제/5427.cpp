#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#define MAX 1000
#define INF 987654321
using namespace std;

typedef struct {
	int y, x, time;	
} Info;

int w, h;
char map[MAX][MAX];
int fireMap[MAX][MAX];
queue<pair<int, int> > fireQ;
bool visited[MAX][MAX];
pair<int, int> Start;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void spreadFire(void) {
	while(!fireQ.empty()) {
		int qSize = fireQ.size();
		for(int i=0; i<qSize; i++) {
			int y = fireQ.front().first;
			int x = fireQ.front().second;
			fireQ.pop();
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
				if(fireMap[ny][nx] == -1 || fireMap[ny][nx] != INF) continue;
				
				fireMap[ny][nx] = fireMap[y][x] + 1;
				fireQ.push(make_pair(ny, nx));
			}
		}
	}
}

int findExit(int a, int b) {
	queue<Info> Q;
	Q.push({a, b, 0});
	visited[a][b] = true;
	
	while(!Q.empty()) {
		int y = Q.front().y;
		int x = Q.front().x;
		int time = Q.front().time;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=h || nx<0 || nx>=w) return time + 1;
			
			if(map[ny][nx] == '#' || visited[ny][nx]) continue;
			if(fireMap[ny][nx] <= time + 1) continue;
			
			visited[ny][nx] = true;
			Q.push({ny, nx, time+1});
		}
	}
	
	return -1;	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		// INIT
		for(int y=0; y<MAX; y++) {
			fill(map[y], map[y] + MAX, 0);
			fill(fireMap[y], fireMap[y] + MAX, INF);
			fill(visited[y], visited[y] + MAX, false);
				
		}
		
		// INPUT
		string str;
		cin >> w >> h;
		for(int y=0; y<h; y++) {
			cin >> str;
			for(int x=0; x<w; x++) {
				map[y][x] = str[x];
				if(map[y][x] == '@') Start = {y, x};
				else if(map[y][x] == '*') {
					fireQ.push(make_pair(y, x));
					fireMap[y][x] = 0;
				} else if(map[y][x] == '#') {
					fireMap[y][x] = -1;
				}
			}
		}
		
		// SIMULATION
		spreadFire();
		int Answer = findExit(Start.first, Start.second);
		
		// OUTPUT
		if(Answer == -1) cout << "IMPOSSIBLE\n";
		else cout << Answer << '\n';
	}
	return 0;
}
