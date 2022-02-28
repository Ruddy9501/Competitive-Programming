/*
2015-11-24 22:53:39
https://codeforces.com/contest/602/problem/B
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#define RAN 1000000
 
using namespace std;
 
int a, b, n, sol, t;
 
struct par{
       int may, men;
}A[RAN][20];
 
main (){
 
     scanf ("%d\n", &n);
 
     for (int i = 1;i <= n; i++){
          scanf ("%d", &A[i][0].men);
          A[i][0].may = A[i][0].men;
     }
 
     t = (int) log2 (n);
     b = n;
     for (int i = 1; i <= t; i++){
          a = 1 << i - 1;
          b -= a;
          for (int j = 1; j <= b; j++){
               A[j][i].men = min (A[j][i - 1].men, A[j + a][i - 1].men);
               A[j][i].may = max (A[j][i - 1].may, A[j + a][i - 1].may);
            }
        }
 
 
     sol = 1;
     for (int i = 1; i <= n && i+sol <= n; i++){
          a = i;
          while(1){
            b = i+sol;
            if (b > n) break;
            t = (int) log2 (b - a);
            b = b - (1 << t) + 1;
            int mi = min (A[a][t].men, A[b][t].men);
            int ma = max (A[a][t].may, A[b][t].may);
            if (ma-mi <= 1) sol++;
             else break;
          }
     }
 
     printf ("%d\n", sol);
}