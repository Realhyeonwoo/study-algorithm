#include<iostream> 
#include<cstring>
#include<string>
#include<vector>

typedef long long ll;
#define MAX 20
using namespace std;

int N, Oper_Num;
char map[MAX];
bool GwalHo[MAX];
ll Answer = -98756432198765;

ll Actual_Calc(ll n1, ll n2, string B) {
	if(B == "*") return n1 * n2;
	else if(B == "+") return n1 + n2;
	else if(B == "-") return n1 - n2;
}
ll Calculate(void) {
	vector<string> v;
	
	for(int i=0; i<N;) {
		if(!GwalHo[i]) {
			string s = "";
			s += map[i];
			v.push_back(s);
			i++;
		} else {
			string s = "";
			s += map[i];
			ll Temp1 = stoi(s);
			
			s = "";
			s += map[i+2];
			ll Temp2 = stoi(s);
			
			s = "";
			s += map[i+1];
			string B_Temp = s;
			
			ll Temp_Result = Actual_Calc(Temp1, Temp2, B_Temp);
			v.push_back(to_string(Temp_Result));
			i += 3;
		}
	}
	
	ll R_Value = stoi(v[0]);
	for(int i=1; i<v.size(); i+=2) {
		if(v[i] == "+") {
			R_Value += stoi(v[i+1]);
		} else if(v[i] == "-") {
			R_Value -= stoi(v[i+1]);
		} else if(v[i] == "*") {
			R_Value *= stoi(v[i+1]);
		}
	}
	
	return R_Value;
}
void DFS(int idx) {
	if(idx >= N) {
		Answer = max(Answer, Calculate());
		return; 
	}
	
	for(int i=idx; i<N; i++) {
		if(i+2 < N) {
			if(!GwalHo[i] && !GwalHo[i+2]) {
				GwalHo[i] = true;
				GwalHo[i+2] = true;
				DFS(idx + 2);
				GwalHo[i] = false;
				GwalHo[i+2] = false;
			}
		} else {
			DFS(i + 1);
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%c", &map[i]);
	}
	Oper_Num = N / 2;
	
	// SIMULATION
	DFS(0);
	
	// OUTPUT
	printf("%lld\n", Answer);
	return 0;
}
