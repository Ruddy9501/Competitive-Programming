/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
12mo
USACO/2006/enero/plata
Días de Dólar/ddayz
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, t, c, r;
char S[1005][105], A[105], B[105], C[105], R[105];

int main(){

    freopen ("ddayz.in", "r", stdin);
    freopen ("ddayz.out", "w", stdout);

    scanf ("%d %d\n", &n, &r);
    S[0][0] = '1';
    for (int i = 1; i <= r; i++){
         for (int j = 0; j <= n-i; j++){
              c = 0;
              int lb = strlen (S[i+j]);
              int la = strlen (S[j]);
              for (int k = la-1; k >= 0; k--)
                   A[++c] = S[j][k]-48;
              c = 0;
              for (int k = lb-1; k >= 0; k--)
                   B[++c] = S[i+j][k]-48;
              c = 0;
              for ( k = 1; k <= max (la,lb) || t == 1; k++){
                   C[k] = A[k] + B[k] + t;
                   t = 0;
                   if (C[k] > 9){
                       t = 1;
                       C[k] -= 10;
                   }
              }
              for (int l = 1; l < k; l++)
                   S[i+j][l-1] = C[k-l]+48;
              for (int k = 0; k <= 100; k++)
                         A[k] = B[k] = C[k] = 0;
         }
    }

    for (int i = 0; i < strlen (S[n]); i++)
         printf ("%c", S[n][i]);

    return 0;
}
