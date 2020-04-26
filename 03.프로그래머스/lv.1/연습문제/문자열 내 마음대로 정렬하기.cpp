#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int i = 0; 
bool compare(string a, string b) {
    if(a[i] == b[i]) {
        return a < b;
    } else {
        return a[i] < b[i];
    }
    
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    i = n;
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    
    return answer;
}
