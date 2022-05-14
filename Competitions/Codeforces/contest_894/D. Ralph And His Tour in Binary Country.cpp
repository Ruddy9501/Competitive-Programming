/*
2017-11-21 06:07:28
https://codeforces.com/contest/894/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
const int MAX = 1e6 + 5;
int n, m, x, y;
int64 a[MAX]; 
vector <int64> d[MAX], t[MAX];
 
int64 Query (int x, int64 y){
      int64 dis = 0, sol = 0;
      while (x > 0){
	         
	         int p = upper_bound (d[x].begin(), d[x].end(), y-dis) - d[x].begin(); p--;
	         
	         if (p >= 0) sol = sol + (y-dis)*(p+1) - t[x][p];
	        
	    //     printf ("p: %d sol: %lld %lld %lld\n", p, sol, d[x][p], dis);
	         
	         if (x != 1){
				 p = upper_bound (d[x].begin(), d[x].end(), y-2ll*a[x]-dis) - d[x].begin(); p--;
				 if (p >= 0) sol = sol - ((y-2ll*a[x]-dis)*(p+1) - t[x][p]);
			 }
	         
	    //     printf ("2 %d %lld\n", p, sol);         
	         
	         dis += a[x];
	         x /= 2;
	  } 
	  
	  return sol;
}
 
int main(){
	
	scanf ("%d %d", &n, &m);
	for (int i = 2; i <= n; i++){
	     scanf ("%lld", &a[i]);
	     int p = i;
	     int64 dis = 0;
	     while (p > 1){
			    dis += a[p]; 
		        p /= 2;
		        d[p].push_back (dis);
		 }
	}
	
	for (int i = 1; i <= n; i++){
		 d[i].push_back (0ll);
	     sort (d[i].begin(), d[i].end());
	     int64 tot = 0;
	     for (int64 j : d[i]){
		      tot += j;
		      t[i].push_back (tot);
		 } 
	}
	
		
	while (m--){
	       int x; int64 y;
	       scanf ("%d %lld", &x, &y);
	       printf ("%lld\n", Query(x, y));
	}
	
	
    return 0;	
}  