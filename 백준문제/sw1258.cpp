#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Box {
	int height;
	int width;
	int space;
};

int N; // 크기 
int map[100][100];
vector<Box> box;

bool compareSpace (Box b1, Box b2) {
	if(b1.space == b2.space) {
		return (b1.height < b2.height);
	} else {
		return (b1.space < b2.space);	
	}
}

void checkSize(int cy, int cx) {
	int height = 0;
	int width = 0;
	for(int y=cy; y<N; y++) {
		height++;
		map[y][cx] = 0;
		if(y+1 == N || map[y+1][cx] == 0) break;
	}
	for(int x=cx; x<N; x++) {
		width++;
		map[cy][x] = 0;
		if(x+1 == N || map[cy][x+1] == 0) break;
	}
	for(int y=cy; y<=cy+height; y++) {
		for(int x=cx; x<=cx+width; x++) {
			map[y][x] = 0;
		}
	}
	
	int space = height * width;
	Box b = {height, width, space};
	box.push_back(b);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// 입력 
		memset(map, 0, sizeof(map));
		box.clear();
		scanf("%d", &N);
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				scanf("%d", &map[y][x]);
			}
		}
		
		// 각 box 정보 저장(box 벡터에)  
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(map[y][x] != 0) {
					checkSize(y, x);
				}
			}
		}
		
		// 정렬 
		sort(box.begin(), box.end(), compareSpace);		
		
		// 출력 
		printf("# %d ", test_case);
		printf("%d ", box.size());
		for(int i=0; i<box.size(); i++) {
			Box b = box[i];
			printf("%d %d ", b.height, b.width);
		}
		printf("\n");
	}
	return 0;
}
