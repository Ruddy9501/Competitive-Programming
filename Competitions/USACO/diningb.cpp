/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/feb08/bronze
Vacas Cenadoras/diningb
Ad-Hod
*/
#include <cstdio>
#include <algorithm>

#define RAN 30010
using namespace std;

int n, A[RAN], s = RAN, U[RAN], D[RAN];

int main(){

    freopen ("diningb.in", "r", stdin);
    freopen ("diningb.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    for (int i = 1; i <= n; i++){
         D[i] = D[i-1];
         U[n-i+1] = U[n-i+2];
         if (A[i] == 2)
             D[i]++;
         if (A[n-i+1] == 1)
             U[n-i+1]++;
    }

    for (int i = 0; i <= n; i++)
         s = min (s, D[i]+U[i+1]);

    printf ("%d\n", s);

    return 0;
}
