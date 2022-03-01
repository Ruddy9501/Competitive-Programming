/*
2017-01-25 16:46:53
https://codeforces.com/contest/749/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2*1e5 + 5;
 
int n, m, a, b, k, A[RAN], B[RAN], C[RAN];
vector <int> V[RAN];
 
bool funcion(int p, bool yes){
     int can = 0;
     bool mar = false;
     for (int i = 1; i <= m; i++){
          if (A[p] == C[i])
              mar = true;
          can += V[C[i]].end() - upper_bound(V[C[i]].begin(), V[C[i]].end(), p);
     }
     if (yes) mar = false;
     if (mar){
         if (can == n-p) return true;
          else return false;
     }
     if (can == n-p) return true;
     return false;
}
 
int bus_bin(){
    int ini = 0, fin = n, sol;
    while (ini <= fin){
           int piv = (ini+fin)/2;
           if (funcion(piv, false))
               fin = piv-1, sol = piv;
            else
               ini = piv+1;
    }
    return sol;
}
 
int bus_bin2(int p){
    int ini = 0, fin = V[A[p]].size();
    int sol = -1;
    while (ini <= fin){
           int piv = (ini+fin)/2;
           if (funcion(V[A[p]][piv], true))
               fin = piv-1, sol = V[A[p]][piv];
            else
               ini = piv+1;
    }
    return sol;
}
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d%d", &a, &b);
         V[a].push_back(i);
         A[i] = a;
         B[i] = b;
    }
 
    scanf ("%d", &k);
 
    while (k--){
           scanf ("%d", &m);
           for (int i = 1; i <= m; i++){
                scanf ("%d", &C[i]);
           }
 
           int sol = bus_bin();
           if (sol == 0) printf ("0 0\n");
            else {
                C[++m] = A[sol];
                sol = bus_bin2(sol);
                printf ("%d %d\n", A[sol], B[sol]);
            }
    }
    return 0;
}