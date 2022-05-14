/*
2017-11-09 19:17:30
https://codeforces.com/contest/888/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
int64 a[] = {0ll,0ll,1ll,2ll,9ll};
 
int main(){
	
	int64 a, b, sol = 0;
	scanf ("%lld %lld", &a, &b);
    if (b >= 1) sol++; //printf ("%lld\n", sol);
    if (b >= 2) sol += a*(a-1ll) / 2ll;
    if (b >= 3) sol += a*(a-1ll)*(a-2ll) / 6ll * 2ll;
    if (b >= 4) sol += a*(a-1ll)*(a-2ll)*(a-3ll) / 24ll * 9ll;
	
	printf ("%lld\n", sol);
    return 0;	
}