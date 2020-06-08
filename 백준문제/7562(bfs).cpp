#include<iostream>
#include<queue>
#define MAX 300
using namespace std;

int l, map[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> Start, End;

int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		// INIT
		for(int y=0; y<MAX; y++) {
			fill(map[y], map[y] + MAX, 0);
			fill(visited[y], visited[y] + MAX, false);
		}
		
		// INPUT
		int y, x;
		cin >> l;
		cin >> y >> x; Start = {y, x};
		cin >> y >> x; End = {y, x};
		
		// SIMULATION
		queue<pair<int, int> > Q;
		Q.push(make_pair(Start.first, Start.second));
		visited[Start.first][Start.second] = true;
		
		int Answer = 0;
		bool isFind = false;
		while(!Q.empty()) {
			int qSize = Q.size(); 
			for(int i=0; i<qSize; i++) {
				int y = Q.front().first;
				int x = Q.front().second;
				Q.pop();
				
				if(y == End.first && x == End.second) {
					isFind = true;
					break;
				}
				
				for(int dir=0; dir<8; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					
					if(ny<0 || ny>=l || nx<0 || nx>=l) continue;
					if(visited[ny][nx]) continue;
					
					visited[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
				
			}
			if(isFind) break;
			if(!Q.empty()) Answer++;
		}
		
		// OUTPUT
		cout << Answer << '\n';
	}
	
	return 0;
}
