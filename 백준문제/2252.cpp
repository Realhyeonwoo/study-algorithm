#include<iostream>
#include<queue>
#define MAX 32001
using namespace std;

int N, M;
int map[MAX];
bool visited[MAX];
int value = 32000;
priority_queue<pair<int, int> > pq;

int main(void) {
	scanf("%d %d", &N, &M);
	int num1, num2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &num1, &num2);
		if(!visited[num2]) {
			map[num2] = value--;
			visited[num2] = true;
			pq.push(make_pair(-map[num2], num2));
		}
		
		if(!visited[num1]) {
			map[num1] = map[num2] - 1;
			visited[num1] = true;
			pq.push(make_pair(-map[num1], num1));
		} 
	}
	
	while(!pq.empty()) {
		printf("%d ", pq.top().second);
		pq.pop();
	}
	
	
	return 0;
}
