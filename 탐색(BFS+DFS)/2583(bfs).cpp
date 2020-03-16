#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int M, N, K; // 세로(M), 가로(N) 
int map[100][100];
bool visited[100][100];
vector<int> answer;
int space;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	map[y][x] = 1;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
			if(visited[ny][nx] || map[ny][nx] == 1) continue;
			
			visited[ny][nx] = true;
			map[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			space++;
		}
	}
}
int main(void) {
	// INPUT
	scanf("%d %d %d", &M, &N, &K);
	int x1, y1, x2, y2;
	for(int i=0; i<K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
		for(int y=y1; y<=y2-1; y++)	{
			for(int x=x1; x<=x2-1; x++)	{
				map[y][x] = 1;
			}
		}
	}
	
	// SIMULATION
	for(int y=0; y<M; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 0) {
				space = 1;
				memset(visited, false, sizeof(visited));
				bfs(y, x);
				answer.push_back(space);
			}
		}
	}
	
	// OUTPUT
	int size = answer.size(); 
	sort(answer.begin(), answer.end());
	printf("%d\n", size);
	for(int i=0; i<size; i++) {
		printf("%d ", answer[i]);
	}
	
	
	return 0;
}
