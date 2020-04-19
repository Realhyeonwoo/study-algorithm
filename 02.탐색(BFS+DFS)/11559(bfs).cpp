#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

char map[12][6];
bool visited[12][6];
vector<pair<int, int> > temp, v;
int count;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(int y, int x) {
	int count = 1;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	temp.push_back(make_pair(y, x));
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop(); 
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>11 || nx<0 || nx>5) continue;
			if(visited[ny][nx] || map[ny][nx] == '.' || map[ny][nx] != map[cy][cx] ) continue;
			
			count++;
			visited[ny][nx] = true;
			temp.push_back(make_pair(ny, nx));
			q.push(make_pair(ny, nx));
		}
	}
	return count; 
}

void dfs(int y, int x) {
	for(int dir=0; dir<4; dir++){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=12 || nx<0 || nx>=6) continue;
		if(visited[ny][nx] || map[ny][nx] == '.' || map[ny][nx] != map[y][x]) continue;
		
		count++;
		visited[ny][nx] = true;
		temp.push_back(make_pair(ny, nx));
		dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	for(int y=0; y<12; y++) {
		for(int x=0; x<6; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	int answer = 0;
	while(1) {
		// RESET
		bool isBomb = false;
		memset(visited, false, sizeof(visited));
		v.clear();
		
		// 터뜨리기 
		// DFS
//		for(int y=0; y<12; y++) {
//			for(int x=0; x<6; x++) {
//				if(visited[y][x] || map[y][x] == '.') continue;
//				count = 1;
//				visited[y][x] = true;
//				temp.push_back(make_pair(y, x));
//				dfs(y, x);
//				
//				if(count >= 4) {
//					isBomb = true;
//					for(int i=0; i<temp.size(); i++) {
//						v.push_back(temp[i]);
//					}
//				}
//				temp.clear();	
//			}
//		}
		// BFS
		for(int y=0; y<12; y++) {
			for(int x=0; x<6; x++) {
				if(visited[y][x] || map[y][x] == '.') continue;
				
				if(bfs(y, x) >= 4) {
					isBomb = true;
					for(int i=0; i<temp.size(); i++) {
						v.push_back(temp[i]);
					}
				}
				temp.clear();	
			}
		}
		
		for(int i=0; i<v.size(); i++) {
			map[v[i].first][v[i].second] = '.';
		}
		
		// 아래로 끌어당기기 
		for(int y=10; y>=0; y--) {
			for(int x=0; x<6; x++) {
				if(map[y][x] == '.') continue;
				int temp = y;
				while(1) {
					if(temp == 11 || map[temp+1][x] != '.') break;
					
					map[temp+1][x] = map[temp][x];
					map[temp][x] = '.';
					temp++;
				}					
			}
		}
		// 터뜨렸는지 검사(아니면 반복문 탈출) 
		if(!isBomb) break;
		answer++;
		
		
	}
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
