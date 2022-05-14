/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Noviembre/Problems/Bronze
Pinball Vacuno/pachinko
Tabla Acomulativa
*/
#include <cstdio>
#include <algorithm>

#define RAN 30
using namespace std;

int n, sol, a, S[RAN][RAN];

int main(){

    freopen ("pachinko.in", "r", stdin);
    freopen ("pachinko.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= i; j++){
              scanf ("%d\n", &a);
              S[i][j] = max(S[i-1][j-1], S[i-1][j])+a;
              sol = max (sol, S[i][j]);
         }


    printf ("%d\n", sol);

    return 0;
}
