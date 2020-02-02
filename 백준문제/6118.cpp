#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000

int n, k;
int visited[MAX] = {0, };
int time = 0; 
int count = 0; 
int answer = 0; 
bool flag = false;

int main(void) {
	scanf("%d %d", &n, &k);
	if(n==k) {
		printf("0\n");
		return 0;
	}
	
	queue<int> q;
	q.push(n);
	
	while(!q.empty()) {
		int size = q.size();
		for(int i=0; i<size; i++) {
			int x = q.front();
			q.pop();
			
			if(x == k) {
				if(answer == 0) {
					answer = time;
				}
				count+=1;
				flag = true;
			}	

			if(x-1 >=0) {
				q.push(x-1);
			}
			if(x+1 <= MAX) {
				q.push(x+1);
			}
			if(x*2 <= MAX) {
				q.push(x*2);
			}
		}
		
		if(flag) break;
		time++;		
	}
	printf("%d\n", answer);
	printf("%d\n", count);
	return 0;
}
