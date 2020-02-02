#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000

int n, k;
bool visited[MAX] = {false, };
int time = 0; 

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
				printf("%d\n", time);
				queue<int> empty;
				q = empty;
				break;
			}	
			
			if(x-1 >=0 && !visited[x-1]) {
				visited[x-1] = true;
				q.push(x-1);
			}
			if(x+1 <= MAX && !visited[x+1]) {
				visited[x+1] = true;
				q.push(x+1);
			}
			if(x*2 <= MAX && !visited[x*2]) {
				visited[x*2] = true;
				q.push(x*2);
			}
		}
		time++;		
	}
	return 0;
}
