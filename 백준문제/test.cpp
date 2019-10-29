#include<cmath>
#include<iostream>
using namespace std;

long long solution(int w,int h)
{
	long long answer = 1;
    long double x[h+1];
    
    for(int i=1; i<=h; i++) {
        x[i] = (double)w / h * i;
    }
   
    for(int i=1; i<=h; i++) {
        cout << x[i] << endl;
    }
    for(int i=1; i<=h-1; i++) {
        answer += ceil(x[i+1]) - ceil(x[i]) * i;
    }
    
    answer = answer * 2; 
	return answer;
}

int main(void) {
	long long answer = solution(8, 12); 	
	cout << endl;
	cout << endl;
	cout << answer << endl; 
}
