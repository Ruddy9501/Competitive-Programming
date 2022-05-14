/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Marzo/Problems/Bronze
Picas y Fijas/mmind
Brute Forse
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

#define RAN 110
using namespace std;

int n, N[RAN], B[RAN], B1[RAN], b, b1, c;
char  A[4], A1[4];
bool M[4];

int main(){

    freopen ("mmind.in", "r", stdin);
    freopen ("mmind.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d %d %d", &N[i], &B[i], &B1[i]);

    for (int i = 1000; i <= 9999; i++){
         sprintf ( A, "%d", i);

         for (c = 1; c <= n; c++){

              sprintf ( A1, "%d", N[c]);

              fill (M, M + 4, 0);
              b1 = b = 0;

              for (int j = 0; j < 4; j++)
                   if (A[j] == A1[j])
                       b++, M[j] = 1;

              for (int j = 0; j < 4; j++){
                   if (!M[j])
                   for (int k = 0; k <= 4; k++){
                        if (!M[k] && A[j] == A1[k]){
                            b1++, M[k] = 1;
                            break;
                        }
                   }
              }

              if (b1 != B1[c] || b != B[c] || c == n)
                  break;
         }

         if (c == n && b1 == B1[c] && b == B[c]){
             printf ("%d\n", i);
             return 0;
         }

    }

    printf ("NONE\n");

    return 0;
}
