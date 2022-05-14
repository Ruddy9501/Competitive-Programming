/*
2017-10-25 00:58:22
https://codeforces.com/contest/883/problem/K
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e6 + 5;
int n, a[MAX], b[MAX], s[MAX];
 
int main(){
 
    scanf ("%d", &n);
    int p, mi = INT_MAX;
    for (int i = 1; i <= n; i++){
    	 scanf ("%d%d",&a[i], &b[i]);
    	 s[i] = a[i] + b[i];
    	 if (mi > s[i]){
    	 	 mi = s[i];
    	 	 p = i;
    	 }
    }
    //printf ("%d\n", p);
    int pp = p;
    while (pp > 1){
    	   pp--;
    	   if (s[pp] >= s[pp+1]+1)
    	   	   s[pp] = s[pp+1]+1;
    	   	else{
    	   	   int p1 = pp+1; 	
    	   	   while (1){
    	   	   	      if (s[p1] > s[p1-1]+1){
    	   	   	      	  s[p1] = s[p1-1]+1;
    	   	   	      	  p1++;
    	   	   	      }
    	   	   	       else
    	   	   	          break;	
    	   	   }	 
    	   	}
    }
    
 
    pp = 1;
    while (pp < n){
    	   pp++;
    	   if (s[pp] >= s[pp-1]+1)
    	   	   s[pp] = s[pp-1]+1;
    	   	else{
    	   	   int p1 = pp-1; 	
    	   	   while (1){
    	   	   	      if (s[p1] > s[p1+1]+1){
    	   	   	      	  s[p1] = s[p1+1]+1;
    	   	   	      	  p1--;
    	   	   	      }
    	   	   	       else
    	   	   	          break;	
    	   	   }	 
    	   	}
    }
 
    long long sol1 = 0;
    for (int i = 1; i <= n; i++){
    	 sol1 += 1ll*(s[i]-a[i]);
         if (s[i] < a[i]){
         	 printf ("-1\n");
         	 return 0;
         }
    }
 
    printf ("%lld\n", sol1);
    for (int i = 1; i <= n; i++){
         printf ("%d", s[i]); 
    	 if (i == n) printf ("\n");
    	  else printf (" ");
    } 	
 
	return 0;
}