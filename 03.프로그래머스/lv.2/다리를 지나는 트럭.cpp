#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int time = 0, sum = 0, truckIdx = 0;
    
    while(1) {
        time++;
        
        if(q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }
        
        if(sum + truck_weights[truckIdx] <= weight) {
            if(truckIdx == truck_weights.size()-1) {
                time += bridge_length;
                break;
            }
            q.push(truck_weights[truckIdx]);
            sum += truck_weights[truckIdx];
            truckIdx++;
        } else {
            q.push(0);
        }
    }
}
