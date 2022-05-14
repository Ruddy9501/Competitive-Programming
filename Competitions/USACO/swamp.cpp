/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
EXPLORA #3 PSN 2013
Cosas del Pantano/swamp
*/
#include <cstdio>
#include <algorithm>

#define RAN 1010
using namespace std;

int con, s, n, a, x, y, d, c;

struct par{
       int x, y;
       bool operator < (const par &R)
       const{
            if (x != R.x)
                return R.x < x;
            return R.y < y;
       }
}A[RAN], C[RAN];

int gcd (int a, int b){
    while (a){
           swap (a, b);
           a %= b;
    }
    return b;
}

int main(){

    freopen ("swamp.in", "r", stdin);
    freopen ("swamp.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &x, &y);
         A[i] = (par){x, y};
    }

    for (int i = 1; i <= n; i++){
         c = 0;
         for (int j = i+1; j <= n; j++){
              x = A[i].x-A[j].x;
              y = A[i].y-A[j].y;
              d = gcd (x, y);
              C[++c].x = x / d;
              C[c].y = y / d;
         }
         sort (C + 1, C + c + 1);
         con = 2;
         for (int j = 2; j <= c; j++){
              if (C[j].x == C[j-1].x && C[j].y == C[j-1].y)
                  con++;
               else
                  con = 2;
              s = max (s, con);
         }
    }

    if (s < 4)
        s = 0;
    printf ("%d\n", s);

    return 0;
}
