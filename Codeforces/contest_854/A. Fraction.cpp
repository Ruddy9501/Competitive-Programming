/*
2017-09-06 16:09:17
https://codeforces.com/contest/854/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
int main(){
 
    scanf ("%d", &n);
    for (int i = (n+1)/2-1; i > 0; i--){
    	 int b = n-i;
    	 if (__gcd(b, i) == 1){
    	 	 printf ("%d %d\n", i, b);
    	 	 break;
    	 }
    }
 
	return 0;
}