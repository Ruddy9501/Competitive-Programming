#include <bits/stdc++.h>

using namespace std;

int f (long long x){
    long long y = 0, aux = x;
    while (aux){
         y = y * 10 + aux % 10;
         aux = aux / 10;
     }
     
     if (x == y) return 1;
     else return  0;
}

int main(){
    
    int cas;
    scanf ("%d", &cas);
    for (int i = 1; i <= cas; ++i){
         long long n;
         scanf ("%lld", &n);
         
         int sol = 0;
         for (long long j = 1; j*j <= n; ++j){
              if (n % j == 0){
                  sol += f(j);
                  if (j*j != n)
                      sol += f(n/j);
              }
         }
         
         printf ("Case #%d: %d\n", i, sol);
    }
    
    return 0;
}
