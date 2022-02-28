/*
Ruddy Guerrero Alvarez
VILLA CLARA - CAIBARIEN
USACO/2008-2009/noviembre/oro
mazcara de bit
Vacas Mezcladas/mixup2
*/
#include <cstdio>
#include <algorithm>

#define RAN 17
using namespace std;

int n, m, A[RAN];
long long s, M[1<<RAN][RAN]; 

int main(){

    freopen ("mixup2.in", "r", stdin);
    freopen ("mixup2.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 0;  i < n; i++)
         scanf ("%d", &A[i]), M[1 << i][i] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
         for (int i = 0; i < n; i++)
              if ( mask & (1 << i) )
                  for (int j = 0; j < n; j++)
                       if ( !(mask&(1<<j)) && abs(A[i]-A[j]) > m)
                           M[mask|(1<<j)][j] += M[mask][i];

    for (int i = 0; i < n; i++)s += M[(1 << n)-1][i];

    printf ("%lld\n", s);

    return 0;
}
