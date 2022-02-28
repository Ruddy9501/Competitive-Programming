/*
Ruddy Guerrero ALvarez
Villa Clara -- CAibarien
USACO\2008\diciembre\plata
Heno para la Venta\hay4sale
SE va el ultimo jd por tiempo
*/
#include <cstdio>
#include <algorithm>

#define RAN 50005

using namespace std;

int T, n, m, c, can, sol, ca;
int A[RAN];
bool M[RAN];

main (){
      
      freopen ("hay4sale.in", "r", stdin);
      freopen ("hay4sale.out", "w", stdout);
      
      scanf ("%d %d\n", &T, &n);
      
      for (int i = 1; i <= n; i++){ca++;
           scanf ("%d", &m);
           for (int j = 0; j <= can; j++){ca++;
                if (A[j] + m <= T && M[A[j] + m] != true){
                    A[++c] = A[j] + m;
                    M[A[j] + m] = true; 
                    if (sol < A[c])
                        sol = A[c];
                }
                can = c;
           }
      }
      
      printf ("%d\n", sol);     
}
