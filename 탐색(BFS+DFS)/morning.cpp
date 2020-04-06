#include<iostream>
using namespace std;

int** a;
int main(void) {
	int num[3][3];
	a = num;
	int count = 0;
	for(int y=0; y<3; y++) {
		for(int x=0; x<3; x++) {
			a[y][x] = count++;
		}
	}
	for(int y=0; y<3; y++) {
		for(int x=0; x<3; x++) {
			printf("%d ", a[y][x]);
		}
		printf("\n");
	}
}
