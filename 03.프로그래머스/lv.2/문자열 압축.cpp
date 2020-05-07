#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 987564321;
    int len = s.size();
    vector<string> v;
    
    if(len == 1) return 1;
    
    for(int i=len/2; i>=1; i--) {
        v.clear();
        for(int j=0; j<len; j+=i) {
            v.push_back(s.substr(j, i));
        }
        
        int index = 1;
        for(int a=0; a<v.size()-1; a+=index) {
            index = 1;
            for(int j=a+1; j<v.size(); j++) {
                if(v[a] != v[j]) break;
                v[j] = "";
                index++;
            }
            if(index != 1) v[a] = to_string(index) + v[a];
        }
        
        int sum = 0;
        for(int a=0; a<v.size(); a++) {
            sum += v[a].length();
        }
        
        if(sum < answer) answer = sum;
    }
    
    return answer;
}
