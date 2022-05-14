/*
2017-09-05 18:26:50
https://codeforces.com/contest/846/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, A[1005], sol;
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         if (A[i]) sol++;  
     }
 
    for (int i = 1; i <= n; i++){
 
    	 int u=0, c=0, U=0, C=0;
 
         for (int j = 1; j < i; j++)
         	  if (A[j]) u++;
         	   else c++;
         
         for (int j = i+1; j <= n; j++)
         	  if (A[j]) U++;
         	   else C++;
 
         if (!A[i]) sol = max(sol, c+U+1);
     
 
 
    } 
 
    printf ("%d\n", sol);
     
 
	return 0;
}