/*
2017-08-29 19:34:57
https://codeforces.com/contest/842/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 3e5 + 5;
 
int n, x, y, S[RAN], A[RAN];
vector <int> d;
vector <int> v[RAN], cero[RAN], uno[RAN];
 
void dfs (int nd, int pd, int div, bool mar){
     
      S[nd] = max (div, S[nd]);
 
     for (int i = 0; i < (int)v[nd].size(); i++){
     	  int ne = v[nd][i];
 
     	  if (ne == pd) continue;
          
          if (A[ne]%div == 0)
              dfs (ne, nd, div, mar);
           else
           	  if (mar)
           	  	  dfs (ne, nd, div, false);
         
     } 
}
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d", &A[i]);
    }
    
    for (int i = 1; i < n; i++){
    	 scanf ("%d %d", &x, &y);
    	 v[x].push_back(y);
    	 v[y].push_back(x);
    }
    
    
	    for (long long j = 1; j*j <= A[1]; j++){
	     	  if (A[1]%j == 0){
	      	  	  d.push_back ((int)j);
	       	  	  
	       	  	  d.push_back (A[1] / j);
	         }
	     }
   
 
    for (auto a : d){
         dfs (1, -1, a, 1);
         /*printf ("%d\n", a);
         for (int i = 1; i <= n; i++)
              printf ("%d ", S[i]);
         printf ("\n\n");   */   
    }
    
    for (int i = 0; i < (int)v[1].size(); i++){
         int nd = v[1][i];
         d.clear();
    	 for (long long j = 1; j*j <= A[nd]; j++){
	     	  if (A[nd]%j == 0){
	      	  	  d.push_back ((int)j);
	       	  	  
	       	  	  d.push_back (A[nd] / j);
	         }
	     }
	     for (auto a : d){
              dfs (nd, 1, a, false);
    }
    
    }
    
    printf ("%d", A[1]);
    for (int i = 2; i <= n; i++)
    	 printf (" %d", S[i]);
    printf ("\n");
 
 
	return 0;
}