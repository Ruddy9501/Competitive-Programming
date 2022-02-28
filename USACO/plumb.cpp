/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/marzo/bronce
Entubando el Estanque/plumb
BFS -> TONTO
*/
#include <cstdio>

#define RAN 55
using namespace std;
const int mf[8] = { 0, 0, 1, 1, 1,-1,-1,-1},
          mc[8] = {-1, 1,-1, 1, 0,-1, 1, 0};

int nf, nc, sol, A[RAN][RAN];

int main(){

    freopen ("plumb.in", "r", stdin);
    freopen ("plumb.out", "w", stdout);

    scanf ("%d %d", &nf, &nc);
    for (int i = 1; i <= nf; i++)
         for (int j = 1; j <= nc; j++)
              scanf ("%d", &A[i][j]);

   for (int i = 1; i <= nf; i++)
        for (int j = 1; j <= nc; j++)
             if (sol < A[i][j]){
                 for (int k = 0; k < 8; k++){
                      if (i+mf[k] > nf || i+mf[k] < 1 || j+mc[k] > nc || j+mc[k] < 1)
                          continue;
                      if (A[i+mf[k]][j+mc[k]] == A[i][j])
                          sol = A[i][j];
                 }
             }

    printf ("%d\n", sol);

    return 0;
}
