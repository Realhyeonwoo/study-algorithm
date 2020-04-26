#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num[n+1];
    for(int i=2; i<=n; i++) num[i] = 1;
    
    for(int i=2; i<=n; i++) {
        for(int j=i*2; j<=n; j+=i) num[j] = 0;
    }
    
    for(int i=1; i<=n; i++) {
        if(num[i] == 1) answer++;
    }
    return answer;
}
