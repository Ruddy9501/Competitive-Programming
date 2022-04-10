/*
https://codeforces.com/contest/1661/problem/C
2022-04-09 18:41:00
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 3 * 1e5 + 5;
 
int cas, n;
long long a[MAX], sol;
 
bool f(long long m, long long ma){
     long long x = (m / 2ll) + (m % 2ll);
     long long y = (m / 2ll);
 
     for (int i = 1; i <= n; ++i){
          long long dif = abs(a[i] - ma);
 
          //if (dif == 0ll) continue;
 
          if (dif % 2ll == 1ll){
              if (x == 0ll) return false;
 
              x--;
              dif--;
          }
 
          long long ny = dif / 2ll;
 
          if (ny <= y){
              y -= ny;
          }
          else{
              ny -= y;
              y = 0;
              long long nx = ny * 2ll;
              if (nx <= x)
                  x -= nx;
              else
                  return false;
          }
     }
 
 
     return true;
}
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           long long ma = 0;
           for (int i = 1; i <= n; ++i){
                scanf ("%lld", &a[i]);
                ma = max(ma, a[i]);
           }
 
 
 
           for  (int i = 0; i <= 3; ++i){
                   long long sol1 = -1;
                   ma += i;
                   long long ini = 0ll, fin = 2000000000000000000ll;
                   while (ini <= fin){
                        // printf ("%lld %lld\n", ini, fin);
                          long long mid = (ini + fin) / 2ll;
                          if (f(mid, ma)) fin = mid - 1ll, sol1 = mid;
                           else ini = mid + 1ll;
                   }
 
                   if (i == 0)
                       sol = sol1;
                   sol = min (sol, sol1);
                  // printf ("%lld\n", sol);
            }
           assert (sol>=0);
           printf ("%lld\n", sol);
    }
 
 
    return 0;
}