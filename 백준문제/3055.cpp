#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#define INF -987654321
#define MAX 50
using namespace std;

int R, C, Answer;
char map[MAX][MAX];
int waterMap[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > Q;
pair<int, int> Start; 

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void spreadWater(void) {
	while(!Q.empty())	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
			if(waterMap[ny][nx] != INF) continue;
			waterMap[ny][nx] = waterMap[y][x] + 1;
			Q.push(make_pair(ny, nx));
		}
	}
}

bool move(void) {
	Q.push(make_pair(Start.first, Start.second));
	visited[Start.first][Start.second] = true;
	
	while(!Q.empty()) {
		int qSize = Q.size();
		Answer++;
		for(int i=0; i<qSize; i++)	 {
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(map[ny][nx] == 'D') return true;
				
				if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
				if(map[ny][nx] == '*' || map[ny][nx] == 'X' || visited[ny][nx]) continue;
				if(waterMap[ny][nx] >=0 && waterMap[ny][nx] <= Answer) continue;
				
				visited[ny][nx] = true;
				Q.push(make_pair(ny, nx));
			}
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INIT
	for(int y=0; y<MAX; y++) fill(waterMap[y], waterMap[y] + MAX, INF);
	
	// INPUT
	string str;
	cin >> R >> C;
	for(int y=0; y<R; y++) {
		cin >> str;
		for(int x=0; x<C; x++) {
			map[y][x] = str[x];
			if(map[y][x] == 'S') {
				map[y][x] = '.';
				Start = {y, x};
			} else if(map[y][x] == '*'){
				Q.push(make_pair(y, x));
				waterMap[y][x] = 0;
			}
		}
	}
	
	// SIMULATION
	spreadWater();
	bool isEscape = move();

	
	// OUTPUT
	if(!isEscape) cout << "KAKTUS";
	else cout << Answer; 
	return 0;
}
