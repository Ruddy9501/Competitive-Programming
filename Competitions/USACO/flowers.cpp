/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007/open07/bronze
Jardín de Flores/flowers
Brute Forse
*/
#include <cstdio>

#define RAN 10010
using namespace std;

int T, n, a, b, s;
bool M[RAN];

int main(){

    //freopen ("flowers.in", "r", stdin);
    //freopen ("flowers.out", "w", stdout);

    scanf ("%d %d", &T, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         for (int j = a; j <= T; j += b)
              M[j] = 1;
    }

    for (int i = 1; i <= T; i++)
         if (!M[i])
             s++;

    printf ("%d\n", s);

    return 0;
}
