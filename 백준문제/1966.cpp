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
		
		scanf("%d %d", &N, &M);
		queue<pair<int, int> > q;
		
		for(int i=0; i<N; i++) {
			scanf("%d", &document[i]);
			q.push_back(make_pair(i, document[i]));
		}
		
		int count = 0;
		while(true) {
			bool flag = false;
			count++;
			queue<pair<int, int> > tq;
			tq = q;
			bool check = false;
			while(!tq.empty()) {
				int index, value;
				if(!check) {
					index = tq.front().first;
					value = tq.front().second;
					tq.pop();
					check = true;	
				}
				
				pair<int, int> cur = q.front();
				q.pop();
				if(value < cur.second)  {
					flag = true;
				}
				
			}
			
			pair<int, int> doc = q.front();
			q.pop();
			
			if(flag) {				
				q.push(doc);
				continue;
			}
			
			if(doc.first == M) {
				break;
			}
			
		}
		
		printf("%d\n", count);
	}
	return 0;
}
