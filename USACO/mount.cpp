/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
USACO/Problems/2009-10/Abril/Problems/Bronze
Observando Montañas/mount
Dinamica
*/
#include <cstdio>

using namespace std;

int n, a, b, ini = 1, sol, ii;
bool m;

int main(){

    freopen ("mount.in", "r", stdin);
    freopen ("mount.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         if (a < b)
             m = 1, ii = i;

         if (a > b && m == 1)
             ini = ii, m = 0;

         if (sol < i-ini+1)
             sol = i-ini+1;

         b = a;
    }

    printf ("%d\n", sol);

    return 0;
}
