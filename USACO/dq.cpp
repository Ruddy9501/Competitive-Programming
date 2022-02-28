/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/marzo/bronce
Reina Lechera/dq
countinchange -> un poco tonto 
*/
#include <cstdio>

#define RAN 305
using namespace std;

int n, m, a, S[RAN];

int main(){

    freopen ("dq.in", "r", stdin);
    freopen ("dq.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    S[0] = 1;
    for (int i = 1; i <= m; i++){
         scanf ("%d", &a);
         for (int j = 0; j <= n-a; j++)
              S[j+a] += S[j];
    }

    printf ("%d\n", S[n]);

    return 0;
}
