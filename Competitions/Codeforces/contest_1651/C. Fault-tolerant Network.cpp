/*
2022-03-10 18:13:32
https://codeforces.com/contest/1651/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const long long RAN = 2 * 1e5 + 5;
const int oo = 1<<30;
 
int cas, con=1, n;
long long a[3][RAN], a1, a2, b1, b2, sol;
 
 
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           for (int i = 0; i < 2; ++i){
                for (int j = 1; j <= n; ++j){
                     scanf ("%lld", &a[i][j]);
                }
           }
 
           a1 = oo, a2 = oo, b1 = oo, b2 = oo;
           for (int i = 1; i <= n; ++i){
                a1 = min (a1, abs(a[0][1] -  a[1][i]));
                a2 = min (a2, abs(a[0][n] -  a[1][i]));
                b1 = min (b1, abs(a[1][1] -  a[0][i]));
                b2 = min (b2, abs(a[1][n] -  a[0][i]));
           }
 
           sol = abs (a[0][1] - a[1][1]) + abs (a[0][n] - a[1][n]);
           sol = min (sol, abs(a[0][1] - a[1][n]) + abs(a[0][n] - a[1][1]));
 
           sol = min (sol, abs(a[0][1] - a[1][1]) + a2 + b2);
           sol = min (sol, abs(a[0][1] - a[1][n]) + a2 + b1);
           sol = min (sol, abs(a[0][n] - a[1][1]) + a1 + b2);
           sol = min (sol, abs(a[0][n] - a[1][n]) + a1 + b1);
           sol = min (sol, a1 + a2 + b1 + b2);
 
           printf ("%lld\n", sol);
    }
 
    return 0;
}