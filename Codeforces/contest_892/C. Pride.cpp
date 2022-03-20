/*
2017-11-17 18:37:08
https://codeforces.com/contest/892/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, gc, a[2005], g, mi = 1<<30;
 
int main(){
    
    scanf ("%d", &n);
    int can = n;
    for (int i = 1; i <= n; i++){
	     scanf ("%d", &a[i]);
	     gc = __gcd (gc, a[i]);
	     if (a[i] == 1) can--;
	}
	
	if (can != n){
	    printf ("%d\n", can);
	    return 0;	
	}
	
	if (gc != 1){
	    printf ("-1\n");
	    return 0;
	}
	
	for (int i = 1; i <= n; i++){
         int g = 0, j;
         for (j = i; j <= n && g != 1; j++) g = __gcd (g, a[j]); 
		 
		 if (g == 1) mi = min (mi, j-i-1);
		 //printf ("%d %d %d\n", i, j, g);
	}
	
	printf ("%d\n", can + mi - 1);
 
    return 0;
}