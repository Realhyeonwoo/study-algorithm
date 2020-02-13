#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int X;
vector<int> stick;

int main(void) {
	scanf("%d", &X);
	
	stick.push_back(64);
	while(true) {
		// 1
		int sum = 0;
		for(int i=0; i<stick.size(); i++) {
			sum += stick[i];
		}
		if(sum <= X) break;
		// 1-1 
		int minStick = *min_element(stick.begin(), stick.end());
		for(int i=0; i<stick.size(); i++) {
			if(minStick == stick[i]) {
				int halfStick = minStick / 2;
				stick[i] = halfStick;
				stick.push_back(halfStick);
				break;
			}
		}	
		// 1-2
		sum = 0; 
		for(int i=0; i<stick.size()-1; i++) {
			sum += stick[i];
		}
		if(sum >= X) stick.pop_back();
	}
	
	// 결과 출력 
	int count = 0; 
	for(int i=0; i<stick.size(); i++) {
		if(stick[i] != 0) {
			count++;
		}
		
	}
	printf("%d\n", count);
	
	return 0;
}

