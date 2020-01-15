#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visited[9];
vector<int> check;

void Print() {
	for(int i=0; i<check.size(); i++) {
		cout << check[i] << " "; 
	}
	cout << endl;
}

void Dfs(int cnt) {
	if(cnt == m) {
		Print();
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		check.push_back(i);
		
		Dfs(cnt+1);
		visited[i] = false;
		check.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n >> m;

	Dfs(0);
	return 0;
}
