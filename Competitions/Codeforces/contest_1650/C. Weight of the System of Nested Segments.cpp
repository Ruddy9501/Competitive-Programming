/*
2022-03-09 23:59:45
https://codeforces.com/contest/1650/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int cas, n, m, a, b;
long long sol;
 
struct tres{
       int p, v, i;
       bool operator<(const tres &r)const{
       return v < r.v;
       }
};
 
 
struct par{
       int v, i;
       bool operator<(const par &r)const{
        return v < r.v;
       }
};
 
vector <tres> v;
vector <par> w;
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
         scanf ("%d%d", &n, &m);
         for (int i = 1; i <= m; ++i){
              scanf ("%d%d", &a, &b);
              v.push_back ((tres){a, b, i});
         }
 
         sort (v.begin(), v.end());
 
         for (int i = 0, j = 0; i < n; ++i, j += 2){
              sol = sol + v[j].v + v[j + 1].v;
              w.push_back ((par){v[j].p, v[j].i});
              w.push_back ((par){v[j + 1].p, v[j + 1].i});
         }
 
         sort (w.begin(), w.end());
         printf ("%lld\n", sol); sol = 0;
         for (int i = 0; i < n; ++i){
              printf ("%d %d\n", w[i].i, w[2*n-i-1].i);
         }
         w.clear();
         v.clear();
    }
 
 
    return 0;
}