/*
Rudy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007-08/Enero/Task/silver
Construyendo Caminos/cowrun
*/
#include <cstdio>

#define RAN 10010
using namespace std;

int n, m, s, p, A[RAN], sum[RAN];

int main(){

    freopen ("cowrun.in", "r", stdin);
    freopen ("cowrun.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
         scanf ("%d", &A[i]);

    for (int i = 0; i < n; i++){

         if (sum[i] > sum[i+1])sum[i+1] = sum[i];

         p = i, s = sum[i];
         for (int j = 0; j < m && p < n; j++){
              p += 2;
              s += A[i+j];

              if (sum[p] < s)sum[p] = s;

         }
    }

    printf ("%d\n", sum[n]);

    return 0;
}
