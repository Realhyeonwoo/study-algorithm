#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int N;
int map[25][25];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int makeGroup_bfs(int y, int x) {
	int count = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x)); 
	map[y][x] = 0; 
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		int cy = cur.first;
		int cx = cur.second;
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir]; 
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(map[ny][nx] == 0) continue;
			map[ny][nx] = 0;
			count++; 
			q.push(make_pair(ny, nx));
		}
	}
	
	return count; 
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	// HOUSE_CHECK(BFS)
	vector<int> answer;
	int number = 0; 
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 1) {
				number++; 
				answer.push_back(makeGroup_bfs(y, x));
			}
		}
	}
	// SORT
	sort(answer.begin(), answer.end());
	
	// OUTPUT
	printf("%d\n", number); 
	for(int i=0; i<answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}
