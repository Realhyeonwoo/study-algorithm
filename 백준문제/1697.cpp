//#include<iostream>
//#include<queue>
//using namespace std;
//
//int n, k;
//bool visited[100001] = {false, };
//int time = 0; 
//
//int main(void) {
//	scanf("%d %d", &n, &k);
//	if(n == k) {
//		printf("0\n");
//	} else {
//		queue<int> q;
//		
//		q.push(n);
//		visited[n] = true;
//		
//		while(!q.empty()) {
//			int size = q.size();
//			for(int i=0; i<size; i++) {
//				int x = q.front();
//				q.pop();
//				
//				if(x == k) {
//					printf("%d\n", time);
//					queue<int> empty;
//					q = empty;
//					break;
//				}
//				
//				if(x-1 >=0 && !visited[x-1]) {
//					q.push(x-1);
//					visited[x-1] = true;
//				}
//				if(x+1 <=100000 && !visited[x+1]) {
//					q.push(x+1);
//					visited[x+1] = true;
//				}
//				if(x*2 <=100000 && !visited[x*2]) {
//					q.push(x*2);
//					visited[x*2] = true;
//				}
//			}
//			time++; 
//		}
//	}
//	
//	return 0;
//}

#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;

int N, K;
bool visited[MAX];
queue<int> Q;
int Answer;

int main(void ){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	
	if(N != K) {
		visited[N] = true;
		Q.push(N);
		
		bool isFind = false;
		while(!Q.empty()) {
			int qSize = Q.size();
			for(int i=0; i<qSize; i++) {
				int now = Q.front();
				Q.pop();
				
				if(now == K) {
					
					isFind = true;
					break;
				}
				// now - 1
				if(now-1>=0 && !visited[now-1]) {
					visited[now-1] = true;
					Q.push(now - 1);
				}
				// now + 1
				if(now+1<MAX && !visited[now+1]) {
					visited[now+1] = true;
					Q.push(now + 1);
				}
				// now * 2
				if(now*2<MAX && !visited[now*2]) {
					visited[now*2] = true;
					Q.push(now * 2);
				}
			}
			if(isFind) break;
			if(Q.size() != 0) Answer++;
		}
	} 
	
	cout << Answer << '\n';
	
	return 0;
}
