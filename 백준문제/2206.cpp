#include<iostream>
#include<string>
#include<queue>
#define MAX 1001
using namespace std;

typedef struct {
	int y, x, cnt, power;
} Info;

int N, M, Answer, map[MAX][MAX];
bool visited[MAX][MAX][2];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs(int a, int b) {
	queue<Info> Q;
	Q.push({a, b, 1, 0}); // y x cnt power 
	visited[a][b][0] = true; // y x cnt power
	
	while(!Q.empty()) {
		int y = Q.front().y;
		int x = Q.front().x;
		int cnt = Q.front().cnt;
		int power = Q.front().power;
		Q.pop();
		
		if(y == N && x == M) return cnt;
		
		if(power == 0) {
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<1 || ny>N || nx<1 || nx>M) continue;
				if(visited[ny][nx][power+1]) continue;
				if(map[ny][nx] == 1) {
					visited[ny][nx][power+1] = true;
					Q.push({ny, nx, cnt+1, power+1});
				}
			}	
		}
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<1 || ny>N || nx<1 || nx>M) continue;
			if(visited[ny][nx][power] || map[ny][nx] == 1) continue;
			visited[ny][nx][power] = true;
			Q.push({ny, nx, cnt+1, power});
		}
	}
	return -1;
}
int main(void) {
	// INPUT
	cin >> N >> M;
	string str;
	for(int y=1; y<=N; y++)	{
		cin >> str;
		for(int x=1; x<=M; x++) map[y][x] = str[x-1] - '0';
	}
	
	// SIMULATION
	Answer = bfs(1, 1);
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}
