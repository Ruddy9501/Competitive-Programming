/*
2017-11-27 21:11:29
https://codeforces.com/contest/893/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
const int64 mod = 1e9 + 7;
const int MAX = 2e6 + 5;
 
int cas, n, k;
int64 f[MAX], d[MAX]; 
 
int64 MD(int64 A,int64 B,int64 C){//return (A/B)%C
     if(A%B == 0)
         return A/B;
     return (A+(C*MD(B-(A%B),C%B,B)))/B; }
 
int main (){
    
    f[0] = 1;
    for (int i = 1; i < MAX; i++){
	     f[i] = (f[i-1]*i) % mod;
	}
	
	d[0] = 1;
	for (int i = 1; i < MAX; i++)
	     d[i] = (d[i-1]*2ll) % mod;
	
	scanf ("%d", &cas);
	while (cas--){
           scanf ("%d %d", &n, &k);
           
           int64 sol = 1;
           for (int64 i = 2; i*i <= n; i++){
		        
		        if (n%i) continue; 
		        
		        int can = 0;
		        while (n%i == 0){
				       n /= i;
				       can++; 
				} 
				
				
			//	printf (" %d %d %lld\n", k+can-1, can, MD (f[k+can-1], f[can], mod));
				sol = (sol * MD (MD (f[k+can-1], f[can], mod), f[k-1], mod)) % mod;
		   }
		   
		   //printf ("%lld %lld\n", sol, p[k][1]);
		   if (n > 1) sol = (sol * MD (MD (f[k], f[1], mod), f[k-1], mod)) % mod;
		   
		   int pos = k%2 ? k-1 : k-1;
		   //printf ("%lld\n", d[pos]);
		   printf ("%lld\n", (sol*d[pos]) % mod);
    }
 
    return 0;
}