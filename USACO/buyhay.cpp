/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/noviembre/plata
Comprando Heno/buyhay
MOCHILA CON REPETICION
*/
#include <cstdio>
#include <algorithm>

#define RAN 50005
using namespace std;

int n, T, a, b, sol = 1 << 30, C[2*RAN];
bool M[2*RAN];

int main(){

    freopen ("buyhay.in", "r", stdin);
    freopen ("buyhay.out", "w", stdout);

    scanf ("%d %d", &n, &T);
    M[0] = true;
    fill (C + 1, C + 2*RAN + 1, 1 << 30);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         for (int j = 0; j <= T; j++){
              if (M[j] == true && C[j] + b < C[j+a]){
                  M[j+a] = true;
                  C[j+a] = C[j] + b;
                  if (j+a >= T)
                      sol = min (sol, C[j+a]);
              }
         }
    }

    printf ("%d\n", sol);

    return 0;
}
