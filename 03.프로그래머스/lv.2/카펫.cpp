#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int temp = (brown - 4) / 2;
    
    // printf("%d %d\n", temp, red);
    for(int i=1; i<=temp/2; i++) {
        if(i*(temp-i) == red) {
            answer.push_back(i+2);
            answer.push_back(temp-i+2);
            break;
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());
    return answer;
}
