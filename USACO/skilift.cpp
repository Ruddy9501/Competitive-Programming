/*
Ruddy Guerrero Alvarez
12mo
Villa Clara
IPVCE:Ernesto Guevara
DIA 7
USACO/2006/marzo/oro
Ascensor para Esquí/skilift
Programacion dinamica + AD-HOD
*/
#include <cstdio>
#include <algorithm>

#define RAN 5005
using namespace std;

long long n, m, u, C[RAN], A[RAN];

int main(){

    freopen ("skilift.in", "r", stdin);
    freopen ("skilift.out", "w", stdout);

    scanf ("%lld %lld\n", &n, &m);

    for (int i = 1; i <= n; i++)
         scanf ("%lld\n", &A[i]);

    C[1] = 1;
    fill (C + 2, C + n + 1, 1 << 30);
    for (int i = 2; i <= n; i++){
         u = 0;
         for (int j = 1; j <= m && j < i; j++){
              if (u * (A[i] - A[i-j]) <= j * (A[i] - A[i-u])){
                  u = j;
                  C[i] = min (C[i-j] + 1, C[i]);
              }
         }
    }

    printf ("%lld\n", C[n]);

    return 0;
}
