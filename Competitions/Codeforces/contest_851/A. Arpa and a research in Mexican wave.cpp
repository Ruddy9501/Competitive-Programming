/*
2017-09-04 17:44:15
https://codeforces.com/contest/851/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long n, k, t;
 
int main(){
 
    scanf ("%lld%lld%lld",&n,&k,&t);
 
    if (t < k) printf ("%lld\n", t);
     else if (t <= n) printf ("%lld\n", k);
        else printf ("%lld\n", k+n-t);   
 
	return 0;
}