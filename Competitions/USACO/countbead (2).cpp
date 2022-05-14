/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/10-Octubre/Problems/Bronce
Contando Canicas/countbead
Ad-Hod
*/
#include <cstdio>

using namespace std;

int a, b, s, n;

int main(){

    freopen ("countbead.in", "r", stdin);
    freopen ("countbead.out", "w", stdout);

    scanf ("%d %d", &n, &a);
    for (int i = 2; i <= n; i++){
         scanf ("%d\n", &b);
         if (a != b)
             s++;
         a = b;
    }

    printf ("%d\n", s);

    return 0;
}
