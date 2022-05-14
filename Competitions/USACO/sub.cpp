/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Marzo/Problems/Bronze
Subsecuencia Contigua Mas Grande/sub
LCS
*/
#include <cstdio>
#include <algorithm>

#define RAN 190
using namespace std;

int la, lb, s, A[RAN], B[RAN], S[RAN][RAN];

int main(){

    freopen ("sub.in", "r", stdin);
    freopen ("sub.out", "w", stdout);

    scanf ("%d %d", &la, &lb);
    for (int i = 1; i <= la; i++)
         scanf ("%d", &A[i]);
    for (int i = 1; i <= lb; i++)
         scanf ("%d", &B[i]);

    for (int i = 1; i <= la; i++){
         for (int j = 1; j <= lb; j++){
              if (A[i] == B[j])
                  S[i][j] = S[i-1][j-1]+1;
              s = max(S[i][j], s);
         }
    }

    printf ("%d\n", s);

    return 0;
}
