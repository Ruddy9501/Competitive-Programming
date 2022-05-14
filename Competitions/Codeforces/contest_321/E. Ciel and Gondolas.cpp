/*
2018-10-15 05:24:35
https://codeforces.com/contest/321/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = 1<<30;
const int MAXN = 4005;
const int MAXM = 805;
 
int n, m;
int dp[MAXM][MAXN], s[MAXN][MAXN];
 
int cost (int j, int i){
    --j;
    return (s[i][i] - s[i][j] - s[j][i] + s[j][j]) / 2;
}
 
void get (int k, int l, int r, int optL, int optR){
 
     if (l > r) return;
 
     int i = (l + r) >> 1;
     int opt = -1;
     for (int j = max (0, optL); j <= optR && j < i; ++j){
          int ct = dp[k-1][j] + cost (j+1, i);
          if (ct <= dp[k][i]){
              dp[k][i] = ct;
              opt = j;
          }
     }
 
     get (k, l, i-1, optL, opt);
     get (k, i+1, r, opt, optR);
}
 
int main(){
 
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
         for (int j = 1; j <= n; ++j){
              scanf ("%d", &s[i][j]);
              s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
         }
    }
 
    for (int i = 0; i <= m; ++i)
         for (int j = 0; j <= n; ++j)
              dp[i][j] = oo;
 
    for (int i = 1; i <= n; ++i)
         dp[1][i] = cost (1, i);
 
    for (int i = 2; i <= m; ++i)
         get (i, 1, n, 1, n);
 
    printf ("%d\n", dp[m][n]);
 
 
    return 0;
}