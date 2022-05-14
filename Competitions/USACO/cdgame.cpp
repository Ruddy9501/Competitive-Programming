/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/plata
Juego de Dígitos Vacuno/cdgame
AD-HOD
*/
#include <cstdio>
#include <algorithm>

#define RAN 1000005
using namespace std;

int n, a, may, men;
bool M[RAN];

int main(){

    freopen ("cdgame.in", "r", stdin);
    freopen ("cdgame.out", "w", stdout);

    M[0] = false;
    for (int i = 1; i <= RAN; i++){
         men = 10;
         may = 0;
         for (int j = i; j > 0; j /= 10)
              if (j % 10 != 0){
                  men = min (men, j % 10);
                  may = max (may, j % 10);
              }
              if (!M[i-men] || !M[i-may])
                  M[i]= true;
    }

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         if (M[a] == true)
             printf ("YES\n");
          else
             printf ("NO\n");
    }

    return 0;
}
