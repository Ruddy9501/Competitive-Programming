/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2007-08\Abril-Open\Data\Bronce
Yendo al Cine\cowflix
MOCHILA
*/
#include <cstdio>

#define RAN 1 << 17
using namespace std;

int T, n, c, a, c1, s, me = 1 << 30, A[RAN];

int main(){

    freopen ("cowflix.in", "r", stdin);
    freopen ("cowflix.out", "w", stdout);

    scanf ("%d %d", &T, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         c = c1;
         for (int j = 1 ; j <= c; j++){
              A[++c1] = A[j]+a;
              if (A[c1] <= T && T - A[c1] < me){
                  me = T - A[c1];
                  s = A[c1];
              }
         }
         A[++c1] = a;
         if (A[c1] <= T && T - A[c1] < me){
             me = T - A[c1];
             s = A[c1];
         }
    }

    printf ("%d\n", s);

    return 0;
}
