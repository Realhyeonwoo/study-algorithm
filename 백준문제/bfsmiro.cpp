#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int map[8][8] = {  		{0,0,1,1,1,1,1,1},
						{1,0,0,0,0,0,0,1},
						{1,1,1,0,1,1,1,1},
						{1,1,1,0,1,1,1,1},
						{1,0,0,0,0,0,0,1},
						{1,0,1,0,1,1,1,1},
						{1,0,0,0,0,0,0,0},
						{1,1,1,1,1,1,1,5}
			};
bool v[8][8] = { false, };
int count[8][8] = {1, };

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		int cy = cur.first;
		int cx = cur.second;
		
		if(map[cy][cx] == 5) {
			printf("arrived: \n");
			return;
		}
	
		v[cy][cx] = true;
		
		int dx[] = { -1, 1, 0, 0};
		int dy[] = { 0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
		
			if(ny<0 || ny>=8 || nx<0 || nx>=8) continue;
			if(v[ny][nx] || map[ny][nx]==1) continue;
		
			v[ny][nx] = true;
			q.push(make_pair(ny, nx));
			count[ny][nx] = count[cy][cx] + 1;
		}
	}
}

int main(void) {
	bfs(0, 0); 
	
	for(int y=0; y<8; y++) {
		for(int x=0; x<8; x++) {
			printf("%d ", count[y][x]);
		}
		printf("\n");
	}
	return 0;
}
