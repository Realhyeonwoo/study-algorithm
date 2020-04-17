#include<iostream>
#include<vector>

#define INF 987564321
using namespace std;

int N, M; // N(세로) M(가로)
int map[10][10], cpyMap[10][10];
bool visited[10][10];
vector<pair<pair<int, int>, pair<int, int> > > v;
int answer = INF;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void copyMap(void) {
	for(int y=0; y<10; y++) {
		for(int x=0; x<10; x++) {
			cpyMap[y][x] = map[y][x];
		}
	}
}

void moveRight(int y, int x) {
	for(int i=x+1; i<M; i++) {
		if(cpyMap[y][i] == 6) break;
		if(1<=cpyMap[y][i] && cpyMap[y][i]<=5) continue;
		cpyMap[y][i] = -1;
	}
}

void moveLeft(int y, int x) {
	for(int i=x-1; i>=0; i--) {
		if(cpyMap[y][i] == 6) break;
		if(1<=cpyMap[y][i] && cpyMap[y][i]<=5) continue;
		cpyMap[y][i] = -1;
	}
}

void moveUp(int y, int x) {
	for(int i=y-1; i>=0; i--) {
		if(cpyMap[i][x] == 6) break;
		if(1<=cpyMap[i][x] && cpyMap[i][x]<=5) continue;
		cpyMap[y][i] = -1;
	}
}

void moveDown(int y, int x) {
	for(int i=y+1; i<N; i++) {
		if(cpyMap[i][x] == 6) break;
		if(1<=cpyMap[i][x] && cpyMap[i][x]<=5) continue;
		cpyMap[y][i] = -1;
	}
}

void checkCameraArea() {
	copyMap();	
	for(int i=0; i<v.size(); i++) {
		if(v[i].second.first == 1) {
			if(v[i].second.second == 0) moveRight(v[i].first.first, v[i].first.second);
			else if(v[i].second.second == 1) moveLeft(v[i].first.first, v[i].first.second);
			else if(v[i].second.second == 2) moveDown(v[i].first.first, v[i].first.second);
			else if(v[i].second.second == 3) moveUp(v[i].first.first, v[i].first.second);
		} else if(v[i].second.first == 2) {
			if(v[i].second.second == 0 || v[i].second.second == 1) {
				moveRight(v[i].first.first, v[i].first.second);
				moveLeft(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 2 || v[i].second.second == 3) {
				moveUp(v[i].first.first, v[i].first.second);
				moveDown(v[i].first.first, v[i].first.second);
			}
		} else if(v[i].second.first == 3) {
			if(v[i].second.second == 0) {
				moveUp(v[i].first.first, v[i].first.second);
				moveRight(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 1) {
				moveDown(v[i].first.first, v[i].first.second);
				moveRight(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 2) {
				moveDown(v[i].first.first, v[i].first.second);
				moveLeft(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 3) {
				moveUp(v[i].first.first, v[i].first.second);
				moveLeft(v[i].first.first, v[i].first.second);
			}
		} else if(v[i].second.first == 4) {
			if(v[i].second.second == 0) {
				moveUp(v[i].first.first, v[i].first.second);
				moveLeft(v[i].first.first, v[i].first.second);
				moveRight(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 1) {
				moveUp(v[i].first.first, v[i].first.second);
				moveDown(v[i].first.first, v[i].first.second);
				moveRight(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 2) {
				moveLeft(v[i].first.first, v[i].first.second);
				moveDown(v[i].first.first, v[i].first.second);
				moveRight(v[i].first.first, v[i].first.second);
			} else if(v[i].second.second == 3) {
				moveUp(v[i].first.first, v[i].first.second);
				moveDown(v[i].first.first, v[i].first.second);
				moveLeft(v[i].first.first, v[i].first.second);
			} 
		} else if(v[i].second.first == 5) {
			moveUp(v[i].first.first, v[i].first.second);
			moveDown(v[i].first.first, v[i].first.second);
			moveLeft(v[i].first.first, v[i].first.second);
			moveRight(v[i].first.first, v[i].first.second);
		}
	}
}

int numOfSecretArea(void) {
	int sum = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(cpyMap[y][x] == 0) sum++;
		}
	}
	return sum;
}

void rotateCamera_dfs(int cnt) {
	if(cnt == v.size()) {
		checkCameraArea();
		answer = min(answer, numOfSecretArea());
		return;
	}
	
	v[cnt].second.second = 0;
	rotateCamera_dfs(cnt + 1);
	
	v[cnt].second.second = 1;
	rotateCamera_dfs(cnt + 1);
	
	v[cnt].second.second = 2;
	rotateCamera_dfs(cnt + 1);
	
	v[cnt].second.second = 3;
	rotateCamera_dfs(cnt + 1);
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] != 0 && map[y][x] != 6) {
				v.push_back(make_pair(make_pair(y, x), make_pair(map[y][x], -1)));
			}
		}
	}
	
	// SIMULATION
	rotateCamera_dfs(0);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
