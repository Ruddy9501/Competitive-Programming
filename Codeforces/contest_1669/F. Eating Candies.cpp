/*
https://codeforces.com/contest/1669/problem/F
2022-04-23 15:19:42
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2e5 + 5;
int cas, n, tot, sol, a[RAN];
map <int, int> m;
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        scanf ("%d", &n);
        tot = 0;
        m.clear();
        for (int i = 1; i <= n; ++i){
             scanf ("%d", &a[i]);
             tot += a[i];
             m[tot] = i;
        }
        
        tot = sol = 0;
        for (int i = n; i >= 1; --i){
             tot += a[i];
             if (m.count(tot) > 0){
                 if (m[tot] < i) 
                    sol = max(sol, m[tot] + n - i + 1);
             }
        }
        
        printf ("%d\n", sol);
    }
    
    return 0;
}
