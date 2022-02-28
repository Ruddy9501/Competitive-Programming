/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
PSN 2012\ 2da Prueba Final\ 
El leñador Pablo\ Madera\ Ad-hoc  
*/
#include <cstdio>
#include <algorithm>
#define RAN 10000100

using namespace std;

long long can, tot, n, m, A[RAN];

int main(){

    freopen ("MADERA.in","r",stdin);
    freopen ("MADERA.out","w",stdout);

    scanf ("%I64d %I64d\n", &n, &m);

    for (int i = 1; i <= n; i++){
         scanf ("%I64d", &A[i]);
    }

    sort (A + 1, A + n + 1);

    tot = A[n] - m;
    can = 1;
    n--;
    while (tot / can < A[n]){
           tot += A[n];
           can++;
           n--;
    }

    printf ("%I64d\n",tot / can);

    return 0;
}
