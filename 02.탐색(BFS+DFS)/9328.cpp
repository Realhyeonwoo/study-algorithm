#include<iostream>
#include<queue>
#include<cstring>
#include<string>

#define MAX 102
using namespace std;

int h, w, answer;
char map[MAX][MAX];
bool visited[MAX][MAX];
string strKey;
bool key[26];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs() {
	queue<pair<int, int> > q;
	queue<pair<int, int> > Door[26];
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
				
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>h+1 || nx<0 || nx>w+1) continue;
			if(map[ny][nx] == '*' || visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			if('A'<=map[ny][nx] && map[ny][nx]<='Z') {
				if(key[map[ny][nx] - 'A']) {
					q.push(make_pair(ny, nx));
				} else {
					Door[map[ny][nx] - 'A'].push(make_pair(ny, nx));
				}
			} else if('a'<=map[ny][nx] && map[ny][nx]<='z') {
				q.push(make_pair(ny, nx));
				if(!key[map[ny][nx] - 'a']) {
					key[map[ny][nx] - 'a'] = true;
					while(!Door[map[ny][nx] - 'a'].empty()) {
						q.push(Door[map[ny][nx] - 'a'].front());
						Door[map[ny][nx] - 'a'].pop();
					}
				}
			} else {
				q.push(make_pair(ny, nx));
				if(map[ny][nx] == '$') answer++;
			}
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		memset(key, false, sizeof(key));
		strKey.clear();
		answer = 0;
		
		// INPUT
		scanf("%d %d", &h, &w);
		for(int y=1; y<=h; y++) {
			for(int x=1; x<=w; x++) {
				scanf(" %c", &map[y][x]);
			}
		}
		cin >> strKey;
		for(int i=0; i<strKey.length(); i++) {
			if(strKey[i] == '0') continue;
			key[strKey[i] - 'a'] = true;
		}
		
		// SIMULATION
		bfs();
		
		// OUTPUT
		printf("%d\n", answer);
	}
	return 0; 
}

