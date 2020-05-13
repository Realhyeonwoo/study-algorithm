#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define MAX 11
using namespace std;

int N;
int num[MAX];
vector<string> Operator;
vector<int> v;
bool visited[10];
vector<int> Answer; 

void dfs(int cnt) {
	if(cnt == Operator.size())	{
		int sum = 0;
		int temp[N];
		for(int i=0; i<N; i++) temp[i] = num[i];
		
		for(int j=0; j<v.size(); j++) {
			int index = v[j];
			if(Operator[index] == "+") sum = (temp[j] + temp[j+1]);
			else if(Operator[index] == "-") sum = (temp[j] - temp[j+1]);
			else if(Operator[index] == "*") sum = (temp[j] * temp[j+1]);
			else if(Operator[index] == "/") sum = (temp[j] / temp[j+1]);
			temp[j+1] = sum;
		}
		
		Answer.push_back(sum);
		
		return;
	}
	
	for(int i=0; i<Operator.size(); i++) {
		if(visited[i])	continue;
		visited[i] = true;
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &num[i]);
	for(int i=0; i<4; i++) {
		int n; scanf("%d", &n);
		for(int j=0; j<n; j++) {
			if(i == 0) Operator.push_back("+");
			else if(i == 1) Operator.push_back("-");
			else if(i == 2) Operator.push_back("*");
			else if(i == 3) Operator.push_back("/");
		}
	}
	
	// SIMULATION
	dfs(0);
	
	// OUTPUT
	printf("%d\n", *max_element(Answer.begin(), Answer.end()));
	printf("%d\n", *min_element(Answer.begin(), Answer.end()));
	
	return 0;
}
