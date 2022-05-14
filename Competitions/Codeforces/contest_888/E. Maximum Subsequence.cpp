/*
2017-11-09 19:42:56
https://codeforces.com/contest/888/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
int n;
int64 x, mod;
vector <int64> a, b, v;
 
int main(){
	
	scanf ("%d%lld", &n, &mod);
	for (int i = 0; i < n; i++){
	     scanf ("%lld", &x);
	     if (i < n/2) a.push_back (x);
	      else b.push_back (x);
	}
	
	int l = (int)a.size();
	int64 sol = 0;
	for (int i = 0; i < 1<<l; i++){
		 int64 sum = 0;
	     for (int j = 0; j < l; j++){
		      if (i & (1<<j)) sum += a[j];
		 } 
		 
		 sum %= mod;
		 sol = max (sol, sum);
		 v.push_back (sum);
	}
	
	sort (v.begin(), v.end());
	
	l = (int)b.size();
	for (int i = 0; i < 1<<l; i++){
	     int64 sum = 0;
	     for (int j = 0; j < l; j++){
		      if (i & (1<<j)) sum += b[j];
		 }
		 
		 sum %= mod;
		 sol = max(sol, sum);
		 int64 fal = mod - sum - 1;
		 int p = upper_bound (v.begin(), v.end(), fal) - v.begin();
		 p--;
		 if (p >= 0)
		     sol = max(sol, (sum+v[p])%mod);
		 p++;
		 if (p < (int)v.size())    
		     sol = max(sol, (sum+v[p])%mod);
	//	 printf ("%lld %lld\n", sum, sol);    
	}
	
	printf ("%lld\n", sol);
	
	     
	     
	
    return 0;	
}