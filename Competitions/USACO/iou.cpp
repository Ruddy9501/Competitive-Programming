/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/marzo/bronce
Devolver/iou
dinamico -> un poco tonto 
*/
#include <cstdio>
#include <algorithm>

#define RAN 100005
using namespace std;

int n, p, d, b, pos, s, A[RAN];

int main(){

    freopen ("iou.in", "r", stdin);
    freopen ("iou.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    while (p != n){
           s++;
           p++;
           if (A[p] < 0){
               d += (A[p]*-1);
               if (pos == 0)
                   pos = p;
           }
            else
               b += A[p];
           if (d <= b){
               if (pos != 0){
                   s += (2*(p - pos));
                   pos = 0;
               }
               b -= d;
               d = 0;
           }
    }

    printf ("%d", s);

    return 0;
}
