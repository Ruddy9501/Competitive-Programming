/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/marzo/plata
Cruce de Río/river
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, tot, C[2506];

int main(){

    freopen ("river.in", "r", stdin);
    freopen ("river.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    scanf ("%d", &a);
    C[1] = a + 2*m;
    tot += a;
    for (int i = 2; i <= n; i++){
         scanf ("%d", &a);
         tot += a;
         C[i] = tot + 2*m;
         for (int k = 1; k <= i/2; k++){
              if (C[i] > C[i-k] + C[k]){
                  C[i] = C[k] + C[i-k];
              }
          }
    }

    printf ("%d\n",C[n]-m);

    return 0;
}
