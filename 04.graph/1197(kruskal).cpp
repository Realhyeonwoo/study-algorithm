#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10001
using namespace std;

typedef struct {
	int a, b, c;
} Edge;

vector<Edge> v;
int num[MAX];
int V, E;

int a, b, c;

bool compare(Edge e1, Edge e2) {
	return e1.c < e2.c;
}

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
	scanf("%d %d", &V, &E);
	for(int i=1; i<=V; i++) {
		num[i] = i;
	}
	
	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({a, b, c});
	}
	sort(v.begin(), v.end(), compare);
	
	int answer = 0;
	for(int i=0; i<v.size(); i++) {
		if(!isCycle(v[i].a, v[i].b)) {
			answer += v[i].c;
			unionParent(v[i].a, v[i].b);
		}
	}
	
	printf("%d\n", answer);
	return 0;
}
