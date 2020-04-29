#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 350
#define START 150
using namespace std;

typedef struct {
	int y, x, makeTime, lifeValue, bornTime, dieTime;
	bool status;
}Cell;

int N, M, K;
int map[MAX][MAX];
vector<Cell> v;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool compare(Cell a, Cell b) {
	return a.lifeValue > b.lifeValue ? true : false;
}

void doDie(int time) {
	for(int i=0; i<v.size(); i++) {
		if(v[i].dieTime == time) v[i].status = false;
	}
}

void doActive(int time) {
	vector<Cell> vTemp;
	for(int i=0; i<v.size(); i++)	{
		if(!v[i].status) continue;
		
		if(v[i].bornTime == time) {
			int y = v[i].y;
			int x = v[i].x;
			int lifeValue = v[i].lifeValue;
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(map[ny][nx] != 0) continue;
				
				vTemp.push_back({ny, nx, time+1, lifeValue, time+1+lifeValue, time+1+lifeValue*2, true});
			}
		}
	}
	
	if(vTemp.size() == 0) return;
	
	sort(vTemp.begin(), vTemp.end(), compare);
	for(int i=0; i<vTemp.size(); i++) {
		int y = vTemp[i].y;
		int x = vTemp[i].x;
		int lifeValue = vTemp[i].lifeValue;
		
		if(map[y][x] != 0) continue;
		map[y][x] = lifeValue;
		v.push_back(vTemp[i]);
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		memset(map, 0, sizeof(map));
		v.clear();
		
		// INPUT
		scanf("%d %d %d", &N, &M, &K);
		int n;
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				scanf("%d", &n);
				if(n == 0) continue;
				map[START+y][START+x] = n;
				v.push_back({START+y, START+x, 0, n, 0+n, 0+n*2, true});
			}
		}
		
		// SIMULATION
		for(int time=0; time<=K; time++) {
			doDie(time);
			doActive(time);
		}
		
		// OUTPUT
		int dieCell = 0;
		for(int i=0; i<v.size(); i++) {
			if(!v[i].status || v[i].makeTime == K+1) dieCell++;
		}
		printf("#%d %d\n", tc, v.size() - dieCell);
	}
	return 0;
}
