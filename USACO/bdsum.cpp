/*
Ruddy Guerrero Alvarez
12mo VC1
IPVCE Ernesto Guevara
Villa Clara -> Caibarien
USACO/2006/oro/febrero/
Sumas de Dígitos hacia atrás/bdsum
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int A[20], C[20][20], n, N, c, tot;

int main(){

    freopen ("bdsum.in", "r", stdin);
    freopen ("bdsum.out", "w", stdout);

    scanf ("%d %d", &n, &N);

    for (int i = 1; i <= n; i++)
         A[i] = i;

    C[1][1] = c =1;
    for (int i = 2; i <= n; i++){
         c++;
         for (int j = 1; j <= c; j++)
              C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    do {
           for (int i = 1; i <= n; i++)
                tot += (C[n][i]*A[i]);
           if (tot == N){
               printf ("%d", A[1]);
               for (int i = 2; i <= n; i++)
                    printf (" %d", A[i]);
               break;
           }
           tot = 0;
    }while (next_permutation(&A[1],&A[n+1]));


    return 0;
}
