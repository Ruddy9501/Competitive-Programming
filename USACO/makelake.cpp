/*
Ruddy Guierrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/mar08/bronze
Haciendo un Lago/makelake
*/
#include <cstdio>
#include <algorithm>

#define RAN 110
using namespace std;

int nf, nc, T, n, a, b, c, s, m, A[RAN][RAN];

int main(){

    freopen ("makelake.in", "r", stdin);
    freopen ("makelake.out", "w", stdout);

    scanf ("%d %d %d %d", &nf, &nc, &T, &n);
    for (int i = 1; i <= nf; i++)
         for (int j= 1; j <= nc; j++)
              scanf ("%d", &A[i][j]);

    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d", &a, &b, &c);
         m = 0;
         for (int j = a; j <= a+2; j++)
              for (int k = b; k <= b+2; k++)
                   m = max (m, A[j][k]);
         for (int j = a; j <= a+2; j++)
              for (int k = b; k <= b+2; k++)
                   A[j][k] = min(m - c, A[j][k]);
    }

    for (int i = 1; i <= nf; i++)
         for (int j = 1; j <= nc; j++)
              s += max (0, T-A[i][j]);

    printf ("%d\n", s*72*72);

    return 0;
}
