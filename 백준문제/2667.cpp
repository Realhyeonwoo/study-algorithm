#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 25
using namespace std;

int N, map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> V;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int a, int b) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	visited[a][b] = true;
	
	int sum = 0;
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		sum++;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(map[ny][nx] == 0 || visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			Q.push(make_pair(ny, nx));
		}
	}
	
	V.push_back(sum);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	string str;
	cin >> N;
	for(int y=0; y<N; y++) {
		cin >> str;
		for(int x=0; x<N; x++) {
			map[y][x] = str[x] - '0';
			if(map[y][x] == 1) map[y][x] = -1;
		}
	}
	
	// SIMULATION
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == -1 && !visited[y][x]) bfs(y, x);
		}
	}
	
	// OUTPUT
	sort(V.begin(), V.end());
	cout << V.size() << '\n';
	for(int i=0; i<V.size(); i++) cout << V[i] << '\n';
	
	return 0;
}
