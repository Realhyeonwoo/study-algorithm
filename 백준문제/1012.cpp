#include<iostream>
#include<queue>
#define MAX 50
using namespace std;

int M, N, K; // 가로(M) 세로(N)
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > Q;
int Answer;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		// INIT
		Answer = 0;
		for(int y=0; y<MAX; y++) {
			fill(map[y], map[y] + MAX, 0);
			fill(visited[y], visited[y] + MAX, false);
		}
		
		// INPUT
		cin >> M >> N >> K;
		int y, x;
		for(int i=0; i<K; i++) {
			cin >> y >> x;
			map[y][x] = 1;
		}
		
		// SIMULATION
		for(int y=0; y<M; y++) {
			for(int x=0; x<N; x++) {
				if(map[y][x] == 0 || visited[y][x]) continue;
				
				Answer++;
				visited[y][x] = 1;
				Q.push(make_pair(y, x));
				
				while(!Q.empty()) {
					int y = Q.front().first;
					int x = Q.front().second;
					Q.pop();
					
					for(int dir=0; dir<4; dir++) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						
						if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
						if(map[ny][nx] == 0 || visited[ny][nx]) continue;
						
						visited[ny][nx] = true;
						Q.push(make_pair(ny, nx));
					}
				}
			}
		}
		
		// OUTPUT
		cout << Answer << '\n';
	}
		
	return 0;
}
