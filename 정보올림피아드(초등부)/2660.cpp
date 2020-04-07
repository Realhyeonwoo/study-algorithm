#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define MAX 51
#define INF 987564321
using namespace std;

int n;
int map[MAX][MAX], d[MAX][MAX];

int main(void) {
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			map[i][j] = INF;
			if(i == j) map[i][j] = 0;
		}
	}
	// INPUT
	scanf("%d", &n);
	int a, b;
	while(1) {
		scanf("%d %d", &a, &b);
		if(a == -1 && b == -1) break;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for(int y=1; y<=n; y++) {
		for(int x=1; x<=n; x++) {
			d[y][x] = map[y][x];
		}
	}
		
	for(int i=1; i<=n; i++) {
		for(int y=1; y<=n; y++) {
			for(int x=1; x<=n; x++) {
				if(d[y][i] + d[i][x] < d[y][x]) {
					d[y][x] = d[y][i] + d[i][x];
				}
			}
		}
	}
	
	int answer[MAX], minValue = INF;
	memset(answer, 0, sizeof(answer));
	for(int y=1; y<=n; y++) {
		for(int x=1; x<=n; x++) {
			answer[y] = max(answer[y], d[y][x]);
		}
		minValue = min(minValue, answer[y]);
	}
	
	vector<int> v;
	for(int i=1; i<=n; i++) {
		if(answer[i] == minValue) v.push_back(i);	
	}
	
	sort(v.begin(), v.end());
	printf("%d %d\n", minValue, v.size());
	for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
	
	return 0;
}
