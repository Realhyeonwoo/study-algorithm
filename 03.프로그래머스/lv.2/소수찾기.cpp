#include <string>
#include <vector>
#include <cstring>
#include<set>
using namespace std;

set<int> answer;

void isPrime(int num) {
    if(num== 0 || num == 1) return;
    for(int i=2; i<num; i++) {
        if(num%i == 0) return;
    }
    answer.insert(num);
}

void dfs(vector<int> num, vector<int> index, bool visited[], int count, int cnt) {
    if(count == cnt) {
        int sum = 0;
        for(int i=0; i<index.size(); i++) {
            for(int j=0; j<i; j++) {
                num[index[i]]*=10;
            }
            sum += num[index[i]];
        }
        isPrime(sum);
        return;
    }
    
    for(int i=0; i<num.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        index.push_back(i);
        dfs(num, index, visited, count, cnt+1);
        visited[i] = false;
        index.pop_back();
    }
}

int solution(string numbers) {
    int size = numbers.length();
    vector<int> num, index;
    bool visited[size];
    
    for(int i=0; i<size; i++) num.push_back(numbers[i] - '0');
    
    for(int i=1; i<=size; i++) {
        memset(visited, false, sizeof(visited));
        dfs(num, index, visited, i, 0);
        index.clear();
    }
    
    return answer.size();
}
