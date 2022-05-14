/*
2015-04-26 22:16:52
https://codeforces.com/contest/538/problem/C
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
long long n, m, sol, D[1000000], A[1000000];
 
int main(){
 
    scanf ("%I64d  %I64d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%I64d  %I64d", &D[i], &A[i]);
         sol = max (sol, A[i]);
    }
    
    for (int i = 1; i <= m-1; i++){
         long long d = abs(D[i+1]-D[i])-abs(A[i]-A[i+1]);
         if (d < 0){
             printf ("IMPOSSIBLE\n");
             return 0;
         }
 
         sol = max (sol, A[i]+(d)/2);
         sol = max (sol, A[i+1]+(d)/2);
         //cout << d/2<<" ";
    }
 
    sol = max (sol, A[m]+(n-D[m]));
    sol = max (sol, A[1]+abs(D[1]-1));
 
    printf ("%I64d \n", sol);
 
    return 0;
}