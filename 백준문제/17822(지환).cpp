/*
	map copy 후 비교 할때 실제맵 비교하고 copy맵 변경 
*/

#include<iostream>
#include<string>
#include<math.h>
#include<memory.h>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int plain[51][51] = { 0, };
int cpy[51][51] = { 0, };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void setCpy(int n) {
   int i, j;
   if (n == 1) {
      for (i = 0; i < 51; i++) {
         for (j = 0; j < 51; j++) {
            cpy[i][j] = plain[i][j];
         }
      }
   }else if (n == 2) {
      for (i = 0; i < 51; i++) {
         for (j = 0; j < 51; j++) {
             plain[i][j] = cpy[i][j];
         }
      }
   }
}

int eraseNum(int N, int M) { // 인접한 같은 수 없애기
   int i, j, ni, nj, dir, flag = 0;

   setCpy(1);

   for (i = 1; i <= N; i++) {
      for (j = 1; j <= M; j++) {
         if (plain[i][j] == 0) continue;
         for (dir = 0; dir < 4; dir++) {
            ni = i + dx[dir];
            nj = j + dy[dir];

            if (ni < 1 || ni > N) continue;
            if (nj < 1) nj = M;
            if (nj > M) nj = 1;

            if (plain[i][j] == plain[ni][nj]) {
               cpy[i][j] = 0;
               cpy[ni][nj] = 0;
               flag = 1;
            }
         }
      }
   }

   setCpy(2);

   return flag;
}

int main(int argc, char** argv)
{
   int i, j, k, answer = 0;;
   int N, M;
   int T;
   int turn;
   int x, d;
   int tmp;
   int rotate, flag, sum, cnt;

   cin >> N >> M >> T;

   for (i = 1; i <= N; i++) {
      for (j = 1; j <= M; j++) {
         cin >> plain[i][j];
      }
   }

   for (turn = 0; turn < T; turn++) {
      cin >> x >> d >> k;
      for (i = 1; i <= N; i++) {
         if (i % x == 0) { // 원판 번호가 배수
            if (d == 0) {
               for (rotate = 0; rotate < k; rotate++) {
                  tmp = plain[i][M];
                  for (j = M - 1; j >= 1; j--) { // 시계방향 돌리기
                     plain[i][j + 1] = plain[i][j];
                  }
                  plain[i][1] = tmp;
               }
            }
            else if (d == 1) {
               for (rotate = 0; rotate < k; rotate++) {
                  tmp = plain[i][1];
                  for (j = 2; j <= M; j++) { // 시계반대방향 돌리기
                     plain[i][j - 1] = plain[i][j];
                  }
                  plain[i][M] = tmp;
               }
            }
         }
      } // 돌리기 끝

      flag = eraseNum(N, M);

      if (flag == 0) { //지울 수 없음
         sum = 0;
         cnt = 0;
         for (i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
               sum += plain[i][j];
               if (plain[i][j] != 0) cnt++;
            }
         }
         for (i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
               if (cnt == 0) break;
               if ((double)plain[i][j] < ((double)sum / (double)cnt) && plain[i][j] != 0) plain[i][j]++;
               else if ((double)plain[i][j] > ((double)sum / (double)cnt)) plain[i][j]--;
            }
         }
      }
   }

   answer = 0;
   for (i = 1; i <= N; i++) {
      for (j = 1; j <= M; j++) {
         answer += plain[i][j];
      }
   }
   
   cout << answer << endl;

   return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
