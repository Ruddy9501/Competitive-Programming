/*
2016-11-23 03:42:58
https://codeforces.com/contest/719/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, A[1000];
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);
 
    if (A[n] == 0) {
        printf ("UP\n");
        return 0;
    }
    if (A[n] == 15){
        printf ("DOWN\n");
        return 0;
    }
 
     if (n > 1) {
        if (A[n-1] < A[n]) printf ("UP\n");
         else printf ("DOWN\n");
 
      }else
        printf ("-1\n");
 
   return 0;
}