#include<iostream>
#include<queue>
#define MAX 200
using namespace std;

typedef struct Info {
	int y, x, horse, cnt;
} Info;

int K, W, H, map[MAX][MAX], Answer = -1;
bool visited[MAX][MAX][31];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int dhy[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dhx[] = {-1, 1, -2, 2, -1, 1, -2, 2};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> K >> W >> H;
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			cin >> map[y][x];
		}
	}
	
	// SIMULATION
	queue<Info> Q;
	Q.push({0, 0, 0, 0}); // y, x, horse, cnt
	visited[0][0][0] = true; // y, x, horse
	
	while(!Q.empty()) {
		int y = Q.front().y;
		int x = Q.front().x;
		int horse = Q.front().horse;
		int cnt = Q.front().cnt;
		Q.pop();
		
		if(y == H-1 && x == W-1) {
			Answer = cnt;
			break;
		}
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
			if(visited[ny][nx][horse] || map[ny][nx] == 1) continue;
			
			visited[ny][nx][horse] = true;
			Q.push({ny, nx, horse, cnt+1});
		}
		
		if(horse < K) {
			for(int dir=0; dir<8; dir++) {
				int ny = y + dhy[dir];
				int nx = x + dhx[dir];
				
				if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
				if(visited[ny][nx][horse+1] || map[ny][nx] == 1) continue;
				
				visited[ny][nx][horse+1] = true;
				Q.push({ny, nx, horse+1, cnt+1});	
			}
		}
		
	}
	
	// OUTPUT
	cout << Answer;
	return 0;
}
