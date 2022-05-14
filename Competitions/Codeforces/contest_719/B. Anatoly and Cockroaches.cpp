/*
2016-11-23 03:51:58
https://codeforces.com/contest/719/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
int n, sol, r, b;
char A[RAN];
int main(){
 
    scanf ("%d", &n);
    scanf ("%s", A);
    for (int i = 0; i < n; i++){
         if (  i%2  && A[i] == 'r') r++;
         if (!(i%2) && A[i] == 'b') b++;
    }
 
    sol = min(r,b) + max(r,b)-min(r,b);
 
    r = b = 0;
    for (int i = 0; i < n; i++){
         if (  i%2  && A[i] == 'b') r++;
         if (!(i%2) && A[i] == 'r') b++;
    }
 
    sol = min(sol, min(r,b) + max(r,b)-min(r,b));
 
    printf ("%d\n", sol);
 
   return 0;
}