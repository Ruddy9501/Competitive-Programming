/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2013/marzo/bronce
Proximidad de Razas/proximity
AD-HOD 
*/
#include <cstdio>
#include <algorithm>

#define RAN 1000005
using namespace std;

int n, m, sol, a, P[RAN];
bool M[RAN];

int main(){

    freopen ("proximity.in", "r", stdin);
    freopen ("proximity.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         if (i - P[a] <= m && M[a] == true)
             if (a > sol)
                 sol = a;
         P[a] = i;
         M[a] = true;
    }

    printf ("%d\n", sol);

    return 0;
}
