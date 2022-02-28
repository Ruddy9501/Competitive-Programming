/*
VC1 -> Ruddy Guerrero Alvarez
Provincial - 2012-2013
IPVCE "Ernesto Guevara"
12mo
*/
#include <cstdio>

using namespace std;

long long tot, n, r;

int main(){

    freopen ("BSUM.in", "r", stdin);
    freopen ("BSUM.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         r = i;
         while (r >= 1){
                if (r % 2 == 1)
                    tot++;
                r /= 2;
         }
    }
    printf ("%lld", tot);

    return 0;
}
