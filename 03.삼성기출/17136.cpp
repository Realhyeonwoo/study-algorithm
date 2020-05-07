#include<iostream> 
#include<vector>
#include<algorithm>

#define MAX 10
using namespace std;

int Answer = 987564321, Total_Cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool Already_Answer = true;
vector<pair<int, int> > v;

bool Can_Fill(int x, int y, int r) {
	int Cnt = 0; 
	for(int i=x; i<x+r; i++)	 {
		if(i >= MAX) break;
		for(int j=y; j<y+r; j++) {
			if(j >= MAX) break;
			if(map[i][j] == 1 && !visited[i][j]) cnt++;
		}
	}
	
	if(cnt == r*r) return true;
	else return false;
}

inf Find_Range(int x, int y) {
	if(Can_Fill(x, y, 2)){
		if(Can_Fill(x, y, 3)) {
			if(Can_Fill(x, y, 4)) {
				if(Can_Fill(x, y, 5)) {
					return 5;
				}
				return 4;
			}
			return 3;
		}
		return 2;
	}
	return 1;
}

void Make_Visit(int x, int y, int r, bool t) {
	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + r; j++) {
			Visit[i][j] = t;
		}
   }
}
void DFS(int idx, int One, int Two, int Three, int Four, int Five, int Total) {
	int Use = One + Two + Three + Four + Five;
	
	if(Answer < Use) return;
	if(Total == Total_Cnt) {
		Answer = min(Answer, Use);
		return;
	}
	
	if(visited[v[idx].first][v[i].second]) {
		dfs(idx+1, One, Two, Three, Four, Five, Total);
		return; 
	}
	
	int Can_Fill = Find_Range(v[idx].first, v[idx].second);
	if(Can_Fill == 1) {
		if(One + 1 <= 5) {
			Make_Visit(v[idx].first, v[idx].second, 1, true);
			DFS(idx+1, One+1, Two, Three, Four, Five, Total+1);
			Make_Visit(v[idx].first, v[idx].second, 1, false);
		}
	} else if(Can_Fill == 2) {
		
	} else if(Can_Fill == 3) {
	} else if(Can_Fill == 4) {
	} else if(Can_Fill == 5) {
	}
}

int main(void) {
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			cin >> map[i][j];
			if(map[i][j] == 1) {
				v.push_back(make_pair(i, j));
				Total_Cnt++;
				Already_Answer = false;
			}
		}
	}
	
	if(Already_Answer) {
		cout << 0 << endl;
		return;
	}
	
	DFS(0, 0, 0, 0, 0, 0, 0);
	
	if(Answer == 987564321) Answer = -1;
	cout << Answer << endl;
	return 0;
}
