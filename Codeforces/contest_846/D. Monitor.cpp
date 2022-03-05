/*
2017-09-05 19:51:29
https://codeforces.com/contest/846/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, k, q, sol=-1, T[1005][1005];
struct par{
	   int x, y, t;
}A[500*500+5];
 
bool ok(int t){
     for (int i = 1; i <= n; i++)
     	  fill (T[i], T[i]+m+1, 0);
 
     for (int i = 1; i <= q; i++) 	
     	  if (A[i].t <= t) 
     	  	  T[A[i].x][A[i].y]++;
 
     for (int i = 1; i <= n; i++) 	  	
     	 for (int j = 1; j <= m; j++)
     	      T[i][j] = T[i][j] + T[i-1][j] + T[i][j-1] - T[i-1][j-1];
 
     for (int i = 1; i <= n-k+1; i++) 	  	
     	 for (int j = 1; j <= m-k+1; j++){
     	      int t = T[i+k-1][j+k-1] - T[i+k-1][j-1] - T[i-1][j+k-1] + T[i-1][j-1];
     	      if (t == k*k) return true;
     	 } 	    
 
     return false;
}
 
int main(){
 
    scanf ("%d%d%d%d",&n,&m,&k,&q);
    for (int i = 1; i <= q; i++)
    	 scanf ("%d%d%d",&A[i].x,&A[i].y,&A[i].t);
    
 
    int ini = 0, fin = 1e9+1;
 
    while (ini <= fin){
    	   int piv = (ini+fin)/2;
    	   if (!ok(piv)) ini = piv+1;
    	    else fin = piv-1, sol = piv;
 
    }
    //printf ("%d\n", ok(8));
    if (sol == -1) printf ("-1\n");
     else printf ("%d\n", sol);
 
    return 0;
}