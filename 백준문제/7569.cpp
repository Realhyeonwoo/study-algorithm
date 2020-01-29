#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int m, n, h;
int map[100][100][100];
int visited[100][100][100] = {false, };
vector< pair<int, pair<int, int> > > check;
int day = 0; 

void bfs(int sh, int sy, int sx) {
	queue< pair<int, pair<int, int> > > q;
	q.push(make_pair(sh, make_pair(sy, sx)));
	visited[sh][sy][sx] = true;
	
	pair<int, pair<int, int> > last = q.front();
	while(!q.empty()) {
		pair<int, pair<int, int> > cur = q.front();
		q.pop();
		
		int i = cur.first;
		int y = cur.second.first;
		int x = cur.second.second;
		
		for(int j=0; j<check.size(); j++) {
			if(i==check[j].first && y==check[j].second.first && x==check[j].second.second) {
				day++;
				printf("day++ [%d %d %d] = %d\n", i, y, x, day);
				break;
			}	
		}
		
//		printf("%d %d %d\n", i, y, x);
		map[i][y][x] = 1;
		
		// 상 하 좌 우 아래  
		int dz[] = { 0, 0, 0, 0, -1, 1};
		int dy[] = { -1, 1, 0, 0, 0, 0};
		int dx[] = { 0, 0, -1, 1, 0, 0};
		printf("========== new queue push =============\n");
		for(int dir=0; dir<6; dir++) {
			int nh = i + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if(nh<0 || nh>=h || ny<0 || ny>=n || nx<0 || nx>=m) continue;
			
			if(!visited[nh][ny][nx] && map[nh][ny][nx] == 0) {
				visited[nh][ny][nx] = true;
				q.push(make_pair(nh, make_pair(ny, nx)));
				printf("[%d %d %d]\n", nh, ny, nx);
			}
		}
		printf("=======================================\n");
		printf("last queue\n");
		printf("=======================================\n");
		if(!q.empty()) {
			check.push_back(make_pair(q.back().first, make_pair(q.back().second.first, q.back().second.second)));
			printf("%d %d %d \n", q.back().first, q.back().second.first, q.back().second.second);
		}
		printf("=======================================\n");
	}
}

int main(void){
	scanf("%d %d %d", &m, &n, &h);
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				scanf("%d", &map[i][y][x]);
			}
		}
	}
	
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				if(!visited[i][y][x] && map[i][y][x] == 1) {
					bfs(i, y, x);	
				}
			}
		}
	}
	
	printf("\n");
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				printf("%d ", map[i][y][x]);
			}
			printf("\n");
		}
	}
	
	printf("%d\n", day);
	return 0; 
}
