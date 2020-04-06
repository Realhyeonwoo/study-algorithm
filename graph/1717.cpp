#include<iostream>

#define MAX 1000001
using namespace std;

int n, m;
int num[MAX];

int getParent(int x) {
	if(num[x] == x) return x;
	return getParent(num[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if(x < y) {
		num[y] = x;
	} else {
		num[x] = y;
	}
}

bool isCycle(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	return x == y ? true : false;
}

int main(void) {
	// INIT
	for(int i=1; i<=MAX; i++) num[i] = i;
	
	// SIMULATION
	scanf("%d %d", &n, &m);
	int c, a, b;
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if(c == 0) {
			unionParent(a, b);
		} else if(c == 1) {
			printf("%s\n", isCycle(a, b) ? "YES" : "NO");
		}
	}
	return 0;
}
