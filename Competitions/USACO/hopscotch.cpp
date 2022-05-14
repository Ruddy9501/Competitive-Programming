/*
Censoring/plata/2015/febrero
*/
#include <cstdio>
#include <iostream>

using namespace std;

int f, c, T, S[102][102], A[102][102];
int main(){

    freopen ("hopscotch.in", "r", stdin);
    freopen ("hopscotch.out", "w", stdout);

    scanf ("%d%d%d", &f,&c,&T);
    for (int i = 1; i <= f; i++)
         for (int j = 1; j <= c; j++)
              scanf ("%d", &A[i][j]);

    S[1][1] = 1;
    for (int i = 1; i <= f; i++)
         for (int j = 1; j <= c; j++)
              for (int k = i+1; k <= f; k++)
                   for (int l = j+1; l <= c; l++){
                        if (A[i][j] != A[k][l])
                            S[k][l] = (S[k][l] + S[i][j])%1000000007;
                   }

    printf ("%d", S[f][c]%1000000007);
    return 0;
}
