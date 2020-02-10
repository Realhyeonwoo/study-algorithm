#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, K; // N: 체스판의 크기, K: 말의 개수  
int map[14][14] ; // 1부터 시작  
vector<int> visited[13][13]; // 각 칸에 방문해 있는 말 번호 저장 
int node[11][3]; // [말 번호]->[행][열][이동방향] 

int main(void) {
	memset(map, -1, sizeof(map));
	scanf("%d %d", &N, &K);
	/*
		체스판의 정보
		0:흰색, 1:빨간색, 2:파란색 
	*/
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	/*
		1번 ~ K번 말 정보
		행	열	이동방향
		우(1) 좌(2) 상(3) 하(4)
		[말 번호]->[행][열][이동방향] 
	*/
	for(int i=1; i<=K; i++) {
		int y, x, move;
		scanf("%d %d %d", &y, &x, &move);
		node[i][0] = y;
		node[i][1] = x;
		node[i][2] = move;
		visited[y][x].push_back(i);
	}
	/*========= 입력 끝 ==========*/
	
	int count = 1;
	while(true)  {
		if(count == 1000) {
			printf("-1\n");
			return 0;
		}
		
		bool flag = false;
		// 1번~k번 말 돌아가면서 동 
		for(int i=1; i<=K; i++) {
			
			int y = node[i][0];
			int x = node[i][1];
			int ny = node[i][0];
			int nx = node[i][1];
			
			if(!visited[y][x].empty() && visited[y][x][0] != i) continue;
			
			switch(node[i][2]) {
				case 1://우 
					nx = x+1; break;
				case 2://좌 
					nx = x-1; break;
				case 3://상 
					ny = y-1; break;
				case 4://하 
					ny = y+1; break;
			}
			
			/*
				변경 사항
				- node 상태변경 
				- visited 상태변경
			*/
			switch(map[ny][nx]) {
				case 0: // 흰 
					for(int v=0; v<visited[y][x].size(); v++) {
						node[visited[y][x][v]][0] = ny;
						node[visited[y][x][v]][1] = nx;
						visited[ny][nx].push_back(visited[y][x][v]);
					}
					visited[y][x].clear();
					break;
				case 1: // 빨
					// 상하반전
					 reverse(visited[y][x].begin(), visited[y][x].end());
					// 이동 
					for(int v=0; v<visited[y][x].size(); v++) {
						node[visited[y][x][v]][0] = ny;
						node[visited[y][x][v]][1] = nx;
						visited[ny][nx].push_back(visited[y][x][v]);
					}
					visited[y][x].clear();
					break;
				default: // 파 or 경계 넘을 때  
					// 이동방향 반대
					if(node[visited[y][x][0]][2] % 2 == 0) { // 좌 or 하 일때 
						node[visited[y][x][0]][2] -= 1; // 우 or 상 으로 변경 
						if(node[visited[y][x][0]][2] == 1) {
							nx = x + 1;
						} else {
							ny = y - 1;
						}
					} else { // 우 or 상 일때 
						node[visited[y][x][0]][2] += 1; // 좌 or 하 로 변경 
						if(node[visited[y][x][0]][2] == 2) {
							nx = x - 1;
						} else {
							ny = y + 1;
						}
					}
					// 한칸 이동 
					// 체스판 벗어나거나 파란색을 만날 경우
					if(ny<1 || ny>N || nx<1 || nx>N) {
						if(node[visited[y][x][0]][2] % 2 == 0) { // 좌 or 하 일때 
							node[visited[y][x][0]][2] -= 1; // 우 or 상 으로 변경 
						} else { // 우 or 상 일때 
							node[visited[y][x][0]][2] += 1; // 좌 or 하 로 변경 
						}
					} else {
						switch(map[ny][nx]) {
						case 0: // 흰 
							for(int v=0; v<visited[y][x].size(); v++) {
								node[visited[y][x][v]][0] = ny;
								node[visited[y][x][v]][1] = nx;
								visited[ny][nx].push_back(visited[y][x][v]);
							}
							visited[y][x].clear(); 
							break;
						case 1: // 빨
							// 상하반전
					 		reverse(visited[y][x].begin(), visited[y][x].end());
							// 이동 
							for(int v=0; v<visited[y][x].size(); v++) {
								node[visited[y][x][v]][0] = ny;
								node[visited[y][x][v]][1] = nx;
								visited[ny][nx].push_back(visited[y][x][v]);
							}
							visited[y][x].clear();
							break;
						}	
					}
					break;
			}
			
		}
		
		// 체스말 4개 쌓였는지 검사 
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(visited[y][x].size() >= 4) {
					flag = true;
					break;
				}
			}
		}
		
		if(flag) break;
		
		count++;
	}
	
	printf("%d\n", count);
	return 0; 
}
