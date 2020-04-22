#include<iostream>
#include<deque>
using namespace std;

deque<int> q[4];
int d[4];

void checkOne() {
	if(d[0] != 0 && q[0][2] != q[1][6]) d[1] = d[0] * (-1);
	if(d[1] != 0 && q[1][2] != q[2][6]) d[2] = d[1] * (-1);
	if(d[2] != 0 && q[2][2] != q[3][6]) d[3] = d[2] * (-1);
}

void checkTwo() {
	if(d[1] != 0 && q[1][6] != q[0][2]) d[0] = d[1] * (-1);
	if(d[1] != 0 && q[1][2] != q[2][6]) d[2] = d[1] * (-1);
	if(d[2] != 0 && q[2][2] != q[3][6]) d[3] = d[2] * (-1);
}

void checkThree() {
	if(d[2] != 0 && q[2][2] != q[3][6]) d[3] = d[2] * (-1);
	if(d[2] != 0 && q[2][6] != q[1][2]) d[1] = d[2] * (-1);
	if(d[1] != 0 && q[1][6] != q[0][2]) d[0] = d[1] * (-1);
}

void checkFour() {
	if(d[3] != 0 && q[3][6] != q[2][2]) d[2] = d[3] * (-1);
	if(d[2] != 0 && q[2][6] != q[1][2]) d[1] = d[2] * (-1);
	if(d[1] != 0 && q[1][6] != q[0][2]) d[0] = d[1] * (-1);
}

void rotateRight(int num) {
	int temp = q[num][7];
	for(int i=7; i>=1; i--) {
		q[num][i] = q[num][i-1];
	}
	q[num][0] = temp;
}

void rotateLeft(int num) {
	int temp = q[num][0];
	for(int i=0; i<7; i++) {
		q[num][i] = q[num][i+1];
	}
	q[num][7] = temp;
}

int main(void) {
	// INPUT
	for(int i=0; i<4; i++) {
		int n;
		for(int j=0; j<8; j++) {
			scanf("%1d", &n);
			q[i].push_back(n);
		}
	}
	int K, num, dir;
	scanf("%d", &K);
	
	// SIMULATION
	// ROTATE
	for(int i=0; i<K; i++) {
		for(int r=0; r<4; r++) d[r] = 0;
		scanf("%d %d", &num, &dir);
		d[num-1] = dir;
		
		if(num-1 == 0) checkOne();		
		else if(num-1 == 1) checkTwo();
		else if(num-1 == 2)checkThree();
		else if(num-1 == 3)checkFour();
		
		for(int r=0; r<4; r++) {
			if(d[r] == 1) rotateRight(r);
			else if(d[r] == -1) rotateLeft(r);
		}
	}
	// CALC_SCORE
	int score[4];
	score[0] = q[0][0] == 0 ? 0 : 1;
	score[1] = q[1][0] == 0 ? 0 : 2;
	score[2] = q[2][0] == 0 ? 0 : 4;
	score[3] = q[3][0] == 0 ? 0 : 8;
	
	// OUTPUT
	int answer = 0;
	for(int i=0; i<4; i++) answer += score[i];
	printf("%d\n", answer);
	
	return 0;
}
