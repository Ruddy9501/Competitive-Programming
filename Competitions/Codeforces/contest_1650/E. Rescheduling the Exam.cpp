/*
2022-03-11 01:03:30
https://codeforces.com/contest/1650/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int cas, n, d, me;
long long a[RAN], sol, x1, x2, x3, x4, xx[10];
 
multiset <long long> s;
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
         scanf ("%d %d", &n, &d);
         for (int i = 1; i <= n; ++i)
              scanf ("%lld", &a[i]);
         a[0] = 0;
 
         for (int i = 0; i < n; ++i)
              s.insert (a[i+1] - a[i] - 1);
 
         xx[1] = 1, xx[2] = n, xx[3] = xx[4] = 0;
         for (int i = 1; i < n; ++i)
             if (a[i+1] - a[i] - 1 == *s.begin()){
                 xx[2] = i;
                 xx[3] = i+1;
                 break;
             }
 
 
         sol = *s.begin();
         for (int j = 1; j <= 4; ++j){
              int i = xx[j];
              if (i == 0) continue;
              if (i != n){
                  x1 = a[i] - a[i-1] - 1;
                   x2 = a[i+1] - a[i] - 1;
 
 
 
                  if (x1 > sol && x2 > sol) continue;
                  s.erase(s.find(x1));
                  s.erase(s.find(x2));
 
                  x3 = a[i+1] - a[i-1] - 1;
                  s.insert(x3);
                  x4 = (*s.rbegin() + 1) / 2 - 1;
 
 
                  s.insert(x4);
                  sol = max (sol, *s.begin());
                  s.erase(s.find(x4));
 
                  x4 = (d - a[n]) - 1;
                  s.insert(x4);
                  sol = max (sol, *s.begin());
                  s.erase(s.find(x4));
 
                  s.insert(x1);
                  s.insert(x2);
                  s.erase(s.find(x3));
 
                  //printf ("%d\n", (int)s.size());
              }
              else{
                  x1 = a[i] - a[i-1] - 1;
                  s.erase(s.find(x1));
                  s.insert(d - a[n-1] - 1);
                  sol = max (sol, *s.begin());
                  s.erase(s.find(d - a[n-1] - 1));
                  //printf ("%d\n", (int)*s.rbegin());
                  x4 = (*s.rbegin() + 1) / 2 - 1;
                  s.insert(x4);
                  sol = max (sol, *s.begin());
              }
         }
 
         printf ("%lld\n", sol);
         s.clear();
    }
 
 
    return 0;
}