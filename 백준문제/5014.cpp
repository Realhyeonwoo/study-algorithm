/*
	ÃÑ FÃþ 
	½ºÅ¸Æ®¸µÅ© GÃþ
	
	°æÈ£ À§Ä¡ SÃþ  => U / D ¹öÆ°  


*/

#include<iostream> 
#include<queue>
#define MAX 1000001
using namespace std;

int F, S, G, U, D, Answer;
bool visited[MAX], isReach;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> F >> S >> G >> U >> D;
	
	// SIMULATION
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		int qSize = Q.size(); 
		for(int i=0; i<qSize; i++) {
			int now = Q.front();
			Q.pop();
			
			if(now == G) {
				isReach = true;
				break;
			}
			
			if(now+U <= F && !visited[now + U]) {
				visited[now + U] = true;
				Q.push(now + U);
			}
			
			if(now-D >= 1 && !visited[now - D]) {
				visited[now - D] = true;
				Q.push(now - D);
			}
		}
		if(isReach) break;
		if(!Q.empty()) Answer++;
	}
	
	// OUTPUT	
	if(isReach) cout << Answer << '\n';
	else cout << "use the stairs";
	
	return 0;
}
