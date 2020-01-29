#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int m, n, h;
int map[100][100][100];
int visited[100][100][100] = {false, };
int day = 0; 

void bfs(int i, y, x) {
	queue< tuple<int, int, int> > q;
	q.push(make_tuple(i, y, x));
	visited[i][y][x] = true;
	
	while(!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();
		
		int i = get<0>(cur);
		int y = get<1>(cur);
		int x = get<2>(cur);
		
		map[i][y][x] = 1;
		int dy[] = { -1, 1, 0, 0, 0, 0};
		int dx[] = { 0, 0, -1, 1, 0, 0};
		int dz[] = { 0, 0, 0, 0, 1, -1};
		for(int dir=0; dir<6; dir++) {
			int nh = i + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(nh<0 || nh>=h || ny<0 || ny>=y || nx<0 || nx>=x) continue;
			if(!visited[nh][ny][nx] && map[nh][hy][nx] == 0) {
				visited[nh][ny][nx = true;]
			}
		}
		
	}
}

int main(void){
	scanf("%d %d %d", &m, &n, &h);
	for(int i=0; i<h; i++) {
		for(int y=0; y<m; y++) {
			for(int x=0; x<n; x++) {
				scanf("%d", &map[i][y][x]);
			}
		}
	}
	
	for(int i=0; i<h; i++) {
		for(int y=0; y<m; y++) {
			for(int x=0; x<n; x++) {
				bfs(i, y, x);
			}
		}
	}
	
	return 0; 
}
