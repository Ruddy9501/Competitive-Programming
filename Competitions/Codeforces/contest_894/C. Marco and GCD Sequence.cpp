/*
2017-11-20 19:43:33
https://codeforces.com/contest/894/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, gc, b[10005];
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) scanf ("%d", &b[i]);
   
    for (int i = 1; i <= n; i++)
         if (b[i]%b[1]) {
		     printf ("-1\n");
		     return 0;
		 }
   
    printf ("%d\n", 2*n);		 
    for (int i = 1; i <= n; i++){
	     printf ("%d %d", b[1], b[i]);
	     i == n ? printf ("\n") : printf (" ");
    } 		 
   
    return 0;
}