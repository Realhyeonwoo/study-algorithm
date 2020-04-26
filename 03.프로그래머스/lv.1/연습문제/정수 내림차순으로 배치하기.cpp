#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<string> v;
    string str = "";
    
    while(n != 0) {
        v.push_back(to_string(n%10));
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<string>());
    for(int i=0; i<v.size(); i++) str += v[i];
    answer = stoll(str);
    
    return answer;
}
