#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
using namespace std;

typedef struct {
	int y, x, cnt;
}Info;

int N, Answer = 987564321;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void numberdIsland(int num) {
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++) {
			if(map[y][x] == -1 && !visited[y][x]) {
				queue<pair<int, int> > Q;
				Q.push(make_pair(y, x));
				visited[y][x] = true;
				map[y][x] = num;
				while(!Q.empty()) {
					int cy = Q.front().first;
					int cx = Q.front().second;
					Q.pop();
					
					for(int dir=0; dir<4; dir++) {
						int ny = cy + dy[dir];
						int nx = cx + dx[dir];
						
						if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
						if(visited[ny][nx] || map[ny][nx] == 0) continue;
						
						visited[ny][nx] = true;
						map[ny][nx] = num;
						Q.push(make_pair(ny, nx));
					}
				}
				num++;
			}
		}
	}
}

int getBridgeLength(int a, int b, int num) {
	queue<Info> Q;
	Q.push({a, b, 0});
	visited[a][b] = true;
	
	while(!Q.empty()) {
		int y = Q.front().y;
		int x = Q.front().x;
		int cnt = Q.front().cnt;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx] == num) {
				Q.push({ny, nx, cnt});
				visited[ny][nx] = true;
			} else if(map[ny][nx] == 0) {
				Q.push({ny, nx, cnt + 1});
				visited[ny][nx] = true;
			} else {
				return cnt;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N;
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++) {
			cin >> map[y][x];
			if(map[y][x] == 1) map[y][x] = -1;
		}
	}
	
	// SIMULATION
	numberdIsland(1);
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] != 0) {
				for(int i=0; i<MAX; i++) fill(visited[i], visited[i]+MAX, false);
				Answer = min(Answer, getBridgeLength(y, x, map[y][x]));
			}
		}
	}
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}

//	cout << '\n';
//	for(int y=0; y<N; y++){
//		for(int x=0; x<N; x++) {
//			cout << map[y][x] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
