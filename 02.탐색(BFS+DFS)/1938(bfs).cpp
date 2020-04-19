#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int N, bShape, eShape;
int map[50][50];
bool visited[50][50][2];
vector<pair<int, int> > sPoint, ePoint;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool turnBlock(int y, int x, int s) {
	if(s == 0) { // 가로 -> 세로 
		for(int i=0; i<8; i++) {
			if(i == 3 || i == 4) continue;
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) return false;
			if(map[ny][nx] == '1') return false;
		}
	} else { // 세로 -> 가로 
		for(int i=0; i<8; i++) {
			if(i == 1 || i == 6) continue;
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) return false;
			if(map[ny][nx] == '1') return false;
		}
	}
	return true;
}
int bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, int> > > q; // y, x, shape, count
	visited[y][x][bShape] = true;
	q.push(make_pair(make_pair(y, x), make_pair(bShape, 0)));
	
	while(!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cs = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		printf("%d %d %d %d \n", cy, cx, cs, cnt);
		if(cy == ePoint[1].first && cx == ePoint[1].second && cs == eShape) return cnt;
		
		if(cs == 0) { // 가로 
			// UP
			int ny = y - 1;
			int nx = x;
			if(!visited[ny][nx] && ny>=0 && nx-1>=0 && nx+1 < N) {
				if(map[ny][nx-1] != '1' && map[ny][nx] != '1' && map[ny][nx+1] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt+1)));
				}
			}
			
			// DOWN
			ny = y + 1;
			nx = x;
			if(!visited[ny][nx][cs] && ny<N && nx-1>=0 && nx+1<N) {
				if(map[ny][nx-1] != '1' && map[ny][nx] != '1' && map[ny][nx+1] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt+1)));
				}
			}
			// LEFT
			ny = y;
			nx = x - 1;
			if(!visited[ny][nx][cs] && nx-1>=0) {
				if(map[ny][nx-1] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt+1)));
				}
			}
			// RIGHT
			ny = y;
			nx = x + 1;
			if(!visited[ny][nx] && nx+1<N) {
				if(map[ny][nx+1] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt+1)));
				}
			}
			// TURN
			if(!visited[cy][cx][cs] && turnBlock(cy, cx, cs)) {
				visited[cy][cx][1] = true;
				q.push(make_pair(make_pair(cy, cx), make_pair(1, cnt+1)));
			}
		} else {
			// UP
			int ny = y - 1;
			int nx = x;
			if(!visited[ny][nx][cs] && ny-1>=0) {
				if(map[ny-1][nx] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt + 1)));
				}
			}
			// DOWN
			ny = y + 1;
			nx = x;
			if(!visited[ny][nx][cs] && ny+1<N) {
				if(map[ny+1][x] != '1'){
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt + 1)));
				}
			}
			// LEFT
			ny = y;
			nx = x - 1;
			if(!visited[ny][nx][cx] && nx>=0 && ny-1>=0 && ny+1<N) {
				if(map[ny][nx] != '1' && map[ny-1][nx] != '1' && map[ny+1][nx] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt + 1)));
				}
			}
			// RIGHT
			ny = y;
			nx = x + 1;
			if(!visited[ny][nx][cs] && nx<N && ny-1>=0 && ny+1<N) {
				if(map[ny][nx] != '1' && map[ny-1][nx] !='1' && map[ny+1][nx] != '1') {
					visited[ny][nx][cs] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(cs, cnt + 1)));
				}
			}
			// TURN
			if(!visited[cy][cx][cs] && turnBlock(cy, cx, cs)) {
				visited[cy][cx][0] = true;
				q.push(make_pair(make_pair(cy, cx), make_pair(0, cnt+1)));
			}
		}
	}
	return 0;
}

int checkShape(vector<pair<int, int> >& p) { // 가로(0) 세로(1) 
	if(p[0].first == p[1].first && p[1].first == p[2].first) { // y값이 같다(가로) 
		return 0;	
	} else {
		return 1;
	}
}

int main(void) {
	//INPUT
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == 'B') sPoint.push_back(make_pair(y, x));
			if(map[y][x] == 'E') ePoint.push_back(make_pair(y, x));
		}
	}
	
	// SIMULATION
	bShape = checkShape(sPoint);
	eShape = checkShape(ePoint);

	int answer = bfs(sPoint[1].first, sPoint[1].second);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
