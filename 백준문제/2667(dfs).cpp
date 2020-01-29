#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, cnt;
int map[25][25];
vector<int> answer;

void dfs(int y, int x) {
	map[y][x] = 0;
	cnt++;
	
	int dy[] = { -1, 1, 0, 0};
	int dx[] = { 0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=n || nx<0 || nx>=0) continue;
		if(!map[ny][nx]) continue;
		dfs(ny, nx);
	}
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
			if(map[y][x]) {
				cnt = 0; 
				dfs(y, x);
				answer.push_back(cnt);
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	int len = answer.size();
	printf("%d\n", len)
	for(int i=0; i<len; i++) {
		printf("%d\n", answer[i]);
	}
	
	return 0; 
}

