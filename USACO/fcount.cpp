/*
2005/febrero/plata
*/
#include <cstdio>
#include <algorithm>

#define RAN 2005
using namespace std;

int n, k, k1, d, ini, fin, sol;
int S[RAN], F[RAN], M[RAN];

int main(){

    freopen ("fcount.in", "r", stdin);
    freopen ("fcount.out", "w", stdout);

    scanf ("%d %d %d %d\n", &n, &k, &k1, &d);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &ini, &fin);
         S[ini]++;
         F[fin+1]++;
    }

    for(int i = 1; i <= d; i++){
        M[i] = M[i-1] + S[i] - F[i];
    }

    for (int i = d; i >= 1; i--){
         if (k > k1)
             k -= M[i];
         if (k <= k1){
             sol = i;
             break;
         }
    }

    printf ("%d", sol);

    return 0;
}
