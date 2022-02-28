/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/2007-2008/noviembre/plata
Mejor Línea de Vacas/bcl
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int fin, ini, f, i, n, c;
char A[50000], S[50000];

int main(){

    freopen ("bcl.in", "r", stdin);
    freopen ("bcl.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%c\n", &A[i]);

    fin = n;
    ini = 1;
    while(n > 0){
          n--;
          if (A[fin] > A[ini])
              S[++c] = A[ini], ini++;
           else
              if (A[fin] < A[ini])
                  S[++c] = A[fin], fin--;
               else{
                   i = ini;
                   f = fin;
                 while (A[i] == A[f] && f-i >= 1){
                        i++;
                        f--;
                 }
                 if (A[i] < A[f])
                     S[++c] = A[ini], ini++;
                  else
                     S[++c] = A[fin], fin--;
               }
    }
    int con = 0;
    for (int i = 1; i <= c; i++){
         if (con == 80){
             printf ("\n");
             con = 0;
         }
         printf ("%c", S[i]);
         con++;
    }
    printf ("\n");
    return 0;
}
