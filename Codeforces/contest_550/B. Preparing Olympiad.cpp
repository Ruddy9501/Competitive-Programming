/*
2015-06-04 20:24:59
https://codeforces.com/contest/550/problem/B
*/
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n, M, m, d, mi, ma, sum,c,sol, A[1000005];
 
int main(){
 
    scanf ("%d%d%d%d", &n, &M, &m, &d);
    for (int i = 1; i <= n; i++) scanf ("%d", &A[i]);
 
    for (int i = 1; i <  1<<n; i++){
         sum = 0;
         mi = 1<<30;
          ma = 0;c=0;
         for (int j = 0; j < n; j++)
              if (i & 1<<j){
                  c++;
                  sum += A[j+1];
                  mi = min (mi, A[j+1]);
                  ma = max (ma, A[j+1]);
              }
         if (sum >= M && sum <= m && ma-mi >= d && c > 1)sol++;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}