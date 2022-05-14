/*
2017-10-27 17:18:42
https://codeforces.com/contest/884/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    
    long long tot = 0, n, x; 
    scanf ("%lld %lld", &n, &x); 
    for (int i = 0; i < n; i++){
    	 long long a; scanf ("%lld", &a);
    	 tot += a;
    }
 
    if (tot+n-1ll == x) printf ("YES\n");
     else printf ("NO\n");
 
	return 0;
}