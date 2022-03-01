/*
2017-01-19 18:49:39
https://codeforces.com/contest/758/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long n, m, k, x, y, A[1005][1005], can, mi, ma;
int main(){
 
    scanf ("%lld %lld %lld %lld %lld", &n, &m, &k, &x, &y);
    if (n > 1){
        can = k / ((n + n-2ll)*m);
        k = k%((n + n-2ll)*m);
    }
    else{
        can = k / (n*m);
        k  %= (n*m);
    }
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= m; j++){
              if (i == 1 || i == n) A[i][j] = can;
              else A[i][j] = can*2ll;
         }
    }
 
 
    for (int i = 1; i <= n; i++){
         if (k == 0) break;
         for (int j = 1; j <= m; j++){
              if (k == 0) break;
              k--;
              A[i][j]++;
         }
    }
 
    for (int i = n-1; i >= 1; i--){
         if (k == 0) break;
         for (int j = 1; j <= m; j++){
              if (k == 0) break;
              k--;
              A[i][j]++;
         }
    }
 
    ma = A[1][1];
    mi = A[1][1];
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= m; j++){
              ma = max(ma, A[i][j]);
              mi = min(mi, A[i][j]);
         }
    }
 
    printf ("%lld %lld %lld\n",ma, mi, A[x][y]);
 
    return 0;
}