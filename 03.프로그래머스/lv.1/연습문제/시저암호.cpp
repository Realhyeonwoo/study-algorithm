#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); i++) {
        for(int j=1; j<=n; j++) {
            if(s[i] == 'z') {
                s[i] = 'a';
                continue;
            }
            if(s[i] == 'Z') {
                s[i] = 'A';
                continue;
            }
            if (isspace(s[i]) != 0) {
                continue;
            }
            s[i] = char(s[i] + 1);
        }
        answer += s[i];
    }
    return answer;
}
