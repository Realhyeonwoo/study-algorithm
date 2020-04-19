//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<set>
//#include<queue>
//#include<vector>
//using namespace std;
//
//string N;
//int K, len;
//
//int Invert(string s) {
//	int sum = 0; 
//	for(int i=0; i<s.length(); i++)	 {
//		sum += (s[i] - '0');
//		if(i != s.length()-1) sum *= 10;
//	}
//	return sum;
//}
//
//int bfs(string s) {
//	queue<string> q;
//	q.push(s);
//	int count = 0;
//	int maxV = 0;
//	
//	while(!q.empty() && count < K) {
//		int qSize = q.size();
//		set<string> visited;
//		for(int s=0; s<qSize; s++) {
//			string cur = q.front();
//			q.pop();
//			
//			for(int i=0; i<len-1; i++) {
//				for(int j=i+1; j<len; j++) {
//					if(i==0 && cur[j]=='0') continue;
//					
//					swap(cur[i], cur[j]);
//					if(visited.find(cur) == visited.end()) {
//						if(count == K-1 && maxV < Invert(cur)) maxV = Invert(cur);
//						
//						q.push(cur);
//						visited.insert(cur);
//					}
//					swap(cur[i], cur[j]);
//				}
//			}
//		}
//		count++;
//	}
//	return maxV;
//}
//
//int main(void) {
//	// INPUT
//	cin >> N >> K;
//	len = N.length();	
//	if(len == 1 || (len == 2 && Invert(N) % 10 == 0)) {
//		printf("-1\n");
//		return 0;
//	}
//	
//	// SIMULATION
//	int answer = bfs(N);
//	
//	// OUTPUT
//	printf("%d\n", answer);
//	
//	return 0;
//}
