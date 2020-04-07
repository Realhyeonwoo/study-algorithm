#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 101
using namespace std;

int r, c, k;
int map[MAX][MAX];
int num[MAX];
int Row = 3, Col = 3;

int main(void) {
	scanf("%d %d %d", &r, &c, &k);
	for(int y=1; y<=Row; y++) {
		for(int x=1; x<=Col; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	int answer = 0;
	while(1) {
		if(answer > 100) {
			answer = -1;
			break;	
		}
		if(map[r][c] == k) break;
		
		vector<int> Size;			
		if(Row >= Col) {
			for(int y=1; y<=Row; y++) {
				vector<pair<int, int> > v;
				memset(num, 0, sizeof(num));
				
				for(int x=1; x<=Col; x++) num[map[y][x]]++;
				for(int i=1; i<MAX; i++) {
					if(num[i] == 0) continue;
					v.push_back(make_pair(num[i], i));
				}
				
				sort(v.begin(), v.end());
				
				for(int x=1; x<=Col; x++) map[y][x] = 0;
				int idx = 1;
				for(int i=0; i<v.size(); i++) {
					map[y][idx++] = v[i].second;
					map[y][idx++] = v[i].first;
				}
				idx--;
				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			Col = Size.back();
			
		} else {
			for(int y=1; y<=Col; y++) {
				vector<pair<int, int> > v;
				memset(num, 0, sizeof(num));
				
				for(int x=1; x<=Row; x++) num[map[x][y]]++;
				for(int i=1; i<MAX; i++) {
					if(num[i] == 0) continue;
					v.push_back(make_pair(num[i], i));
				}
				
				sort(v.begin(), v.end());
				
				for(int x=1; x<=Row; x++) map[x][y] = 0;
				int idx = 1;
				for(int i=0; i<v.size(); i++) {
					map[idx++][y] = v[i].second;
					map[idx++][y] = v[i].first;
				}
				idx--;
				Size.push_back(idx);
			}
			sort(Size.begin(), Size.end());
			Row = Size.back();
		}
		answer++;
	}
	
	printf("%d\n", answer);
	return 0;
}
