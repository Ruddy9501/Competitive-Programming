/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2003\dec03
Rain cover\cover
*/
#include <cstdio>
#include <algorithm>

#define RAN 25010
using namespace std;

struct par{
       int v, id;
       bool operator <(const par &R)
       const{
             return R.v > v;
       }
};

int n, sol, i, a, b, f, p, M[RAN];
par I[RAN], F[RAN];

int main(){

    freopen ("cover.in", "r", stdin);
    freopen ("cover.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         I[i] = par{a, i};
         F[i] = par{b, i};
    }

    sort (I + 1, I + n + 1);
    sort (F + 1, F + n + 1);

    i = 1;
    f = 1;
    while (i <= n || f <= n){
           if (I[i].v > F[f].v || i > n){
               sol = max (sol, f-M[F[f].id]);
               f++;
           }
           else{
               M[I[i].id] = i;
               i++;
           }
    }

    printf ("%d\n", sol);

    return 0;
}
