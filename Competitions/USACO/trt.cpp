/*
Ruddy Guerrero Alvarez
12mo
USACO/2006/febrero/oro
Chocolates  para las vacas/trt
*/
#include <cstdio>
#include <algorithm>

#define RAN 2005
using namespace std;

int n, sol, A[RAN], T[RAN][RAN];

int main(){

    freopen ("trt.in", "r", stdin);
    freopen ("trt.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    for (int i = 1; i <= n; i++){
         T[i][0] = T[i-1][0] + (A[i] * i);
         T[0][i] = T[0][i-1] + (A[n-i+1]*i);
    }

    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n-i; j++){
              T[i][j] = max((T[i-1][j] + A[i]*(i+j)),
                           (T[i][j-1] + A[n-j+1]*(i+j)));
         }
    }

    for (int i = 0; i <= n; i++)
         sol = max(T[i][n-i], sol);

    printf ("%d\n", sol);

    return 0;
}
