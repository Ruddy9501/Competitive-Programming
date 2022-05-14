#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2e5 + 5;
int cas, n, k, a[RAN];
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        scanf ("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf ("%d", &a[i]);
        
        int sol = 0;
        for (int i = 30; i >= 0; --i){
             int cont = 0;
             for (int j = 1; j <= n; ++j)
                  if (!(a[j] & (1<<i)))
                    cont++;
             if (cont <= k){
                 sol |= (1<<i);
                 k -= cont;
             }
        }        
        
        printf ("%d\n", sol);
        
    }
    
    return 0;
}
 
