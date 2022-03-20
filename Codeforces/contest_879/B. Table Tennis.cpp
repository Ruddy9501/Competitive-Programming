/*
2017-10-26 17:56:22
https://codeforces.com/contest/879/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
int n, can;
int64 a[10000], sol, k;
 
int main(){
  
    scanf ("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++)
    	 scanf ("%lld", &a[i]);
    
    sol = a[1];
    for (int i = 2; i <= n; i++){
    	 if (sol > a[i]) can++;
    	  else{
    	  	 sol = a[i];
    	  	 can = 1;
    	  }
 
    	  if (can == k){
    	  	  printf ("%lld\n", sol);
    	  	  return 0;
    	  }
 
    	 // printf ("%d %d %d\n", i, can, sol);
    } 
 
    printf ("%lld\n", sol);	
 
 
	return 0;
}