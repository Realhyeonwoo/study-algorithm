#include<iostream>
#include<queue>
#define MAX 1500
using namespace std;

int R, C;
char map[MAX][MAX], cpyMap[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> Start, End;
queue<pair<int, int> > Q, mQ, tQ;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isMeet(void) {
	while(!mQ.empty()) {
		int y = mQ.front().first;
		int x = mQ.front().second;
		mQ.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(!visited[ny][nx] && map[ny][nx] == 'L') return true;
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx] == '.') {
				visited[ny][nx] = true;
				mQ.push(make_pair(ny, nx));	
				continue;
			}
			if(map[ny][nx] == 'X') {
				visited[ny][nx] = true;
				tQ.push(make_pair(ny, nx));
			}
		}
	}
	return false;
}

void copyMap(char res[][MAX], char temp[][MAX]) {
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			res[y][x] = temp[y][x];
		}
	}
}

void meltIce(void) {
//	copyMap(cpyMap, map);
	
//	while(!Q.empty()) {
		int qSize = Q.size();
		for(int i=0; i<qSize; i++) {
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();
			
			bool isMelt = false;
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
				if(map[ny][nx] == 'X') {
					map[ny][nx] = '.';
					Q.push(make_pair(ny, nx));
				}
			}
		}
//	}
	
//	copyMap(map, cpyMap);
}

int main(void) {
	// INPUT
	cin >> R >> C;
	string str;
	int temp = 0;
	for(int y=0; y<R; y++) {
		cin >> str;
		for(int x=0; x<C; x++) {
			map[y][x] = str[x];
			if(str[x] != 'X') Q.push(make_pair(y, x));
			if(str[x] == 'L') {
				if(temp == 0) {
					Start = {y, x};
					visited[y][x] = true;
					mQ.push(make_pair(y, x));
					temp++;
				} else {
					End = {y, x};
				}
			}
		}
	}
	// SIMULATION
	int Answer = 0;
	while(1) {
		if(isMeet()) break;
		meltIce();
		
		Answer++;
		
		mQ = tQ;
		while(!tQ.empty()) tQ.pop();
		
//		cout << "################################\n";
//		for(int y=0; y<R; y++) {
//			for(int x=0; x<C; x++) {
//				cout << map[y][x] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << "################################\n";
	}
	
	// OUTPUT
	cout << Answer;
	return 0;
}
