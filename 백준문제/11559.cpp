#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#define ROW 12
#define COL 6
using namespace std;

char map[ROW][COL];
bool visited[ROW][COL];
int Answer;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isBreak(void) {
	bool isDestroy = false;
	
	for(int y=ROW-1; y>=0; y--) {
		for(int x=0; x<COL; x++) {
			if(map[y][x] != '.') {
				vector<pair<int, int> > V;
				V.push_back(make_pair(y, x));
				queue<pair<int, int> > Q;
				Q.push(make_pair(y, x));
				visited[y][x] = true;
				
				while(!Q.empty()) {
					int y = Q.front().first;
					int x = Q.front().second;
					Q.pop();
					
					for(int dir=0; dir<4; dir++) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						
						if(ny<0 || ny>=ROW || nx<0 || nx>=COL) continue;
						if(map[ny][nx] == '.' || visited[ny][nx]) continue;
						if(map[ny][nx] == map[y][x]) {
							Q.push(make_pair(ny, nx));
							V.push_back(make_pair(ny, nx));
							visited[ny][nx] = true;
						}
					}
				}
				if(V.size() >= 4) {
					isDestroy = true;
					for(int i=0; i<V.size(); i++) map[V[i].first][V[i].second] = '.';
				}
			}
		}
	}
	return isDestroy;
}

void moveDown(void) {
	for(int x=0; x<COL; x++){
		for(int y=ROW-2; y>=0; y--){
			if(map[y][x] != '.')	{
				int ny = y+1;
				while(ny<ROW && map[ny][x] == '.') ny++;
				if(ny-1 != y) {
					map[ny-1][x] = map[y][x];
					map[y][x] = '.';	
				}
			}
		}
	}
}

int main(void) {
	// INPUT
	string str;
	for(int y=0; y<ROW; y++) {
		cin >> str;
		for(int x=0; x<COL; x++) map[y][x] = str[x];
	}
	
	// SIMULATION
	while(1) {
		if(!isBreak()) break;
		moveDown();
		Answer++;
		for(int y=0; y<ROW; y++) fill(visited[y], visited[y] + COL, false);
	}
	
	// OUTPUT
	cout << Answer;
	return 0;
}
