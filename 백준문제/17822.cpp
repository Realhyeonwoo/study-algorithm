#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// N:������ ����, M:���ǿ� ���� ������ ����, T: ȸ�� �� 

int N, M, T;
queue<int> circle[51];
int arr[51][51];
int backup[51][51];

// Ž��
void eraseNum_dfs() {
	//���� 
	for(int i=1; i<=N; i++) {
		for(int j=0; j<M; j++) {
			backup[i][j] = arr[i][j];
		}
	}
	
	int dy[] = { -1, 1, 0, 0};
	int dx[] = { 0, 0, -1, 1};
	
	int flag = 0;
	for(int y=1; y<=N; y++) {
		for(int x=0; x<M; x++) {
			if(backup[y][x] == 0) continue;
			
			for(int dir=0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<1 || ny>N) continue;
				if(nx<0) {
					nx = M-1:
				}
				if(nx>M-1) {
					nx = 0;
				}
				
				if(arr[y][x] == arr[ny][nx]) {
					backup[y][x] = 0;
					backup[ny][nx] = 0;
					flag = 1;
				}
				
			}
		}
	}
	
	for(int y=1; y<=N; y++) {
		for(int x=0; x<M; x++) {
			arr[y][x] = backup[y][x];
		}
	}
      
	return flag;
   
}
int calc() {
	// queue ����� ���� �迭�� ��ȯ 
	for(int i=1; i<=N; i++) {
		int j = 0;
		while(!circle[i].empty()) {
			int x = circle[i].front();
			arr[i][j] = x;
			j++;
			circle[i].pop();
		}
	}
	
	// Ž��  
	for(int i=1; i<=N; i++) {
		for(int j=0; j<M; j++) {
			eraseNum_();
		}
	}
}

// �ð���� ȸ�� 
void rotLeft(int circleNum, int count) {
		for(int i=1; i<=count; i++) {
		int v = circle[circleNum].back();
		int arr[M];
		arr[0] = v;
		
		for(int i=1; i<M; i++) {
			int k = circle[circleNum].front();
			arr[i] = k;
			circle[circleNum].pop();
		}
		
		while(!circle[circleNum].empty()) {
			circle[circleNum].pop();
		}
		for(int i=0; i<M; i++) {
			circle[circleNum].push(arr[i]);
		}
	}
}

// �ݽð���� ȸ�� 
void rotRight(int circleNum, int count) {
	for(int i=1; i<=count; i++) {
		int v = circle[circleNum].front();
		circle[circleNum].pop();
		circle[circleNum].push(v);
	}
}

int main(void) {
	scanf("%d %d %d", &N, &M, &T);
	int num;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d", &num);
			circle[i].push(num);
		}
	}
	
	for(int i=1; i<=T; i++) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		for(int i=1; i<=N; i++) {
			if(i%x == 0) {	// x�� ����� i��° ���� 
				if(d == 0) { // �ð� ���� 
					rotLeft(i, k); // i ��° �� k��ŭ ȸ�� 
				} else if(d == 1) { // �ݽð� ���� 
					rotRight(i, k);
				}
			}
		}
	}
	
//	for(int i=1; i<=N; i++) {
//		while(!circle[i].empty()) {
//			printf("%d ", circle[i].front());
//			circle[i].pop();
//		}
//		printf("\n");
//	}

	int flag = calc();
	
	if(flag == 0) {
		
	} else {
		
	}
//	
//	printf("%d\n", sum);
	
	return 0; 
}
