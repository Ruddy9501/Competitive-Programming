/*
Ruddy Guierrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/mar08/bronze
Estadísticas/stats
*/
#include <cstdio>
#include <algorithm>

#define RAN 510
using namespace std;


int tot, n, A[RAN];

int main(){

    freopen ("stats.in", "r", stdin);
    freopen ("stats.out", "w", stdout);

    scanf ("%d", &n);

    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         tot += A[i];
    }

    sort (A + 1, A + n + 1);

    printf ("%.6lf\n%.6lf\n", ((double)tot/(double)n), ((double)(A[(n+1)/2]+A[(n+2)/2])/2));


    return 0;
}
