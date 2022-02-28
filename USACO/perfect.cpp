/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/marzo/bronce
La Vaca Perfecta/perfect
AD - HOD
*/
#include <cstdio>
#include <algorithm>

#define RAN 105
using namespace std;

int n, A[RAN], S[RAN];

int main(){

    freopen ("perfect.in", "r", stdin);
    freopen ("perfect.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++)
              scanf ("%d", &A[j]);
         sort (A + 1, A + n + 1);
         S[i] = A[n/2+1];
    }

    sort (S + 1, S + n + 1);
    printf ("%d\n", S[n/2+1]);

    return 0;
}
