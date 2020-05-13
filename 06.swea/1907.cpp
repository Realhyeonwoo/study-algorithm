#include<iostream>
#include<vector>
#include<queue>

#define MAX 1000
using namespace std;

int H, W, Answer;
int map[MAX][MAX];
queue<pair<int, int> > q;

int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs() {
	int qSize = q.size();
	
	for(int i=0; i<qSize; i++) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<8; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
			if(map[ny][nx] != 0) {
				map[ny][nx]--;
				if(map[ny][nx] == 0) q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		Answer = 0;
		
		// INPUT
		scanf("%d %d", &H, &W);
		for(int y=0; y<H; y++) {
			for(int x=0; x<W; x++) {
				char c;
				scanf(" %c", &c);
				if(c != '.') map[y][x] = c - '0';
				else q.push(make_pair(y, x));
			}
		}
		
		// SIMULATION
		while(1) {
			bfs();
			if(q.size() == 0) break;
			Answer++;
		}
		
		// OUTPUT
		printf("#%d %d\n", tc, Answer);
	}
	return 0;
}
