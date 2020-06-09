#include<iostream>
#include<queue>
#include<vector>
#define MAX 101
using namespace std;

int N, M, Answer = 1;
vector<pair<int, int> > v[MAX][MAX];
bool visited[MAX][MAX], lighted[MAX][MAX], temp[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(void) {
	// INPUT
	cin >> N >> M;
	int x, y, a, b;
	for(int i=0; i<M; i++) {
		cin >> x >> y >> a >> b;
		v[x][y].push_back(make_pair(a, b));
	}
	
	// SIMULATION
	queue<pair<int, int> > Q;
	Q.push(make_pair(1, 1));
	lighted[1][1] = true;
	visited[1][1] = true;
	
	while(!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		for(int i=0; i<v[x][y].size(); i++) {
			int cx = v[x][y][i].first;
			int cy = v[x][y][i].second;
			if(!lighted[cx][cy]) Answer++;
			lighted[cx][cy] = true;
			
			if(temp[cx][cy] && !visited[cx][cy]) {
				Q.push(make_pair(cx, cy));
				visited[cx][cy] = true;
			}
		}
		
		for(int dir=0; dir<4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx<1 || nx>N || ny<1 || ny>N) continue;
			if(visited[nx][ny]) continue;
			if(!lighted[nx][ny]) {
				temp[nx][ny] = true;
				continue;
			}
			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}
