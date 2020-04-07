#include<iostream>
#define MAX 4
#define INF 987564321
using namespace std;

int a[4][4] = {
	
};
int num[MAX][MAX] = {
	{0, 5, INF, 8 },
	{7, 0, 9, INF },
	{2, INF, 0, 4 },
	{INF, INF, 3, 0 },
};

int d[MAX][MAX];
int main(void) {
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			d[y][x] = num[y][x];
		}
	}
	
	for(int i=0; i<MAX; i++) {
		for(int y=0; y<MAX; y++) {
			for(int x=0; x<MAX; x++) {
				if(d[y][i] + d[i][x] < d[y][x])	 {
					d[y][x] = d[y][i] + d[i][x];
				}
			}
		}
	}
	
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			printf("%2d ", d[y][x]);
		}
		printf("\n");
	}
	return 0;
}
