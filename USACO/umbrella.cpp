/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Paraguas para Vacas/umbrella
USACO/Problems/2011-12/December/Problems/Silver

*/
#include <cstdio>
#include <algorithm>

#define RAN 100010
#define RAM 5010
using namespace std;

int A[RAM], S[RAN], s[RAM], n, T;

int main(){

    freopen ("umbrella.in", "r", stdin);
    freopen ("umbrella.out", "w", stdout);

    scanf ("%d %d", &n, &T);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
    }

    for (int i = 1; i <= T; i++){
         scanf ("%d", &S[i]);
    }

     for (int i = T-1; i >= 1; i--)
          S[i] = min (S[i], S[i+1]);

    sort (A + 1, A + n + 1);
    n++;
    fill (s + 2, s + n + 1, (1<<30));

    for (int i = 2; i <= n; i++)
         for (int j = 1; j < i; j++){
              s[i] = min (s[i], s[j] + S[A[i-1]-A[j]+1]);
         }

    printf ("%d\n", s[n]);

    return 0;
}
