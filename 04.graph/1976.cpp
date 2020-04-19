#include<iostream>
#include<vector>

#define MAX 201
using namespace std;

int N, M;
int map[MAX][MAX];
int num[MAX];

int getParent(int x) {
	if(x == num[x]) return x;
	return getParent(num[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if(a < b) {
		num[b] = a;
	} else {
		num[a] = b;
	}
}

bool isCycle(int a, int b) {
	a = getParent(a);
	b = getParent(b); 
	
	return a == b ? true : false;
}

int main(void) {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) num[i] = i;
	
	scanf("%d", &M);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) {
				if(!isCycle(y, x)) unionParent(y, x);
			}
		}
	}
	
	vector<int> v;
	int n;
	for(int i=1; i<=M; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	
	bool isPossible = true;
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(!isCycle(v[i], v[j])) {
				isPossible = false;
				break;
			}
		}
		if(!isPossible) break;
	}
	
	printf("%s\n", isPossible ? "YES" : "NO");
	
	return 0; 
}
