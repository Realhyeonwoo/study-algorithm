#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
	public: 
	long long int a, b, value;
	Edge(long long int a, long long int b, long long int value) {
		this->a = a;
		this->b = b;
		this->value = value;
	}
};

int T, N;
vector<Edge> v;
long long int X[1001], Y[1001];
double E;
int island[1001];

int getParent(int a) {
	if(a == island[a]) return a;
	return getParent(island[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if(a < b) {
		island[b] = a; 
	} else {
		island[a] = b;
	}
}

bool isCycle(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a==b ? true : false;
}

bool compare(Edge a, Edge b) {
	return a.value < b.value;	
}	

int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		v.clear();
		
		scanf("%d", &N);
		long long int p;
		for(int i=1; i<=N; i++) {
			scanf("%lld", &p);
			X[i] = p;
		}
		for(int i=1; i<=N; i++) {
			scanf("%lld", &p);
			Y[i] = p;
		}
		scanf("%lf", &E);
		
		for(int i=1; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				long long int value  = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
				v.push_back(Edge(i, j, value));
			}
		}
		
		
		sort(v.begin(), v.end(), compare);
		
		for(int i=1; i<=N; i++) island[i] = i;
		long long int sum = 0;
		for(int i=0; i<v.size(); i++) {
			if(!isCycle(v[i].a, v[i].b)) {
				sum += v[i].value;
				unionParent(v[i].a, v[i].b);
			}
		}
		
		printf("#%d %0.f\n", tc, (double)(E*sum));
		
	}
	return 0;
}
