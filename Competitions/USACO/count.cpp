/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007/open07/bronze
Conteo de Vacas/count
Brute Forse
*/
#include <cstdio>

using namespace std;

int n ,a, b, i;

bool bus_dig(int n){
     for ( ; n; n/=10)
         if (n%10 == a)
             return 0;
     return 1;
}

int main(){

    freopen ("count.in", "r", stdin);
    freopen ("count.out", "w", stdout);

    scanf ("%d %d", &b, &a);
    for (i = 1; b ; i++){
         if (bus_dig(i)){
             b--;
         }
    }

    printf ("%d\n", --i);

    return 0;
}
