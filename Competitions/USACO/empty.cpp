/*
USACO/2013-2014/oro/noviembre
*/
#include <cstdio>
#include <algorithm>

#define RAN 3000000
using namespace std;

int n, m, x, y, can, A[RAN];
long long a, b;

int main(){

    freopen ("empty.in", "r", stdin);
    freopen ("empty.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d %lld %lld", &x, &y, &a, &b);
         for (int j = 1; j <= y; j++)
              A[(j*a+b)%n] +=  x;
    }

    for (int i = 0; i < n; i++){
         can += A[i];
         if (can > 0)
             can--;
    }

    for (int i = 0; i < n; i++){
         can += A[i];
         if (can == 0){
             printf ("%d\n", i);
             break;
         }
         can--;
    }

    return 0;
}
