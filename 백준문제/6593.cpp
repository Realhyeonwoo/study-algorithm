#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#define MAX 30
using namespace std;

typedef struct {
	int h, y, x, time;
} Info;

int L, R, C;
char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
pair<int, pair<int, int> > Start, End;

int dh[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};

int bfs(int c, int a, int b) {
	queue<Info> Q;
	Q.push({c, a, b, 0});
	visited[c][a][b] = true;
	
	while(!Q.empty()) {
		int h = Q.front().h;
		int y = Q.front().y;
		int x = Q.front().x;
		int time = Q.front().time;
		Q.pop();	
		
		if(End.first == h && End.second.first == y && End.second.second == x) return time;
		
		for(int dir=0; dir<6; dir++) {
			int nh = h + dh[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C || nh<0 || nh>=L) continue;
			if(map[nh][ny][nx] == '#' || visited[nh][ny][nx]) continue;
			
			visited[nh][ny][nx] = true;
			Q.push({nh, ny, nx, time+1});
		}
	}
	
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1) {
		// INIT
		for(int l=0; l<L; l++) {
			for(int y=0; y<R; y++){
					fill(map[l][y], map[l][y]+MAX, 0);
					fill(visited[l][y], visited[l][y]+MAX, false);
			}
		}
		// INPUT
		string str;
		cin >> L >> R >> C;
		if(L == 0 && R == 0 && C == 0) break;
		
		for(int l=0; l<L; l++) {
			for(int y=0; y<R; y++){
				cin >> str;
				for(int x=0; x<C; x++) {
					map[l][y][x] = str[x];
					if(str[x] == 'S') Start = {l, make_pair(y, x)};
					else if(str[x] == 'E') End = {l, make_pair(y, x)};
				}
			}
		}
		
		// SIMULATION
		int Answer = bfs(Start.first, Start.second.first, Start.second.second);
		
		// OUTPUT	
		if(Answer == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << Answer << " minute(s).\n";
	}
	
	return 0;
}
