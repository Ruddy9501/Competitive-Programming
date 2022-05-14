#include <bits/stdc++.h>

using namespace std;

int n, m, k, sol;

int main(){

    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n; i++){
         for (int j = 0; j <= m; j++){
              for (int x = 0; x <= n; x++){
                   for (int y = 0; y <= m; y++){
                        int a = i-x;
                        int b = j-y;
                        int c = __gcd(a,b);
                        //printf ("%d %d %d\n", a, b, c);
                        if (c == k-1) sol++;
                   }
              }
         }
    }


    printf ("%d\n", sol);

    return 0;
}
