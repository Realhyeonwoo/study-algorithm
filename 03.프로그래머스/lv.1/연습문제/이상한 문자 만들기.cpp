#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    int n = 0;;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            answer += s[i];
            n = 0;
            continue;
        }
        
        if(n%2 == 0) {
            if('A'<=s[i] && s[i]<='Z') answer += s[i];
            else answer += s[i] - 32;
        }
        else {
            if('a'<=s[i] && s[i]<='z') answer += s[i];
            else answer += s[i] + 32;
        }
        n++;
    }
    
    return answer;
}
