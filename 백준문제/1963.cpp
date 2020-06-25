#include<iostream>
#include<queue>
#define MAX 10000
using namespace std;

int visited[MAX]; // 1000 ~ 9999

bool isPrime(int num) {
	for(int i=2; i<num; i++) {
		if(num % i == 0) return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		// INPUT
		int num1, num2, Answer = 0;
		cin >> num1 >> num2;		
		
		// SIMULATION
		bool isFinish = false;
		queue<int> Q;
		Q.push(num1);
		visited[num1] = true;
		while(!Q.empty()) {
			int n = Q.front();
			Q.pop();
			
			// 천의 자리 
			int nNum = n % 1000;
			for(int i=1; i<=9; i++) {
				nNum += 1000 * i;
				if(nNum == num2) {
					isFinish = true;
					Answer += 1;
				}
				if(!visited[nNum] && isPrime(nNum)) {
					Q.push(nNum);
					visited[nNum] = true;
				}
			}
			if(isFinish) break;
			
			// 백의 자리 
			nNum = n % 1000;
			int temp = nNum - (nNum % 100);
			nNum = n - temp;
			for(int i=0; i<=9; i++) {
				nNum += 100 * i;
				if(nNum == num2) {
					isFinish = true;
					Answer += 1;
				}
				if(!visited[nNum] && isPrime(nNum)) {
					Q.push(nNum);
					visited[nNum] = true;
				}
			}
			if(isFinish) break;
			
			// 십의 자리 
			nNum = (n% 100) / 10;
			nNum = n - nNum * 10;
			for(int i=0; i<=9; i++) {
				nNum += 10 * i;
				if(nNum == num2) {
					isFinish = true;
					Answer += 1;
				}
				if(!visited[nNum] && isPrime(nNum)) {
					Q.push(nNum);
					visited[nNum] = true;
				}
			}
			if(isFinish) break;
			
			// 일의 자리 
			nNum = n - (n%10);
			for(int i=0; i<=9; i++) {
				nNum += i;
				if(nNum == num2) {
					isFinish = true;
					Answer += 1;
				}
				if(!visited[nNum] && isPrime(nNum)) {
					Q.push(nNum);
					visited[nNum] = true;
				}
			}
			if(isFinish) break;
			
			Answer++;
		}
		
		// OUTPUT
		cout << Answer << '\n';
	}
	return 0;
}
