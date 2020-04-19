#include<iostream>
#include<vector>

#define MAX 8 
#define INF 987564321
using namespace std;

int N, M; // N(세로) M(가로)  
int map[MAX][MAX], cpyMap[MAX][MAX];
vector<pair<pair<int, int>, pair<int, int> > > v;
int answer = INF;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

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
		cpyMap[i][x] = -1;
	}
}
void moveDown(int y, int x) {
	for(int i=y+1; i<N; i++) {
		if(cpyMap[i][x] == 6) break;
		if(1<=cpyMap[i][x] && cpyMap[i][x]<=5) continue;
		cpyMap[i][x] = -1;
	}
}

void checkCameraArea() {
	// COPY_MAP
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			cpyMap[y][x] = map[y][x];
		}
	}
	// CHECK_CAMERA_AREA
	for(int i=0; i<v.size(); i++) {
		int y = v[i].first.first;
		int x = v[i].first.second;
		int type = v[i].second.first;
		int dir = v[i].second.second;
		
		if(type == 1) {
			if(dir == 0) moveRight(y, x);
			else if(dir == 1) moveLeft(y, x);
			else if(dir == 2) moveDown(y, x);
			else if(dir == 3) moveUp(y, x);
		} else if(type == 2) {
			if(dir == 0 || dir == 1) {
				moveRight(y, x);
				moveLeft(y, x);
			} else if(dir == 2 || dir == 3) {
				moveDown(y, x);
				moveUp(y, x);
			}
		} else if(type == 3) {
			if(dir == 0) {
				moveUp(y, x);
				moveRight(y, x);
			}
			else if(dir == 1){
				moveRight(y, x);
				moveDown(y, x);
			} 
			else if(dir == 2){
				moveLeft(y, x);
				moveDown(y, x);
			} 
			else if(dir == 3) {
				moveUp(y, x);
				moveLeft(y, x);
			}
		} else if(type == 4) {
			if(dir == 0) {
				moveUp(y, x);
				moveRight(y, x);
				moveLeft(y, x);
			} else if(dir == 1) {
				moveUp(y, x);
				moveRight(y, x);
				moveDown(y, x);
			} else if(dir == 2) {
				moveDown(y, x);
				moveRight(y, x);
				moveLeft(y, x);
			} else if(dir == 3) {
				moveUp(y, x);
				moveLeft(y, x);
				moveDown(y, x);
			}
		} else if(type == 5) {
			moveUp(y, x);
			moveRight(y, x);
			moveLeft(y, x);
			moveDown(y, x);
		}
			
	}
}

int numOfSecretArea() {
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
			if(1<=map[y][x] && map[y][x]<=5){
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
