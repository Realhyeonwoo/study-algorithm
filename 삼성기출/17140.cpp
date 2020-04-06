#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define MAX 101
using namespace std;

int r, c, k, answer = 0;
int map[MAX][MAX];
int num[MAX];

int main(void) {
	// INPUT
	scanf("%d %d %d", &r, &c, &k);
	for(int y=1; y<=3; y++) {
		for(int x=1; x<=3; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	if(map[r][c] == k) {
		printf("%d\n", answer);
		return 0;
	}
	
	int Time = 0;
	int Row = 3, Col = 3;	
	while(1) {
		if(map[r][c] == k) {
			answer = Time;
			break;
		}
		if(Time > 100) {
			answer = -1;
			break;
		}
		
		
		vector<int> Size;
		
		if(Row >= Col) {
			for(int i=1; i<=Row; i++) {
				vector<pair<int, int> > v;
				memset(num, 0, sizeof(num));
				for(int j=1; j<=Col; j++) num[map[i][j]]++;
				for(int j=1; j<MAX; j++) {
					if(num[j] == 0) continue;
					v.push_back(make_pair(num[j], j));
				}
				sort(v.begin(), v.end());
				for(int j=1; j<=Col; j++) map[i][j] = 0;
				int idx = 1;
				for(int j=0; j<v.size(); j++) {
					map[i][idx++] = v[j].second;
					map[i][idx++] = v[j].first;
				}
				idx--;
				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			Col = Size.back();
		} else {
			for(int i=1; i<=Col; i++) {
				vector<pair<int, int> > v;
				memset(num, 0, sizeof(num));
				for(int j=1; j<=Row; j++) num[map[j][i]]++;
				for(int j=1; j<MAX; j++) {
					if(num[j] == 0) continue;
					v.push_back(make_pair(num[j], j));
				}
				sort(v.begin(), v.end());
				for(int j=1; j<=Row; j++) map[j][i] = 0;
				int idx = 1;
				for(int j=0; j<v.size(); j++) {
					map[idx++][i] = v[j].second;
					map[idx++][i] = v[j].first;
				}
				idx--;
				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			Row = Size.back();
		}
		Time++;
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
