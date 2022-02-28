/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
PSN EXPLORA#1
Luciernagas/firefly
TAbla acomulativa
*/
#include <cstdio>
#include <algorithm>

#define RAN 500005
using namespace std;

int n, m, a, s1 = 1 << 30, s2, R[RAN], S[RAN], A[RAN];

int main(){

    freopen ("firefly.in", "r", stdin);
    freopen ("firefly.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         if (i % 2 == 1)
             R[a+1]++;
          else
             S[m-a+1]++;
    }

    A[0] = n/2;
    for (int i = 1; i <= m; i++){
         A[i] = A[i-1] + S[i] - R[i];
         if (A[i] < s1){
             s1 = A[i];
             s2 = 0;
         }
         if (A[i] == s1)
             s2++;
    }

    printf ("%d %d\n", s1, s2);

    return 0;
}
