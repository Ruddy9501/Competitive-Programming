/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2010-11/January/Problems/Silver
 Dividiendo el Oro/divgold
 continchage
*/
#include <cstdio>
#include <algorithm>

#define RAN 500010
#define MOD 1000000
using namespace std;

int n, A[260], M[RAN], sum, sol = RAN, s;

int main(){

    freopen ("divgold.in", "r", stdin);
    freopen ("divgold.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         sum += A[i];
    }

    M[0] = 1;
    for (int i = 1; i <= n; i++)
         for (int j = sum/2+1; j >= A[i]; j--)
              if (M[j-A[i]]){
                  M[j] = (M[j] + M[j-A[i]]) % MOD;
                  if (sol >= abs(j-(sum-j))){
                      sol = abs(j-(sum-j));
                      s = M[j];
                  }
              }

    printf ("%d\n%d\n", sol, s);

    return 0;
}
