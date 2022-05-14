/*
2017-09-05 18:53:03
https://codeforces.com/contest/846/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, sol;
long long  m, tot, A[100];
bool M[1000];
 
int bus(int n, int k,long long m){
    
    fill (M+1,M+k+1, true); 
    int s = 0, id;
   
    for (int i = 1; i <= k; i++){
    	 long long mi = 1ll<<60;
    	 for (int j = 1; j <= k; j++){
    	 	  if (M[j] && A[j] < mi) 
    	 	  	  mi = A[j], id = j;
    	 }
 
    	 M[id] = false;
         int can = n;
    	 while (can--){
    	 	    if (m >= A[id]){
    	 	    	s++;
    	 	    	m -= A[id]; //printf ("------ %lld\n", A[id]);
    	 	    }
    	 }
 
    	 //printf ("+++ %d %lld\n", A[id], m);
    }
    
    return s;
      	 	
}
 
int main(){
 
    scanf ("%d%d%lld",&n,&k,&m);
    for (int i = 1; i <= k; i++){
    	 scanf ("%lld", &A[i]);
         tot += A[i];
    }
 
    for (int i = 0; i <= n; i++){
         long long t = i * tot; 
         if (t > m) continue;
 
         sol = max (sol, i*(k+1) + bus(n-i, k, m-t));
 
        // printf ("%d %d %d\n", i, i*(k+1),  bus(n-i, k, m-t));
    } 	
    
    printf ("%d\n", sol);
	return 0;
}