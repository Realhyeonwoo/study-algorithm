#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int N;
int room[3][200];

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		memset(room, 0, sizeof(room));
		scanf("%d", &N);
		for(int student=0; student<N; student++) {
			int start, end;
			scanf("%d %d", &start, &end);
			
			int sIndex, eIndex;
			sIndex = (start%2 == 0) ? start/2-1 : start/2;
			eIndex = (end%2 == 0) ? end/2-1 : end/2;
			if(sIndex > eIndex) {
				int temp = sIndex;
				sIndex = eIndex;
				eIndex = temp;
			}
			for(int corridor=sIndex; corridor<=eIndex; corridor++) {
				room[1][corridor]++;
			}
		}
		
		int answer = *max_element(room[1], room[1]+200);
		
		printf("#%d %d", test_case, answer);		
	}
	return 0;
}
