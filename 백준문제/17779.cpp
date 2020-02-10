#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[22][22];
int people[22][22];
vector<int> answer;

void calcPopulation() {
	int population[5] = {0, 0, 0, 0, 0};
	for(int i=0; i<5; i++) {
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x] == i+1) {
					population[i] += people[y][x];
				}
			}
		}	
	}
	
	sort(population, population+5);
//	for(int i=0; i<5; i++) {
//		printf("%d ", population[i]);
//	}
//	printf("\n -> %d", population[4] - population[0]);
//	printf("\n\n");

//	printf("%d\n", population[4] - population[0]);

	answer.push_back(population[4] - population[0]);
}

void setDistrict(int x, int y, int d1, int d2) {
	for(int i=0; i<=d1; i++) {
		if(y-i<1 || y-i>N || x+i<1 || x+i>N) continue;
		map[y-i][x+i] = 5;
	}
	for(int i=0; i<=d2; i++) {
		if(y+i<1 || y+i>N || x+i<1 || x+i>N) continue;
		map[y+i][x+i] = 5;
	}
	for(int i=0; i<=d2; i++) {
		if(y-d1+i<1 || y-d1+i>N || x+d1+i<1 || x+d1+i>N) continue;
		map[y-d1+i][x+d1+i] = 5;
	}
	for(int i=0; i<=d1; i++) {
		if(y+d2-i<1 || y+d2-i>N || x+d2+i<1 || x+d2+i>N) continue;
		map[y+d2-i][x+d2+i] = 5;
	}
	
	//	5번선거구  
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(map[i][j] == 5) {
				int flag = false;
				int index = 0;
				for(int k=1; k<=N; k++) {
					if(map[i][j+k] == 5) {
						index = k;
						flag = true;
						break;
					}
				}
				if(flag) {
					for(int k=1; k<=index; k++) {
						map[i][j+k] = 5;
					}	
				}
			}
			
		}
	}
	//	1번선거구 
	for(int i=1; i<y; i++) {
		for(int j=1; j<=x+d1; j++) {
			if(map[i][j] != 5) {
				map[i][j] = 1;
			}
		}
	}
	
	//	2번선거구 
	for(int i=1; i<=y; i++) {
		for(int j=x+d1+1; j<=N; j++) {
			if(map[i][j] != 5) {
				map[i][j] = 2;
			}
		}
	}
	//	3번선거구 
//	x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	for(int i=y; i<=N; i++) {
		for(int j=1; j<x+d1; j++) {
			if(map[i][j] != 5) {
				map[i][j] = 3;
			}
		}
	}
	//	4번선거구
	for(int i=y+1; i<=N; i++) {
		for(int j=x+d1; j<=N; j++) {
			if(map[i][j] != 5) {
				map[i][j] = 4;
			}
		}
	}
	
	if(x==3 && y==5) {
		printf("\n");
		for(int z=1; z<=N; z++) {
			for(int i=1; i<=N; i++) {
				printf("%d ", map[z][i]);
			}
			printf("\n");
		}
	}
	

}

int main(void) {
	scanf("%d", &N);
	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			scanf("%d", &people[r][c]);
		}
	}
	
	for(int y=2; y<=N-1; y++) {
		for(int x=1; x<=N-2; x++) {
			for(int d=2; d<=N-x; d++) {
				for(int d1=1; d1<=d-1; d1++) {
					memset(map, 0, sizeof(map));
					//구역 나누기 
					setDistrict(x, y, d1, d-d1);
					// 구역별 인구수 구하기 
					printf("[%d %d %d %d]\n", x, y, d1, d-d1);
					
						calcPopulation();
					
					
				}
			}
		}
	}

	int minV = answer[0];
	for(int i=1; i<answer.size(); i++) {
		if(answer[i] < minV) {
			minV = answer[i];
		}
	}
	
	printf("%d ", minV);
	
	return 0;
}

