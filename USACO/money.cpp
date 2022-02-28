/*
Ruddy Guerrero Alvarez
12mo
USACO/2007-2008/octubre/oro/
cunting changes
*/

#include <cstdio>

using namespace std;

int n, m, a;
int A[10005];

int main (){

    freopen ("money.in", "r", stdin);
    freopen ("money.out", "w", stdout);

    A[0] = 1;
    scanf ("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d\n", &a);
         for (int j = 0; j <= m-a; j++)
              A[j+a] += A[j];
    }

    printf ("%d\n", A[m]);

    return 0;
    }
