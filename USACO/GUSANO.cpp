/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
PSN 2012\ 2da Prueba Final\
Gusanillo\ gusano\ Brute Forse 
*/
#include <cstdio>
#include <algorithm>

using namespace std;

long long a, n, d, p, mcd, c;

long long mcm (long long a, long long b){
         if (a % b != 0)
             mcm (b, a % b);
          else
             c = b;
             
}

int main(){

    freopen ("GUSANO.in","r",stdin);
    freopen ("GUSANO.out","w",stdout);

    scanf ("%I64d %I64d %I64d", &n, &d, &p);

    c = mcm (d, p);

    mcd = (d * p) / c;

    printf ("%I64d", (n / mcd) + 1);
    return 0;
}
