/*
2022-03-10 00:21:37
https://codeforces.com/contest/1650/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int cas, n, a[RAN], pos, s[RAN], aux[RAN];
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
         scanf ("%d", &n);
         for (int i = 1; i <= n; ++i){
              scanf ("%d", &a[i]);
         }
 
         for (int i = n; i >= 1; --i){
 
             // for (int j = 1; j <= n; ++j) printf ("%d ", a[j]); printf ("\n");
 
              if (a[i] != i){
 
                  pos = 0;
                  for (int j = 1; j < i; ++j)
                       if (a[j] == i)
                           pos = j;
 
                  s[i] = pos;
                  for (int j = 1; j <= i; ++j)
                       if (j > pos)
                           aux[j - pos] = a[j];
                       else
                           aux[i + j - pos] = a[j];
 
                  for (int j = 1; j <= i; ++j)
                       a[j] = aux[j];
              }
              else s[i] = 0;
         }
 
         printf ("%d", s[1]);
         for (int i = 2; i <= n; ++i) printf (" %d", s[i]);
         printf ("\n");
    }
 
 
    return 0;
}