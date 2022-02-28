/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Noviembre/Problems/Bronze
Vacas Claustrofóbicas/claust
Brute Forse
*/
#include <cstdio>

#define RAN 2010
using namespace std;

int s1, s2, n;
long long sol = 9999999999999999, d;

struct par{
       long long x, y;
}A[RAN];

long long dis(int x, int y){
          return ((A[x].x-A[y].x)*(A[x].x-A[y].x)+
                 (A[x].y-A[y].y)*(A[x].y-A[y].y));
}

int main(){

    freopen ("claust.in", "r", stdin);
    freopen ("claust.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &A[i].x, &A[i].y);
         for (int j = i-1; j >= 1; j--){
              d = dis (i, j);
              if (d < sol){
                  sol = d;
                  s1 = j;
                  s2 = i;
              }
         }
    }

    printf ("%d %d", s1, s2);

    return 0;
}
