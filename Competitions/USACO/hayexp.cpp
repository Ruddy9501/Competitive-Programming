/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/diciembre/bronce
Gastos de Heno/hayexp
Tabla acomulativa -> tonta
*/
#include <cstdio>
#include <algorithm>

#define RAN 505
using namespace std;

int A[RAN], a, b, n, m;

int main()
{
    freopen ("hayexp.in", "r", stdin);
    freopen ("hayexp.out", "w", stdout);

    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
         scanf ("%d", &a), A[i] = A[i-1] + a;

    for (int i = 1; i <= m; i++)
         scanf ("%d %d", &a, &b), printf ("%d\n", A[b]-A[a-1]);

    return 0;
}
