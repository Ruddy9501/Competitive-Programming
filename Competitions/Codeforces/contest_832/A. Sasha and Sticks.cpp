/*
2017-07-24 17:40:21
https://codeforces.com/contest/832/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    long long n, k;
    scanf ("%lld %lld", &n, &k);
    if ((n / k) % 2ll) printf ("YES\n");
     else printf ("NO\n");
 
	return 0;
}