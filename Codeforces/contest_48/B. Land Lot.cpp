/*
2016-06-08 16:38:58
https://codeforces.com/contest/48/problem/B
*/

#include <bits/stdc++.h>
 
using namespace std;
int n, m, a, b, sol, T[105][105];
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= m; j++){
              cin >> a;
              T[i][j] = T[i-1][j] + T[i][j-1] - T[i-1][j-1];
              if (a == 1)
                  T[i][j]++;
         }
    }
 
    cin >> a >> b;
 
    sol = 500*500;a--,b--;
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++){
              if (i+a <= n && j+b <= m){
                  sol = min (sol, T[i+a][j+b]+T[i-1][j-1]-T[i+a][j-1]-T[i-1][j+b]);
              }
              if (i+b <= n && j+a <= m){
                  sol = min (sol, T[i+b][j+a]+T[i-1][j-1]-T[i+b][j-1]-T[i-1][j+a]);
              }
         }
    cout << sol << endl;
 
    return 0;
}