/*
2017-07-18 14:40:44
https://codeforces.com/contest/831/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
#define int64 long long
int64 n, k, T[10000+5], a;
vector <int64> s, x;
unordered_map <int64, int64> m;
 
int main(){
 
    scanf ("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++){
    	 scanf ("%lld", &T[i]);
    	 T[i] += T[i-1];
    }
 
    for (int i = 1; i <= k; i++){
         scanf ("%lld", &a);
         for (int j = 1; j <= n; j++)
              x.push_back(a-T[j]);
 
         sort (x.begin(), x.end());
    	 auto it = unique(x.begin(), x.end());
    	 x.erase(it, x.end());
 
         for (int j = 0; j < (int)x.size(); j++){
         	  int64 xx = x[j];
         	  m[xx]++;
         	  if (m[xx] == k) s.push_back(xx);
         }
 
         x.clear();
    }
 
    sort (s.begin(), s.end());
    auto it = unique(s.begin(), s.end());
    s.erase(it, s.end());
    printf ("%d\n", (int)s.size());
 
	return 0;
}