/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/febrero/plata
El duende/lepr
BRUTE FORCE
*/
#include <cstdio>
#include <algorithm>

#define RAN 405
using namespace std;

int n, d1, d2, s1, s2, sol = -(1 << 30), A[RAN][RAN];

int main(){

    freopen ("lepr.in", "r", stdin);
    freopen ("lepr.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
              scanf ("%d", &A[i][j]), A[i+n][j+n] = A[i][j+n] =  A[i+n][j] = A[i][j];

    for (int i = 1; i <= 2*n; i++)
         for (int j = 1; j <= 2*n; j++){
              d1 = d2 = s1 = s2 = 0;
              for (int k = 0; k < n; k++){
                   if (j - k <= 2*n && i + k <= 2*n){
                       d1 += A[i+k][j+k];
                       sol = max (sol, d1);
                   }
                   if (j - k > 0 && i + k <= 2*n){
                       d2 += A[i+k][j-k];
                       sol = max (sol, d2);
                   }
                   if (i + k <= 2*n){
                       s1 += A[i+k][j];
                       sol = max (sol, s1);
                   }
                   if (j + k <= 2*n){
                       s2 += A[i][k+j];
                       sol = max (sol, s2);
                   }
              }
         }

    printf ("%d\n", sol);

    return 0;
}
