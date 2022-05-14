/*
2017-09-22 20:32:26
https://codeforces.com/contest/847/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int64;
int64 n, k;
 
int main() {
	scanf("%lld%lld", &n, &k);
 
	if (n*(n-1ll)/2ll < k){
		printf ("Impossible");
	}
	else{
		long long p;
		for (long long i = 1; i <= n; i++)
			 if (i*(i-1ll)/2ll <= k)
			 	 p = i;
 
	    n = n - p;
	    k = k - (p)*(p-1ll)/2ll;
 
	    //printf ("%lld %lld\n", p, k);
	    for (long long i = 1; i <= p; i++){
	    	 printf ("(");
	    	 if (i == k){
	    	 	 printf ("()");
	    	 	 n--;
	    	 }
	    }	
 
	    for (int i = 1; i <= p; i++)
	         printf (")");
 
	    for (int i = 1; i <= n; i++)
	         printf ("()");      
	}
    
    printf ("\n");
 
	return 0;
}