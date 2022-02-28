/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
/USACO/Problems/2009-10/Febrero/Problems/Bronze
Desenterrando Tesoros/scavhunt
Bruete Forse
*/
#include <cstdio>

#define RAN 6000
using namespace std;

int a, b, n, m, A[RAN], B[RAN];

int main(){

    freopen ("scavhunt.in", "r", stdin);
    freopen ("scavhunt.out", "w", stdout);

    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; i++){
         if (n%i == 0)
             A[++a] = i;
    }

    for (int i = 1; i <= m; i++){
         if (m%i == 0)
             B[++b] = i;
    }

    for (int i = 1; i <= a; i++)
         for (int j = 1; j <= b; j++)
              printf ("%d %d\n", A[i], B[j]);

    return 0;
}
