#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

#define MAX 350
#define SIZE 150
using namespace std;

typedef struct {
	int y, x, lifeValue, bornTime, activeTime, dieTime;
	bool status;
} Cell;

int N, M, K, answer;
int map[MAX][MAX];
vector<Cell> v;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void doDie(int time) {
	for(int i=0; i<v.size(); i++) {
		if(v[i].dieTime == time) v[i].status = false;
	}
}

bool compare(Cell a, Cell b) {
	return a.lifeValue > b.lifeValue ? true : false;
}
void doActive(int time) {
	vector<Cell> temp;
	
	for(int i=0; i<v.size(); i++) {
		if(!v[i].status) continue;
		if(v[i].activeTime == time) {
			int y = v[i].y;
			int x = v[i].x;
			int lifeValue = v[i].lifeValue;
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(map[ny][nx] != 0) continue;
				temp.push_back({ny, nx, lifeValue, time+1, time+1+lifeValue, time+1+lifeValue*2, true});
			}
		}
	}
	if(temp.size() == 0) return;
	sort(temp.begin(), temp.end(), compare);
	
		
		for(int i=0; i<temp.size(); i++) {
			int y = temp[i].y;
			int x = temp[i].x;
			int lv = temp[i].lifeValue;
			
			if(map[y][x] != 0) continue;
			map[y][x] = lv;
			v.push_back(temp[i]);
		}
}

int main(void) {
	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		memset(map, 0, sizeof(map));
		answer = 0;
		v.clear();
		
		// INPUT
		scanf("%d %d %d", &N, &M, &K);
		int n;
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				scanf("%d", &n);
				if(n == 0) continue;
				map[SIZE+y][SIZE+x] = n;
				v.push_back({SIZE+y, SIZE+x, n, 0, 0+n, 0+n*2, true});
			}
		}
		
		// SIMULATION
//		for(int time=0; time<=K; time++) {
//			doDie(time);
//			doActive(time);
//		}
		int Time = 0;
		while(1) {
			if(Time == K) break;
			doDie(Time);
			doActive(Time);
			Time++;
		}
		
		// OUTPUT
		int dieCell = 0;
//		for(int i=0; i<v.size(); i++) {
//			if(!v[i].status || v[i].bornTime == K+1) dieCell++;
//		}
		for (int i = 0; i < v.size(); i++)
    {
        if (v[i].status == false) dieCell++;
        if (v[i].dieTime == K) dieCell++;
        if (v[i].bornTime == K + 1) dieCell++;
    }
    printf("%d\n", v.size());
    printf("%d\n", dieCell);
		printf("#%d %d\n", tc, v.size()-dieCell);
	}
	return 0;
}
