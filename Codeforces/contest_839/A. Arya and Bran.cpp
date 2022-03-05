/*
2017-08-14 19:38:47
https://codeforces.com/contest/839/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, a, can, tot;
 
int main(){
 
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         tot += a;
         if (tot <= 8) can += tot;
          else can += 8;
 
         tot = max(tot-8, 0);
 
         if (can >= k){
             printf ("%d\n", i);
             return 0;
         }
    }
 
    printf ("-1\n");
 
 
 
    return 0;
}