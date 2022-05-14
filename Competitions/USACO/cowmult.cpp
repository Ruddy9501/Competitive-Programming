/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/feb08/bronze
Multiplicación Vacuna/cowmult
Ad-Hod
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int la, lb;
char A[12], B[12];
long long a, b, s;

int main(){

    freopen ("cowmult.in", "r", stdin);
    freopen ("cowmult.out", "w", stdout);

    scanf ("%lld %lld", &a, &b);

    sprintf (A , "%d", a);
    sprintf (B , "%d", b);

    la = strlen (A);
    lb = strlen (B);

    for (int i = 0; i < la; i++)
         for (int j = 0; j < lb; j++)
              s += ((A[i]-48)*(B[j]-48));

    printf ("%d\n", s);

    return 0;
}
