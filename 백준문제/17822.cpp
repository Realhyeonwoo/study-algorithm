#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// N:원판의 갯수, M:원판에 적힌 숫자의 갯수, T: 회전 수 

int N, M, T;
queue<int> circle[51];
int arr[51][51];

int calc() {
	for(int i=1; i<=N; i++) {
		int j = 0;
		while(!circle[i].empty()) {
			int x = circle[i].front();
			arr[i][j] = x;
			j++;
			circle[i].pop();
		}
	}
//	for(int i=1; i<=N; i++) {
//		for(int j=0; j<M; j++) {
//			printf("%d ", value[i][j]);
//		}
//		printf("\n");
//	}
	bool flag = true;
	
	for(int i=1; i<=N; i++) {
		for(int j=0; j<M; j++) {
			if(i==1 && j==0) {
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j+1] = 0;					
				}
				if(arr[i][j] == arr[i][M-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][M-1] = 0;
				}
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
			} else if(i==1 && j==M-1) {
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i][0]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][0] = 0;
				}
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
			} else if(i==N && j==0) {
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j+1] = 0;
				}
				if(arr[i][j] == arr[i][M-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][M-1] = 0;
				}
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
			} else if(i==N && j==M-1) {
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i][0]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][0] = 0;
				}
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
			} else if(i==1) {
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
			} else if(i==N) {
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
			} else if(j==0) {
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j+1] = 0;
				}
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
			} else if(j==M-1) {
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
			} else {
				if(arr[i][j] == arr[i][j+1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j+1] = 0;
				}
				if(arr[i][j] == arr[i][j-1]) {
					flag = false;
					arr[i][j] = 0;
					arr[i][j-1] = 0;
				}
				if(arr[i][j] == arr[i-1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i-1][j] = 0;
				}
				if(arr[i][j] == arr[i+1][j]) {
					flag = false;
					arr[i][j] = 0;
					arr[i+1][j] = 0;
				}
			}
		}
	}
	
	if(flag) {
		int sum = 0;
		for(int i=1; i<=N; i++) {
			for(int j=0; j<M; j++) {
				sum += arr[i][j];
			}
		}
		int size = N * M;
		int avg = sum / size;
		sum = 0;
		for(int i=1; i<=N; i++) {
			for(int j=0; j<M; j++) {
				if(arr[i][j] > avg) {
					sum += arr[i][j] - 1;	
				} else {
					sum += arr[i][j] + 1;
				}
			}
		}
		return sum;
	} else {
		int sum = 0;
		for(int i=1; i<=N; i++) {
			for(int j=0; j<M; j++) {
				sum += arr[i][j];
			}
		}
		return sum;
	}
}

// 시계방향 회전 
void rotLeft(int circleNum, int count) {
	for(int i=1; i<=count; i++) {
		int v = circle[circleNum].front();
		circle[circleNum].pop();
		circle[circleNum].push(v);
	}
}

// 반시계방향 회전 
void rotRight(int circleNum, int count) {
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
			if(i%x == 0) {	
				if(d == 0) {
					rotLeft(i, k);
				} else if(d == 1) {
					rotRight(i, k);
				}
			}
		}
	}
	
	int sum = calc();
	
	printf("%d\n", sum);
	
	return 0; 
}
