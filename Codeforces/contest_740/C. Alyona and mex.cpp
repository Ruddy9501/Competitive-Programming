/*
2016-11-23 20:31:55
https://codeforces.com/contest/740/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, m, a, b, mi = 1<<30, ini, fin;
int S[1000000];
int main(){
 
   scanf ("%d%d", &n, &m);
   for (int i = 1; i <= m; i++){
        scanf ("%d %d", &a, &b);
        if (abs(a-b) < mi){
            mi = abs(a-b);
            ini = min(a, b);
            fin = max(a, b);
        }
   }
 
   int c = 0; mi++;
   for (int i = ini; i <= n; i++){
        S[i] = c;
        c++;
        c %= mi;
   }
 
   c = mi-1;
   for (int i = ini-1; i >= 1; i--){
        S[i] = c;
        c--;
        c = (c+mi)%mi;
   }
 
   printf ("%d\n", mi);
   for (int i = 1; i <= n; i++){
        if (i == 1) printf ("%d", S[i]);
         else printf (" %d", S[i]);
   }
   printf ("\n");
 
   return 0;
}