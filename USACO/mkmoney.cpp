/*
Ruddy Guerrero Alvarez
VILLA CLARA -> Caibarien
USACO/Problems/2010-11/October/Problems/Gold
Haciendo Dinero/mkmoney
MOCHILA CON REPETICION
los rangos de este ejercicio estan mal
n = 100 no 1000 muy facil
*/
#include <cstdio>
#include <algorithm>

#define RAN 100010
using namespace std;

int n, m, a, b, S[RAN];


int main(){

    freopen ("mkmoney.in", "r", stdin);
    freopen ("mkmoney.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         for (int j = a; j <= m; j++)
              S[j] = max (S[j], max(S[j-a],j-a) + b-a);
    }

    printf ("%d\n", S[m]);

    return 0;
}
