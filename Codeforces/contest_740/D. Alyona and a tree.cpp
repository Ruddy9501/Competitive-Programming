/*
2016-11-23 22:42:52
https://codeforces.com/contest/740/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int,int>pari;
const int RAN = 2*1e5+5;
#define ll long long
int n, A[RAN], P[RAN],l, I[RAN], F[RAN];
ll C[RAN];
vector <pari> V[RAN];
 
vector <ll> St[RAN*4];
 
void dfs(int nod, ll dis){
     P[++l] = nod;
     I[nod] = l;
     C[nod] = dis - A[nod];
     int t = (int)V[nod].size();
     for (int i = 0; i < t; i++){
          int newn = V[nod][i].first;
          ll newc = (ll)V[nod][i].second + dis;
 
          dfs(newn, newc);
     }
     F[nod] = l;
}
 
void built(int ini, int fin, int p){
 
     if (ini == fin){
         St[p].push_back(C[P[ini]]);
         return ;
     }
 
     int piv = (ini+fin)/2;
     built (ini, piv, p*2);
     built (piv+1, fin, p*2+1);
     merge(St[2*p].begin(), St[2*p].end(), St[2*p+1].begin(), St[2*p+1].end(), inserter(St[p], St[p].begin()));
}
 
int query(int ini, int fin, int p, int a, int b, ll num){
 
    if (ini > b || fin < a) return 0;
 
    if (ini >= a && fin <= b){
        return upper_bound(St[p].begin(), St[p].end(), num) - St[p].begin();
    }
 
    int piv = (ini+fin)/2;
    return query(ini, piv, p*2, a, b, num) + query(piv+1, fin, p*2+1, a, b, num);
}
 
int main(){
 
   scanf ("%lld", &n);
   for (int i = 1; i <= n; i++)
        scanf ("%lld", &A[i]);
 
   for (int i = 1; i < n; i++){
        int a, b;scanf ("%d %d", &a, &b);
        V[a].push_back(pari(i+1, b));
   }
 
   dfs(1, 0);
 
   built(1, n, 1);
   for (int i = 1; i <= n; i++){
        printf ("%d ", query(1, n, 1, I[i]+1, F[i], C[i]+A[i]) );
   }
 
   return 0;
}