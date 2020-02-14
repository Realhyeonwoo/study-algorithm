#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

int T;
int N, M;
int document[100];

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		memset(document, 0, sizeof(document));
		
		// input
		scanf("%d %d", &N, &M);
		queue<pair<int, int> > q;
		
		for(int i=0; i<N; i++) {
			scanf("%d", &document[i]);
			q.push(make_pair(i, document[i]));
		}
		
		
		// simulation
		// first: i번째, second: 가중치 
		int count = 0; 
		while(true) {
			queue<pair<int, int> > copy = q;
			pair<int, int> doc = q.front();
			q.pop();
			
			bool flag = true;
			while(!copy.empty()) {
				pair<int, int> cur = copy.front();
				copy.pop();
				int important = cur.second;
				if(important > doc.second) {
					q.push(doc);
					flag = false;
					break;
				}
			}
			if(flag) {
				count++;
			}
			if(flag && doc.first == M) {
				break;
			}
			
			
		}
		
		// output
		printf("%d\n", count);
	}
	return 0;
}
