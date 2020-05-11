#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, Answer;
string str;
vector<pair<int, char> > v;
vector<int> index, vFirst;
bool visited[20];

void dfs(int start, int cnt, int M) {
	if(cnt == M) {
		vFirst.clear();
		if(cnt != 0) {
			int nowIdx = index[0];
			vFirst.push_back(nowIdx);
			// 괄호 안겹치게끔 연속인 index값은 선택안되게  
			for(int i=1; i<index.size(); i++) {
				if(nowIdx+1 != index[i]) {
					nowIdx = index[i];
					vFirst.push_back(index[i]);
				}
			}
			
			if(vFirst.size() != M) return;
			
			// 수식 변경 2 
			vector<int> num, minus;
			string tmepStr = str;
			for(int i=0; i<vFirst.size(); i++) {
				int idx = v[vFirst[i]].first;
				char oper = v[vFirst[i]].second;
				
				int tmp = 0;
				if(oper == '+') tmp = (str[idx-1]-'0') + (str[idx+1]-'0');
				else if(oper == '-') tmp = (str[idx-1]-'0') - (str[idx+1]-'0');
				else if(oper == '*') tmp = (str[idx-1]-'0') * (str[idx+1]-'0');
				if(tmp < 0) {
					tmepStr[idx] = 'c';
					minus.push_back(tmp);
				} else if(tmp >= 10) {
					tmepStr[idx] = 'b';	
					num.push_back(tmp);
				} else {
					tmepStr[idx] = tmp + '0';	
				}
				tmepStr[idx-1] = 'a';
				tmepStr[idx+1] = 'a';
			}
			
			// 새로운 완성 수식 
			string newStr = "";
			for(int i=0; i<tmepStr.length(); i++) {
				if(tmepStr[i] == 'a') continue;
				newStr += tmepStr[i];
			}
			
			// 계산  
			int sum = 0, index = 0, index2 = 0;
			
			if(newStr[0] >= '0' && newStr[0] <= '9') sum += newStr[0] - '0';
			else if(newStr[0] == 'c') sum = minus[index2++];
			else if(newStr[0] == 'b') sum = num[index++];
			
			for(int i=1; i<newStr.length(); i++) {
				if(newStr[i] == '+') {
					if(newStr[i+1] == 'c') {
						sum += minus[index2++];
						i++;
					}
					else if(newStr[i+1] == 'b') {
						sum += num[index++];
						i++;
					}
					else sum += newStr[++i] - '0';
				}
				else if(newStr[i] == '-') {
					if(newStr[i+1] == 'c') {
						sum += (-1) * minus[index2++];
						i++;
					}
					else if(newStr[i+1] == 'b') {
						sum -= num[index++];
						i++;
					}
					else sum -= newStr[++i] - '0';
				} 
				else if(newStr[i] == '*') {
					if(newStr[i+1] == 'c') {
						sum *= minus[index2++];
						i++;
					}
					else if(newStr[i+1] == 'b') {
						sum *= num[index++];
						i++;
					}
					else sum *= newStr[++i] - '0';
				} 
			}
			// 최댓값 비교 저장  
			Answer = max(Answer, sum);
		}
		return;
	}
	for(int i=start; i<N/2; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		index.push_back(i);
		dfs(i, cnt+1, M);
		visited[i] = false;
		index.pop_back();
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	cin >> str;
	
	// SIMULATION
	Answer = str[0] - '0';
	for(int i=0; i<N; i++) {
		if(i%2 != 0) {
			v.push_back(make_pair(i, str[i]));
			if(str[i] == '+') Answer += (str[i+1] - '0');
			else if(str[i] == '-') Answer -= (str[i+1] - '0');
			else if(str[i] == '*') Answer *= (str[i+1] - '0');
		}
	}
	
	for(int i=1; i<=N/2; i++) {
		dfs(0, 0, i);
	}
	
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
