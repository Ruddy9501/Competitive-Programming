/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2013/marzo/bronce
Carrera Vacuna/cowrace
acomulando
*/
#include <cstdio>
#include <algorithm>

#define RAN 1000005
using namespace std;

int n, m, a, b, sol, ini, pa, pb, gan, A[RAN], B[RAN];

int main(){

    freopen ("cowrace.in", "r", stdin);
    freopen ("cowrace.out", "w", stdout);

    scanf ("%d %d", &n, &m);

    ini = 1;
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         for (int j = ini; j < ini+b; j++)
              A[j] = a;
         ini += b;
    }

    ini = 1;
    for (int i = 1; i <= m; i++){
         scanf ("%d %d", &a, &b);
         for (int j = ini; j < ini+b; j++)
              B[j] = a;
         ini += b;
    }

    for (int i = 1; i <= ini; i++){
         pa += A[i];
         pb += B[i];
         if (pa == pb)continue;
         if (gan == 0)
             if (pa > pb)
                 gan = 1;
              else
                 gan = 2;
         else
         if (pa > pb && gan == 2){
             gan = 1;
             sol++;
         }
          else
             if (pa < pb && gan == 1){
                 gan = 2;
                 sol++;
             }
    }

    printf ("%d\n", sol);

    return 0;
}
