/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2006\nov06\02 Silver
Mal dia de pelos\badhair
MUY facil
Dinamica
*/
#include <cstdio>

#define RAN 80010
using namespace std;

long long n, c, s,  A[RAN], M[RAN], C[RAN];
long long sol;
int main(){

    freopen ("badhair.in", "r", stdin);
    freopen ("badhair.out", "w", stdout);

    scanf ("%lld", &n);

    for (int i = 1; i <= n; i++)
         scanf ("%lld", &A[i]);

    for (int i = n; i >= 1; i--){
         s = 0;
         while (M[c] < A[i] && c != 0){
                s += C[c];
                c--;
         }
         M[++c] = A[i];
         C[c] = s+1;
         sol += s;
    }

    printf ("%lld\n", sol);

    return 0;
}
