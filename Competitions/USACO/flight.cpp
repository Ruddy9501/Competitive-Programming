/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
12mo
USACO/2005/octubre/oro
Volando Correctamente/flight
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, K, may, sol, sum;
int C[20009];

struct tri{
       int cos, ini, fin;
}A[50005];

struct comp{
       bool operator ()(const tri &R, const tri &S)
       const {
              if (R.fin != S.fin)
                  return R.fin < S.fin;
              return R.ini < S.ini;
       }
};

int main(){

    freopen ("flight.in", "r", stdin);
    freopen ("flight.out", "w", stdout);

    scanf ("%d %d %d\n", &n, &m, &K);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d\n", &A[i].ini, &A[i].fin, &A[i].cos);
         if (A[i].ini > A[i].fin){
             A[i].ini = 2 * m - A[i].ini;
             A[i].fin = 2 * m - A[i].fin;
         }
    }

    sort (A + 1, A + n + 1, comp());
    for (int i = 1; i <= n; i++){
         may = 0;
         for (int j = A[i].ini; j < A[i].fin && may != K; j++)
              if (C[j] > may)
                  may = C[j];
         sum = min (K - may, A[i].cos);
         for (int j = A[i].ini; j < A[i].fin && sum != 0; j++)
              C[j] += sum;
         sol += sum;
    }

    printf ("%d\n", sol);

    return 0;
}
