#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a == b) return a;
    
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    for(int i=a; i<=b; i++) {
        answer += (long long) i;
    }
    // answer = (long long)((a + b) * (b - a + 1) ) / (long long)2;
    return answer;
}
