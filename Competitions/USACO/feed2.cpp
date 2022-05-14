/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
/USACO/Problems/2009-10/Enero/Problems/Silver
Comprando Comida/feed2
dinamica
*/
#include <cstdio>
#include <algorithm>

#define RAN 105
using namespace std;

int t, n, m, a, b, c, sol;

struct par{
       int cos, can;
       bool operator <(const par &R)
       const {
             return R.cos > cos;
       }
}A[RAN];

int main(){

    freopen ("feed2.in", "r", stdin);
    freopen ("feed2.out", "w", stdout);

    scanf ("%d %d %d", &t, &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d %d", &a, &b, &c);
         A[i].cos = (n - a) + c;
         A[i].can = b;
    }

    sort (A + 1, A + m + 1);

    for (int i = 1; i <= m; i++){
         a = min (t, A[i].can);
         t -= a;
         sol += a * A[i].cos;
    }

    printf ("%d\n", sol);

    return 0;
}
