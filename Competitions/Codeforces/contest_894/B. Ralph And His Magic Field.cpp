/*
2017-11-20 19:37:07
https://codeforces.com/contest/894/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
 
const int64 MOD = 1000000007ll;
int64 n, m, sol;
int k; 
 
int64 ele(int64 mul, int64 p){
      int64 s = 1;
      for (int64 i = 0; i < 64; i++){
           if (p & (1ll<<i)) s = (s*mul)%MOD;
           mul = (mul*mul)%MOD;  
	  }
	  return s;
}
 
int main(){
	
	scanf ("%lld %lld %d", &n, &m, &k);
	
	if (((n+m) & 1) && k==-1){
	    printf ("0\n");
	    return 0;
	}
	
	printf ("%lld\n", ele (ele (2ll, n-1ll), m-1ll) % MOD);
	
	
    return 0;	
}