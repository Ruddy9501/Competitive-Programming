/*
https://codeforces.com/contest/1661/problem/D
2022-04-09 20:36:36
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 3 * 1e5 + 5;
 
int cas, n, l;
long long a[MAX], sol;
long long ini[MAX * 5], sal[MAX * 5];
int r1, r2;
 
void Lazy_propagation(int x, int xend, int P){
    if(x == xend)
        return;
 
    long long pv = 1ll * (x+xend)/2;
 
    ini[P*2] += ini[P];
    ini[P*2+1] += (ini[P]  + sal[P] * (pv - x + 1ll));
 
    sal[P*2] += sal[P];
    sal[P*2+1] += sal[P];
 
    sal[P] = 0;
    ini[P] = 0;
}
 
long long Query(int x, int xend, int P){
 
    if(sal[P])
        Lazy_propagation(x, xend, P);
 
    if(r2 < x || xend < r1)
        return 0;
 
    if(r1 <= x && xend <= r2)
        return ini[P];
 
    int pv = (x+xend)/2;
    return Query(x, pv, P*2) + Query(pv+1, xend, P*2+1);
}
 
void Update(int x, int xend, int P, long long sum){
 
    if(sal[P])
        Lazy_propagation(x, xend, P);
 
    if(r2 < x || xend < r1)
        return ;
 
    if(r1 <= x && xend <= r2){
        sal[P] += sum;
        ini[P] += 1ll * (x - r1 + 1ll) * sum;
        return ;
    }
 
    int pv = (x+xend)/2;
    Update(x, pv, P*2, sum);
    Update(pv+1, xend, P*2+1, sum);
}
 
int main(){
 
 
           scanf ("%d %d", &n, &l);
           for (int i = 1; i <= n; ++i){
                scanf ("%lld", &a[i]);
           }
 
            for (int i = n; i >= 1; --i){
                r1 = i, r2 = i;
                long long can = Query(1, n, 1);
 
                if (can >= a[i]) continue;
 
                 if (i >= l)
                    r1 = i - l + 1, r2 = i;
                else
                    r1 = 1, r2 = l;
 
                long long dif  = (a[i] - can);
                long long sum = dif / (1ll * i-r1+1ll) + (dif % (1ll * i-r1+1ll) != 0);
                sol += sum;
                assert(dif >= 0);    
                Update(1, n, 1, sum);
           }
 
           printf ("%lld\n", sol);
 
 
    return 0;
}