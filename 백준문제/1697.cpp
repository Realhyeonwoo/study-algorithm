#include<iostream>
#include<queue>
using namespace std;

int n, k;
bool visited[100001] = {false, };
int time = 0; 

int main(void) {
	scanf("%d %d", &n, &k);
	if(n == k) {
		printf("0\n");
	} else {
		queue<int> q;
		
		q.push(n);
		visited[n] = true;
		
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
					q.push(x-1);
					visited[x-1] = true;
				}
				if(x+1 <=100000 && !visited[x+1]) {
					q.push(x+1);
					visited[x+1] = true;
				}
				if(x*2 <=100000 && !visited[x*2]) {
					q.push(x*2);
					visited[x*2] = true;
				}
			}
			time++; 
		}
	}
	
	return 0;
}
