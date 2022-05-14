/*
2016-11-23 20:00:00
https://codeforces.com/contest/740/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, A[10000];
 
 
 
int main(){
 
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);
 
    int sol = 0;
    for (int i = 1; i <= m; i++){
        int a, b; scanf ("%d %d", &a, &b);
         int tot = 0;
         for (int j = a; j <= b; j++)
              tot += A[j];
         sol += max(tot, 0);
    }
 
    printf ("%d\n", max(0, sol));
 
    return 0;
}