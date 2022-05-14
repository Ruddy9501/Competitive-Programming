/*
2015-12-09 20:59:02
https://codeforces.com/contest/606/problem/C
*/
#include <cstdio>
#include <algorithm>
 
#define RAN 1000000
using namespace std;
 
int n, c, p,sol,A[RAN], S[RAN], Val[RAN], Ant[RAN];
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         S[A[i]] = S[A[i]-1]+1;
         sol = max(sol,S[A[i]]);
    }
 
    printf ("%d\n", n-sol);
    //imprimir (Pos[c]);
 
    return 0;
}