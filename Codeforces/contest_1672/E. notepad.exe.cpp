/*
https://codeforces.com/contest/1672/problem/E
2022-04-23 20:43:43
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int cas, n;
int a[RAN], b[RAN], c[RAN], ant[RAN], aux[RAN];
 
map <int, int> m;
 
int f(int x){
    if (m.count(x)) return m[x];
    printf ("? %d\n", x);
    fflush(stdout);
    int w;
    scanf ("%d", &w);
    return m[x] = w; 
}
 
int main(){
    
    scanf ("%d", &n);
    long long sol = 1<<30;       
    int ini = 1, fin = 2001*n, ma;
    while (ini <= fin){
        int mid = (ini + fin)>>1;
        int xx = f(mid);
        if (xx == 0) xx = 20005;
        if (xx <= 1) 
            ma = mid, fin = mid - 1;
        else 
            ini = mid + 1;  
    }
    sol = ma;
    for (int i = 1; i <= n; ++i){
         int x = (ma - 1) / i;
         if (x && f(x)){
             sol = min (sol, 1ll * f(x) * x); 
         }
    }
    printf ("! %lld\n", sol);
    fflush(stdout);
 
    return 0;
}
