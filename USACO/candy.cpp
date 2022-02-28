/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2010-11/November/Problems/Silver
Caramelos/candy 
*/
#include <cstdio>
#include <algorithm>

#define RAN 40010
using namespace std;

int n, a, b, R, p, sol, A[RAN], C[RAN], S[RAN];
bool M[RAN];

int main(){

    freopen ("candy.in", "r", stdin);
    freopen ("candy.out", "w", stdout);

    scanf ("%d %d %d %d", &n, &a, &b, &R);

    for (int i = 1; i <= a; i++)
         scanf ("%d", &A[i]);

    for (int i = 1; i <= b; i++){
         scanf ("%d", &p);
         M[p] = 1;
    }

    M[n] = 0;
    fill (S + 1, S + n, -1);
    for (int i = n; i > 0; i--){
         if (S[i] != -1){

             if (C[i] > a){
                 printf ("-1\n");
                 return 0;
             }

             if (M[i]){
                 C[i]++;
                 if (S[i+R] < S[i]){
                     S[i+R] = S[i];
                     i += (R+1);
                 }
                 continue;
             }

             for (int j = 1; j <= a; j++)
                  if (S[i-A[j]] < S[i] + A[j])
                      S[i-A[j]] = S[i] + A[j];
         }
    }

    for (int i = 0; i <= n; i++)sol = max (sol, S[i]);

    printf ("%d\n", sol);

    return 0;
}
