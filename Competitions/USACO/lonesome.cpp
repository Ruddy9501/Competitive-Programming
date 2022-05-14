/*
Ruddy Guerrero Alvarez
Villa Clara - Caibarien
El Gran Baile/bigdance/USACO 2009-2010/diciembre/bronce
Muy facil^n
*/
#include <cstdio>
#include <algorithm>
#define RAN 600

using namespace std;

int n, s1, s, M;

struct dos{
       int x, y;
}A[RAN];

int main(){

    freopen ("lonesome.in", "r", stdin);
    freopen ("lonesome.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d%d", &A[i].x, &A[i].y);
    }

    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++){
             if (M < abs(A[i].x - A[j].x) + abs(A[i].y - A[j].y)){
                 M = abs(A[i].x - A[j].x) + abs(A[i].y - A[j].y);
                 s = i;
                 s1 = j;
             }
         }
    }

    printf ("%d %d", s, s1);
    return 0;
}
