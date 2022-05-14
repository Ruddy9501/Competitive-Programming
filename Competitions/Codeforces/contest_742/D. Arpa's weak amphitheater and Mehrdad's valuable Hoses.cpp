/*
2016-12-06 19:23:48
https://codeforces.com/contest/742/problem/D
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int RAN = 1e3+5;
int n, m, T;
int P[RAN];
bool M[RAN][RAN], m1[RAN];
ll B[RAN], Dp[RAN][RAN], sol;
queue <int> Q;
vector <int> V[RAN], v;
 
void bfs(int nod){
   v.push_back(nod);
   Q.push(nod);
   int newn;
   while (!Q.empty()){
          nod = Q.front();
          Q.pop();
          int l = V[nod].size();
          for (int i = 0; i < l; i++){
               newn = V[nod][i];
               if (!m1[newn]){
                   m1[newn] = true;
                   v.push_back(newn);
                   Q.push(newn);
               }
          }
   }
}
 
void mochila (int pos, int p, ll b){
     M[pos-1][0] = true;
     for (int i = 0; i+p <= T; i++){
         // Dp[pos][i] = max(Dp[pos-1][i], Dp[pos][i]);
          if (M[pos-1][i]){
              M[pos][i+p] = true;
              Dp[pos][i+p] = max(Dp[pos][i+p], Dp[pos-1][i] + b);
              sol = max(sol, Dp[pos][i+p]);
          }
     }
}
 
int main(){
 
    scanf ("%d%d%d", &n, &m, &T);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &P[i]);
 
    for (int i = 1; i <= n; i++)
         scanf ("%lld", &B[i]);
 
    for (int i = 1; i <= m; i++){
         int a, b;
         scanf ("%d%d", &a, &b);
         V[a].push_back(b);
         V[b].push_back(a);
    }
 
    M[0][0] = true; int c = 0;
    for (int i = 1; i <= n; i++){
         if (m1[i]) continue;
         m1[i] = true;
         v.clear();
         bfs(i);
         int p = 0;
         ll t = 0;
         int l = v.size();
         c++;
         for (int j = 0; j < l; j++){
               mochila(c, P[v[j]], B[v[j]]);
               p += P[v[j]];
               t += B[v[j]];
         }
 
         mochila(c, p, t);
         for (int i = 1; i <= T; i++){
              if (M[c-1][i]) M[c][i] = true;
              Dp[c][i] = max(Dp[c-1][i], Dp[c][i]);
         }
    }
 
    printf ("%lld\n", sol);
 
    return 0;
}