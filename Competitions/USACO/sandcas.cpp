/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien
USACO\2008\marzo\Plata
Castillo de Arena\sandcas
Ad-hoc
*/
#include <cstdio>
#include <algorithm>

#define RAN 100010

using namespace std;

int n, x, y, sol;
int A[RAN], B[RAN];

main (){
     
     freopen ("sandcas.in", "r", stdin);
     freopen ("sandcas.out", "w",stdout);
     
     scanf ("%d %d %d\n", &n, &x, &y);
     
     for (int i = 1; i <= n; i++)
          scanf ("%d %d", &A[i], &B[i]);
          
     sort (A + 1, A + n + 1);
     sort (B + 1, B + n + 1);
     
     for (int i = 1; i <= n; i++){
          if (A[i] > B[i])
              sol += (A[i] - B[i]) * y;
           else
              sol += (B[i] - A[i]) * x;  
     }
     
     printf ("%d\n", sol);
}
