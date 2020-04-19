#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MIN -987654321
using namespace std;

string s;
bool visited[101];
vector<int> idx;

int solution(string answer_sheet, vector<string> sheets) {
	int answer = 0;
	vector<int> num;
	
	for(int i=0; i<sheets.size(); i++) {
		for(int j=i+1; j<sheets.size(); j++) {
			num.clear();
			for(int l=0; l<answer_sheet.length(); l++) {
				if((sheets[i][l] == sheets[j][l]) && (sheets[i][l] != answer_sheet[l])) {
					num.push_back(l);
				}
			}
			sort(num.begin(), num.end());
			if(num.size() == 0) continue;
			
			int succeed = 1;
			for(int i=0; i<num.size(); i++) {
				int count = 0;
				if(num[i]+1 == num[i+1]) {
					for(int j=i+1; j<num.size(); j++) {
						if(num[j]+1 == num[j+1]) count++;
					}
					succeed = max(succeed, count);
				}
			}
			if(succeed != 0 && succeed != 1) succeed--;
			
			if(answer < num.size() + succeed * succeed) {
				answer = num.size() + succeed * succeed;
			}

		}
	}
	return answer;
}

int main(void) {
	string a = "53241";
	vector<string> b;
	b.push_back("53241"); 
	b.push_back("42133");
	b.push_back("53241");
	b.push_back("14354");
	
	int answer = solution(a, b);
	printf("%d\n", answer);
	return 0;
}



//4132315142
//
//3241523133
//4121314445
//=> 4
//4132315142
//3241523133
//3243523133
//=> 1 2 3 5 6 7 9 10
//
//3241523133
//4433325251
//
//3241523133
//2412313253
//
//4121314445
//3243523133
//
//4121314445
//4433325251
//
//4121314445
//2412313253
//
//3243523133
//4433325251
//

//24551
//24553
//24553
//=> 1 + 1^2
//24551
//24553
//24553
//=> 1 + 1^2
//24551
//24553
//24553
//=> 1 + 1^2
//24551
//24553
//24553
//=> 1 + 1^2
//24551
//24553
//24553
//=> 1 + 1^2
//24551
//24553
//24553


//53241
//53241
//42133
//
//53241
//53241
//53241
//
//53241
//53241
//14354
//
//53241
//42133
//53241
//
//53241
//42133
//14354
//
//53241
//53241
//14354
