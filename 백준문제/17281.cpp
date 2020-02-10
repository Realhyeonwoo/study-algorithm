#include<cstdio>
#include<vector>
using namespace std;

int n;
bool visited[10] = {false,};
vector<int> v;
int arr[51][10];
int new_arr[51][10];

int last = 1;
int out = 0; 
int ground[4];
int score;
vector<int> total;


void Simulate(int num) {
	if (num == 0) {
		out++;
	}
	else if (num == 1) {
		if (ground[1] == 0 && ground[2] == 0 && ground[3] == 0) {
			ground[1] = 1;
			ground[2] = 0;
			ground[3] = 0;
		}
		else if (ground[1] == 0 && ground[2] == 0) {
			ground[1] = 1;
			ground[2] = 0;
			ground[3] = 0;
			score += 1;	
		}
		else if (ground[1] == 0 && ground[3] == 0) {
			ground[1] = 1;
			ground[2] = 0;
			ground[3] = 1;
		}
		else if (ground[2] == 0 && ground[3] == 0) {
			ground[1] = 1;
			ground[2] = 1;
			ground[3] = 0;
		}
		else if (ground[1] == 0 ) {
			ground[1] = 1;
			ground[2] = 0;
			ground[3] = 1;
			score += 1;
		}
		else if (ground[2] == 0) {
			ground[1] = 1;
			ground[2] = 1;
			ground[3] = 0;
			score += 1;
		}
		else if (ground[3] == 0) {
			ground[1] = 1;
			ground[2] = 1;
			ground[3] = 1;
		}
		else {
			ground[1] = 1;
			ground[2] = 1;
			ground[3] = 1;
			score++;
		}
	}
	else if (num == 2) {
		if (ground[1] == 0 && ground[2] == 0 && ground[3] == 0) {
			ground[1] = 0;
			ground[2] = 1;
			ground[3] = 0;
		}
		else if (ground[1] == 0 && ground[2] == 0) {
			ground[1] = 0;
			ground[2] = 1;
			ground[3] = 0;
			score += 1;
		}
		else if (ground[1] == 0 && ground[3] == 0) {
			score += 1;
			
		}
		else if (ground[2] == 0 && ground[3] == 0) {
			ground[3]++;
			ground[2]++;
			ground[1] = 0;
		}
		else if (ground[1] == 0) {
			score += 2;
			ground[3] = 0;
		}
		else if (ground[2] == 0) {
			ground[2]++;
			ground[1] = 0; 
			score += 1;
		}
		else if (ground[3] == 0) {
			ground[1] = 0;
			ground[3]++;
			score += 1;
		}
		else {
			ground[1] = 0;
			score += 2;
		}
	}
	else if (num == 3) {
		if (ground[1] == 0 && ground[2] == 0 && ground[3] == 0) {
			ground[3]++;
		}
		else if (ground[1] == 0 && ground[2] == 0) {
			score += 1;
		}
		else if (ground[1] == 0 && ground[3] == 0) {
			ground[2] = 0;
			ground[3]++;
			score += 1;
		}
		else if (ground[2] == 0 && ground[3] == 0) {
			ground[1] = 0;
			ground[3]++;
			score += 1;
		}
		else if (ground[1] == 0) {
			ground[2] = 0;
			score += 2;
		}
		else if (ground[2] == 0) {
			ground[1] = 0;
			score += 2;
		}
		else if (ground[3] == 0) {
			ground[1] = 0;
			ground[2] = 0;
			ground[3]++;
			score += 2;
		}
		else {
			ground[1] = 0;
			ground[2] = 0;
			score += 3;
		}
	}
	else if (num == 4) {
		for (int i = 1; i < 4; i++) {
			if (ground[i] != 0) {
				score++;
				ground[i] = 0;
			}
		}
		score += 1;
	}
	return;
}

void Play() {
	for(int i=1; i<=n; i++)	 {
		while(last<=9) {
			Simulate(new_arr[i][last]);
			
			if (last == 9) {
				last = 1;
			}
			else {
				last++;
			}
			
			if (out == 3) {
				out = 0; 
				break;
			}
		}
		// �̴� ������ �ʱ�ȭ 
		for(int i=1; i<4; i++) {
			ground[i] = 0;
		}
	}
}

void Dfs(int cnt) {
	if(cnt == 8) {
		// new_array�� Ÿ�� ���� �迭 
		// 4�� Ÿ�ڿ��� 1�� ���� ����
		// 1~3�� 5~9�� �ڸ����� ��������� �Ҵ�  
		for(int i=0; i<=v.size(); i++) {
			for(int j=1; j<=n; j++) {
				if(i>=0 && i<3) {
					new_arr[j][i+1] = arr[j][v[i]];
				}
				else if(i == 3) {
					new_arr[j][i+1] = arr[j][1];
				}
				else if(i > 3){
					new_arr[j][i+1] = arr[j][v[i-1]];	
				}
			}
		}
		
		//������ ���� �迭�� �ùķ��̼��� ���� ������ ��� 
		Play();
		
		// �� ������ �ùķ��̼��� ������ �ش� �ùķ��̼��� ������� �� �ʱ�ȭ 
		total.push_back(score);
		score = 0; 
		last = 1; 
		return;
	}
	
	for(int i=2; i<10; i++) {
		if(visited[i] == true) continue;
		visited[i] = true;
		v.push_back(i);
		Dfs(cnt+1);
		v.pop_back();
		visited[i] = false;
	}
}

void Input() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

int main(void){
	Input();
	Dfs(0);

	// �ְ� ���� ���ϱ� 
	int max = total[0];
	for(int i=1; i<total.size(); i++) {
		if(max < total[i]) {
			max = total[i];
		}
	}
	printf("%d\n", max);
	
	return 0; 
}

