#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

int n;
int map[25][25];
bool visited[25][25] = { false, };
vector<int> group;
int groupNum = -1;

void bfs(pair<int, int> pos) {
	queue< pair<int, int> > q;
	q.push(pos);
	visited[pos.first][pos.second] = true;
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cy = cur.first;
		int cx = cur.second;
		
		map[cy][cx] = groupNum;
		
		int dy[] = { -1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
			if(!visited[ny][nx] && map[ny][nx] == 1) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
	groupNum--;
}

int main(void) {
	scanf("%d", &n); 
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(map[y][x] == 1) {
				bfs(make_pair(y, x));
			}
		}
	}
	
	groupNum += 1;
	int count = groupNum * (-1);
	printf("%d\n", count);
	
	for(int i=groupNum; i<=-1; i++) {
		count = 0; 
		for(int y=0; y<n; y++) {
			for(int x=0; x<n; x++) {
				if(map[y][x] == i) {
					count++;
				}
			}
		}
		group.push_back(count);
	}
	
	sort(group.begin(), group.end());
	for(int i=0; i<group.size(); i++) {
		printf("%d\n", group[i]); 
	}

	return 0; 
}
