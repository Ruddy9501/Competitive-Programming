/*
2016-11-15 20:24:51
https://codeforces.com/contest/734/problem/C
*/
#include <iostream>
#define ll long long
#define RAN 1000000
using namespace std;
 
ll n, m, k, sol, x, s, T[RAN], P1[RAN], P2[RAN], C[RAN];
 
ll busqueda(ll tot){
   int ini = 1, fin = k;
   int p = -1;
   while (ini <= fin){
          int piv = (ini+fin)/2;
          if (tot >= P2[piv]){
              p = piv;
              ini = piv+1;
          }
          else
             fin = piv-1;
   }
 
   return  p;
}
 
int main(){
 
    cin >> n >> m >> k;
    cin >> x >> s;
    ll sol = x*n;
    for (int i = 1; i <= m; i++){
         cin >> T[i];
    }
 
    for (int i = 1; i <= m; i++){
         cin >> P1[i];
         if (P1[i] <= s)
             sol = min (sol, n*T[i]);
    }
 
    for (int i = 1; i <= k; i++){
         cin >> C[i];
    }
 
    for (int i = 1; i <= k; i++){
         cin >> P2[i];
         if (P2[i] <= s){
             sol = min (sol, x*(n-C[i]));
         }
    }
 
    for (int i = 1; i <= m; i++){
         if (P1[i] > s) continue;
         int p = busqueda(s-P1[i]);
         ll a;
         if (p == -1) continue;
              a = (n-C[p])*T[i];
         sol = min (sol, a);
    }
 
    cout << sol << "\n";
 
    return 0;
}