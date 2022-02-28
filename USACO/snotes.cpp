/*
Ruddy Guerrero Alvarez
Villa Clara - Caibarien
El Gran Baile/bigdance/USACO 2009-2010/diciembre/bronce
Muy facil = es mierda
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int a, n, m, con;
int A[2000000];

int main(){

    freopen ("snotes.in", "r", stdin);
    freopen ("snotes.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         for (int j = con; j <= con+a; j++)
              A[j] = i;
         con += a;
    }

    for (int i = 1; i <= m; i++){
         scanf ("%d", &a);
         printf ("%d\n", A[a]);
    }

    return 0;
}
