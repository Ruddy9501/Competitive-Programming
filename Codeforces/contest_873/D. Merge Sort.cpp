/*
2017-10-12 18:12:55
https://codeforces.com/contest/873/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
int n, k, m, S[MAX];
 
void dfs (int a, int b){
	 if (a+1 >= b){
	 	 S[a] = ++m;
	 	 return ;
	 }
 
	 if (k == 0){
         for (int i = a; i < b; i++)
         	  S[i] = ++m;
	 }
	 else{
	 	k -= 2;
	 	int piv = (a+b)/2;
	 		dfs (piv, b);
	 	dfs (a, piv);
	 
	 } 
}
 
int main(){
    
    scanf ("%d %d", &n, &k);
    
    if (k%2 == 0){
    	printf ("-1\n");
    	return 0;
    }
 
    k--;dfs (0, n);
    
    if (k > 0){
    	printf ("-1\n");
    	return 0; 
    } 
 
    for (int i = 0; i < n; i++){
    	 printf ("%d", S[i]);
         if (i == n-1) printf ("\n");
          else printf (" ");
    }
 
	return 0;
}