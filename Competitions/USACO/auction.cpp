/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/noviembre/bronce
¡Yendo Una vez, Yendo Dos veces, Yendo!/auction
AD-HOD
*/
#include <cstdio>
#include <algorithm>

#define RAN 1005
using namespace std;

int n, s, m, sol, A[RAN];

int main(){

    freopen ("auction.in", "r", stdin);
    freopen ("auction.out", "w", stdout);

    scanf ("%d %d", &n, &m );
    for (int i = 1; i <= m; i++)
         scanf ("%d", &A[i]);

    sort (A + 1, A + m + 1);

    for (int i = 1; i <= m; i++)
         if (A[i]*min(m-i+1, n) > sol){
             sol = A[i]*min(m-i+1, n);
             s = A[i];
         }

    printf ("%d %d\n", s, sol);

    return 0;
}
