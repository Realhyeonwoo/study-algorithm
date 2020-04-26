#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int multi = n * m;
    
    while(m != 0) {
        int temp = n % m;
        n = m;
        m = temp;
    }
    answer.push_back(n);
    answer.push_back(multi / n);
    return answer;
}
