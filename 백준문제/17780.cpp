#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, K; // N: ü������ ũ��, K: ���� ����  
int map[14][14] ; // 1���� ����  
vector<int> visited[13][13]; // �� ĭ�� �湮�� �ִ� �� ��ȣ ���� 
int node[11][3]; // [�� ��ȣ]->[��][��][�̵�����] 

int main(void) {
	memset(map, -1, sizeof(map));
	scanf("%d %d", &N, &K);
	/*
		ü������ ����
		0:���, 1:������, 2:�Ķ��� 
	*/
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	/*
		1�� ~ K�� �� ����
		��	��	�̵�����
		��(1) ��(2) ��(3) ��(4)
		[�� ��ȣ]->[��][��][�̵�����] 
	*/
	for(int i=1; i<=K; i++) {
		int y, x, move;
		scanf("%d %d %d", &y, &x, &move);
		node[i][0] = y;
		node[i][1] = x;
		node[i][2] = move;
		visited[y][x].push_back(i);
	}
	/*========= �Է� �� ==========*/
	
	int count = 1;
	while(true)  {
		if(count == 1000) {
			printf("-1\n");
			return 0;
		}
		
		bool flag = false;
		// 1��~k�� �� ���ư��鼭 �� 
		for(int i=1; i<=K; i++) {
			
			int y = node[i][0];
			int x = node[i][1];
			int ny = node[i][0];
			int nx = node[i][1];
			
			if(!visited[y][x].empty() && visited[y][x][0] != i) continue;
			
			switch(node[i][2]) {
				case 1://�� 
					nx = x+1; break;
				case 2://�� 
					nx = x-1; break;
				case 3://�� 
					ny = y-1; break;
				case 4://�� 
					ny = y+1; break;
			}
			
			/*
				���� ����
				- node ���º��� 
				- visited ���º���
			*/
			switch(map[ny][nx]) {
				case 0: // �� 
					for(int v=0; v<visited[y][x].size(); v++) {
						node[visited[y][x][v]][0] = ny;
						node[visited[y][x][v]][1] = nx;
						visited[ny][nx].push_back(visited[y][x][v]);
					}
					visited[y][x].clear();
					break;
				case 1: // ��
					// ���Ϲ���
					 reverse(visited[y][x].begin(), visited[y][x].end());
					// �̵� 
					for(int v=0; v<visited[y][x].size(); v++) {
						node[visited[y][x][v]][0] = ny;
						node[visited[y][x][v]][1] = nx;
						visited[ny][nx].push_back(visited[y][x][v]);
					}
					visited[y][x].clear();
					break;
				default: // �� or ��� ���� ��  
					// �̵����� �ݴ�
					if(node[visited[y][x][0]][2] % 2 == 0) { // �� or �� �϶� 
						node[visited[y][x][0]][2] -= 1; // �� or �� ���� ���� 
						if(node[visited[y][x][0]][2] == 1) {
							nx = x + 1;
						} else {
							ny = y - 1;
						}
					} else { // �� or �� �϶� 
						node[visited[y][x][0]][2] += 1; // �� or �� �� ���� 
						if(node[visited[y][x][0]][2] == 2) {
							nx = x - 1;
						} else {
							ny = y + 1;
						}
					}
					// ��ĭ �̵� 
					// ü���� ����ų� �Ķ����� ���� ���
					if(ny<1 || ny>N || nx<1 || nx>N) {
						if(node[visited[y][x][0]][2] % 2 == 0) { // �� or �� �϶� 
							node[visited[y][x][0]][2] -= 1; // �� or �� ���� ���� 
						} else { // �� or �� �϶� 
							node[visited[y][x][0]][2] += 1; // �� or �� �� ���� 
						}
					} else {
						switch(map[ny][nx]) {
						case 0: // �� 
							for(int v=0; v<visited[y][x].size(); v++) {
								node[visited[y][x][v]][0] = ny;
								node[visited[y][x][v]][1] = nx;
								visited[ny][nx].push_back(visited[y][x][v]);
							}
							visited[y][x].clear(); 
							break;
						case 1: // ��
							// ���Ϲ���
					 		reverse(visited[y][x].begin(), visited[y][x].end());
							// �̵� 
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
		
		// ü���� 4�� �׿����� �˻� 
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
