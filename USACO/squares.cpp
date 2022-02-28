/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
/USACO/Problems/2007/oct07/bronze
Cuadrados Perfectos/squares
Brute Forse
*/
#include <cstdio>

using namespace std;

int n, s;

int main(){

    //freopen ("squares.in", "r", stdin);
   // freopen ("squares.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= 500; i++)
         for (int j = i+1; j <= 500; j++)
              if (i*i+n == j*j)
                  s++;

    printf ("%d\n", s);

    return 0;
}
