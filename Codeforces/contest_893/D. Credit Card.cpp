/*
2017-11-23 19:36:53
https://codeforces.com/contest/893/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
const int MAX = 1e5 + 5;
const int oo = INT_MAX;
 
int n;
int64 st[4*MAX], c[MAX], l[4*MAX], tot, sum, a[MAX], b, k;
 
void built (int ini, int fin, int p){
     if (ini == fin){
	     st[p] = k - a[ini];
	     return ;
	 }
	 
	 int piv = (ini+fin)/2;
	 built (ini, piv, p*2);
	 built (piv+1, fin, p*2+1);
	 st[p] = min (st[2*p], st[2*p+1]);
}
 
void leisi (int ini, int fin, int p){
     if (ini == fin) return ;
     
     l[p*2] += l[p];
     l[p*2+1] += l[p];
     
     st[p*2] -= l[p];
     st[p*2+1] -= l[p];
     
     l[p] = 0; 
} 
 
int64 query (int ini, int fin, int p, int a, int b){
	  if (l[p]) 
	      leisi (ini, fin, p);
     
      if (ini > b || fin < a) return oo;
          
      if (ini >= a && fin <= b) return st[p];
      
      int piv = (ini+fin)/2;
      return min (query (ini, piv, p*2, a, b), query (piv+1, fin, p*2+1, a, b));
} 
 
void update (int ini, int fin, int p, int a, int b, int64 val){
     
     if (l[p])
         leisi (ini, fin, p);
     
     if (ini > b || fin < a) return ;
     
     if (ini >= a && fin <= b){
	     l[p] += val;
	     st[p] -= val;
	     return ;
	 }     
      
     int piv = (ini+fin)/2;
     update (ini, piv, p*2, a, b, val); 
     update (piv+1, fin, p*2+1, a, b, val); 
     
     st[p] = min (st[p*2], st[p*2+1]);
}
 
int main (){
    
    scanf ("%d %lld", &n, &k) ;
    for (int i = 1; i <= n; i++){
	     scanf ("%lld", &b);
	     a[i] = a[i-1] + b;
	     c[i] = b;
	}
	
	for (int i = 1; i <= n; i++){
	     if (a[i] > k) {
		     printf ("-1\n");
		     return 0; 
		 }
	}
	
	built (1, n, 1);
    
    int sol = 0;
    for (int i = 1; i <= n; i++){
	     tot += c[i];
	     
	     
	     if (tot >= 0 || c[i] != 0) continue;
	     
	     sol++;
	     sum = query (1, n, 1, i, n);
	     tot += sum;
	     update (1, n, 1, i, n, sum);
	    
	     if (tot < 0){
		     printf ("-1\n");
		     return 0;
		 }
	}
	
	printf ("%d\n", sol);
    
    return 0;
}