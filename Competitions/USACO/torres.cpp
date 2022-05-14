/*
Ruddy Guerrero Alvarez
12mo 
Villa Clara -> Caibarien
NACINAL 13  -> 2B
Catcher -> calcular pendientes  
*/
#include <cstdio>
#include <algorithm>

#define RAN 50000
using namespace std;

int n, k, a, b, t, s, A[RAN], C[RAN];
bool M[RAN];

long long pend(long long x, long long y, long long z){
               return ((( (A[y]-A[z])*(x-z) - A[x]-A[z])*(y-z)) ));
}

int main(){

    freopen ("TORRES.in", "r", stdin);
    freopen ("TORRES.out", "w", stdout);

    scanf ("%d %d", &n, &k);

    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         A[a] = b;
         M[a] = true;
         if (a > t)
             t = a;
    }

    for (int i = 1; i <= t; i++){
         C[i] = C[i-1];
         if (M[i] == true){
             C[i] += 1;
             for (int j = i-1; j >= 1 && j >= i-k; j--){
                  if (M[j] == true){
                      if (pend(j, s, i) > 0){
                          if (C[j]+1 < C[i]){
                              C[i] = C[j]+1;
                          }
                          s = j;
                      }
                  }
             }
             s = i;
         }

    }

    printf ("%d\n", C[t]);

    return 0;
}
