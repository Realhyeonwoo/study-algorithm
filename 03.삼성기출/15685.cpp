#include<iostream>
#include<vector>
#define MAX 21
using namespace std;

int N;
vector<pair<int, int> > v[MAX]; // 1 ~ 20 번 드래곤 커브
int map[101][101];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int main(void) {
	// INPUT
	int N;
	scanf("%d", &N); 
	// SIMULATION
	int x, y, dir, g;
	for(int i=1; i<=N; i++) {
		scanf("%d %d %d %d", &x, &y, &dir, &g);
		v[i].push_back(make_pair(x, y));
		v[i].push_back(make_pair(x+dx[dir], y+dy[dir]));
		
		for(int j=1; j<=g; j++) {
			for(int k=v[i].size()-1; k>0; k--) {
				int nX = v[i][v[i].size()-1].first;
				int nY = v[i][v[i].size()-1].second;
				
				int x2 = v[i][k].first;
				int y2 = v[i][k].second;
				int x1 = v[i][k-1].first;
				int y1 = v[i][k-1].second;

				int gap;
				if(x2 == x1){
					gap = y2 - y1; 
					if(gap < 0) nX += gap;
					else nX += gap;
				} else if(y2 == y1) {
					gap = x2 - x1;
					if(gap<0) nY -= gap;	
					else nY -= gap;
				}
				if(nX>=0 && nX<=100 && nY>=0 && nY<=100) {
					v[i].push_back(make_pair(nX, nY));
				}
			}
		}
//		printf("=============================================\n");
//		for(int j=0; j<v[i].size(); j++) {
//			printf("%d %d\n", v[i][j].first, v[i][j].second);
//		}
//		printf("=============================================\n");
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=0; j<v[i].size(); j++) {
			map[v[i][j].second][v[i][j].first] = 1;
		}
	}
	
	int sum = 0;
	for(int y=0; y<=100; y++) {
		for(int x=0; x<=100; x++) {
			if(y+1 >100 || x+1 >100) continue;
			if(map[y][x] == 1 && map[y+1][x] == 1 && map[y][x+1] == 1 && 
			map[y+1][x+1] == 1) {
				sum++;
			}
		}
	}

	// OUTPUT
	printf("%d\n", sum);
	return 0;
}
