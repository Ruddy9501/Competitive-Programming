/*
Ruddy Guerrero Alvarez
12grado
Villa Clara -> Caibarien
USACO/2007-2008/noviembre/PLATA
Vallas Vacunas/hurdles
*/
#include <cstdio>
#include <algorithm>
#define MAX 1 << 29
using namespace std;

int nd, nc, np, nod, newn, cos, M[400][400];

int main(){

    freopen ("hurdles.in", "r", stdin);
    freopen ("hurdles.out", "w", stdout);

    scanf ("%d %d %d\n", &nd, &nc, &np);

    for (int i = 1; i <= nd; i++)
         fill (M[i] + 1, M[i] + nd + 1, MAX);

    for (int i = 1;i <= nc; i++){
         scanf ("%d %d %d", &nod, &newn, &cos);
         M[nod][newn] = cos;
    }

    for (int k = 1; k <= nd; k++){
         for (int i = 1; i <= nd; i++){
              if (M[i][k] == MAX)
                  continue;
              for (int j = 1; j <= nd; j++){
                   if (M[k][j] == MAX)
                       continue;
                   if (M[i][j] > max(M[i][k], M[k][j]))
                       M[i][j] = max(M[i][k], M[k][j]);
              }
         }
    }

    for (int i = 1; i <= np; i++){
         scanf ("%d %d", &nod, &newn);
         if (M[nod][newn] == MAX)
             printf ("-1\n");
          else
             printf ("%d\n", M[nod][newn]);
    }

    return 0;
}
