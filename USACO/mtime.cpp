/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/noviembre/plata
Manejo de tiempo/mtime
DINAMICA
*/
#include <cstdio>
#include <algorithm>

#define RAN 1005
using namespace std;

int n, r, sol;

struct tri{
       int d, f;
       bool operator <(const tri &R)
       const{
            if (R.f != f)
                return R.f > f;
            return R.d < d;
       }
}A[RAN];

int main(){

    freopen ("mtime.in", "r", stdin);
    freopen ("mtime.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d %d", &A[i].d, &A[i].f);

    sort (A + 1, A + n + 1);

    int P = A[n].f;
    for (int i = n; i >= 1; i--){
          if (P > A[i].f)
              P = (A[i].f-A[i].d);
           else
              P -= A[i].d;
    }

    if (P >= 0)
        printf ("%d\n", P);
     else
        printf ("-1\n");
    return 0;
}
