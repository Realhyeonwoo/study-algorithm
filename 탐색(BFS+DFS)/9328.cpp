#include<iostream>
#include<string>
#include<queue>
#include<cstring>

#define MAX 111
using namespace std;

int h, w, answer;
char map[MAX][MAX];
bool visited[MAX][MAX];
string First_Key;
bool keys[26];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(void) {
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
				if(keys[map[ny][nx] - 'A']) {
					q.push(make_pair(ny, nx));
				} else {
					Door[map[ny][nx] - 'A'].push(make_pair(ny, nx));
				}
			} else if('a'<= map[ny][nx] && map[ny][nx]<='z') {
				q.push(make_pair(ny, nx));
				if(!keys[map[ny][nx] - 'a']) {
					keys[map[ny][nx] - 'a'] = true;
					while(Door[map[ny][nx] - 'a'].empty() == 0) {
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
		memset(keys, false, sizeof(keys));
		First_Key.clear();
		answer = 0;
				
		// INPUT
		scanf("%d %d", &h, &w);
		for(int y=1; y<=h; y++) {
			for(int x=1; x<=w; x++) {
//				cin >> map[y][x];
				scanf(" %c", &map[y][x]);
			}
		}
		
		 cin >> First_Key;
    for (int i = 0; i < First_Key.length(); i++)
    {
        if (First_Key[i] == '0') continue;
        keys[First_Key[i] - 'a'] = true;
    }

		
		// SIMULATION
		bfs();
		
		// OUTPUT
		printf("%d\n", answer);
	
	}
	return 0;
}
