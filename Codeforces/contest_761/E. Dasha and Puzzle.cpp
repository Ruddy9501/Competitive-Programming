/*
2017-01-31 23:37:50
https://codeforces.com/contest/761/problem/E
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 1e6+5;
 
ll n, a, b, R, C[100], X[100], Y[100];
vector <ll> V[100];
 
const ll mx[] = {1 , -1, 0, 0},
         my[] = {0, 0, 1, -1};
 
bool  D[100][4], M[100][100];
 
void dfs(int nod, ll d){
     for (int i = 0; i < V[nod].size(); i++){
          int newn = V[nod][i];
          if (!M[nod][newn]){
              int mo;
              for (int i = 0; i < 4; i++)
                   if (!D[nod][i]){
                       D[nod][i]  = true;
                       mo = i;
                       if (i == 0) D[newn][1] = true;
                       if (i == 1) D[newn][0] = true;
                       if (i == 2) D[newn][3] = true;
                       if (i == 3) D[newn][2] = true;
                       break;
                   }
 
              M[nod][newn] = M[newn][nod] = true;
              X[newn] = X[nod] + (1ll<<d)*mx[mo];
              Y[newn] = Y[nod] + (1ll<<d)*my[mo];
 
              dfs(newn, d-1ll);
          }
     }
}
 
int main() {
 
    cin >> n;
    for (int i = 1; i < n; i++){
         cin >> a >> b;
         V[a].push_back(b);
         V[b].push_back(a);
         C[a]++, C[b]++;
    }
 
    for (int i = 1; i <= n; i++){
         if (C[i] > 4){
             cout << "NO\n";
             return 0;
         }
    }
 
    dfs(1, 31ll);
 
    cout << "YES\n";
    for (int i = 1; i <= n; i++){
         cout << X[i] << " " << Y[i] << "\n";
    }
 
    return 0;
}