/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007/mar07/mar07_bronze
Espectáculo Pirotécnico/fireshow
Brute Forse 
*/
#include <cstdio>

#define RANM 2000010
#define RANN 110
using namespace std;

int n, s, T, A[RANN];
bool M1[RANM], M[RANN];

int main(){

    freopen ("fireshow.in", "r", stdin);
    freopen ("fireshow.out", "w", stdout);

    scanf ("%d %d", &n, &T);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         for (int j = 1; j <= i-1; j++)
              if (A[i] % A[j] == 0)
                  M[i] = 1;
               else
                  if (A[j] % A[i] == 0)
                      M[j] = 1;
    }

    for (int i = 1; i <= n; i++){
         if (M[i])continue;
         for (int j = A[i]; j <= T; j += A[i])
              if (!M1[j]){
                  M1[j] = 1;
                  s++;
              }
    }

    printf ("%d\n", s);

    return 0;
}
