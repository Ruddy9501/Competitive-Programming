/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/enero/bronce
De Regreso al Establo/backbarn
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int a, n, m, ini, S[1000000];

int main(){

    freopen ("mnoteb.in", "r", stdin);
    freopen ("mnoteb.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         for (int j = ini; j < ini+a; j++)
              S[j] = i;
         ini+=a;
    }

    for (int i = 1; i <= m; i++){
         scanf ("%d", &a);
         printf ("%d\n", S[a]);
    }

    return 0;
}
