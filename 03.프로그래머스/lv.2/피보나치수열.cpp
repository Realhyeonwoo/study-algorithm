#include <string>
#include <vector>
using namespace std;

int dp[100001];

int solution(int n) {
    dp[1] = 1;
    dp[2] = 1;
    if(n == 1) return dp[1];
    else if(n == 2) return dp[2];
    
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    return dp[n];
}
