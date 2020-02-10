#include<iostream>
#include<string>
#include<math.h>
#include<memory.h>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int ground[15][15] = { 0, };
int cpy[15][15][2] = { 0, };
int archer[15] = { 0, };
int N, M, D;

void setCpy(int n) {
   int i, j;
   if (n == 1) {
      for (i = 0; i < N; i++) {
         for (j = 0; j < M; j++) {
            cpy[i][j][0] = ground[i][j];
            cpy[i][j][1] = ground[i][j];
         }
      }
   }else if (n == 2) {
      for (i = 0; i < N; i++) {
         for (j = 0; j < M; j++) {
            cpy[i][j][0] = cpy[i][j][1];
         }
      }
   }
}

int goUp(int loc_i, int loc_j) { // 현재 궁수위치에서 가장 가까운 적 죽임
   int i, j, dist;
   int min = loc_i + M;
   int kill_i = -1, kill_j = -1;

   //if (loc_i == 0) return;

   for (j = 0; j < M; j++) {
      for (i = loc_i - 1; i >= 0; i--) {
         if (cpy[i][j][0] == 0) continue;
         dist = abs(loc_i - i) + abs(loc_j - j);
         if (min > dist) {
            min = dist;
            if (min <= D) {
               kill_i = i;
               kill_j = j;
            }
         }
      }
   }

   if ( kill_i == -1) { // 못죽임
      return 0;
   }
   else {
      if (cpy[kill_i][kill_j][1] == 0) return 0;
      cpy[kill_i][kill_j][1] = 0;
      return 1;
   }
}

int setArcher(int loc, int depth, int max) {
   int i, j, idxA, now;
   
   if (depth == 3) { // 궁수 배치 끝
      setCpy(1);
      now = 0; //현재 배치에서 죽인 적 세아림
      for (i = N; i > 0; i--) {
         setCpy(2);
         for (idxA = 0; idxA < 15; idxA++) {
            if (archer[idxA]) {
               now += goUp(i, idxA);
            }
         }
      }
      return now;
   }

   for (i = loc; i < M; i++) {
      archer[i] = 1;
      now = setArcher(i + 1, depth + 1, max);
      if (max < now) max = now;
      archer[i] = 0;
   }

   return max;
}

int main(int argc, char** argv)
{
   int i, j, k, answer = 0;


   cin >> N >> M >> D;

   for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
         cin >> ground[i][j];
      }
   }

   answer = setArcher(0, 0, 0);
   
   cout << answer << endl;

   return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
