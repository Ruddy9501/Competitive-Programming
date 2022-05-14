/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Marzo/Problems/Bronze
Necesidad de Velocidad/boost
convinatoria
*/
#include <cstdio>

using namespace std;

int f, m, n, s, F[21], M[21];
double m1, f1, t, may;

int main(){

    freopen ("boost.in", "r", stdin);
    freopen ("boost.out", "w", stdout);

    scanf ("%d %d %d", &f, &m, &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d %d", &F[i], &M[i]);

    may = (double)f/(double)m;
    for (int i = 1; i < (1 << n); i++){
         m1 = m, f1 = f;
         for (int j = 0; j < n; j++)
              if (i & (1 << j))
                  m1 += M[j+1], f1 += F[j+1];
         t = f1 / m1;
         if (t > may)
             may = t, s = i;
    }
    if (s == 0)
        printf ("NONE\n");
     else
        for (int i = 0; i < n; i++)
             if (s & (1 << i))
                 printf ("%d\n", i+1);

    return 0;
}
