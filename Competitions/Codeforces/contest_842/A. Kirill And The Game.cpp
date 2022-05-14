/*
2017-08-29 18:28:35
https://codeforces.com/contest/842/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long l, r, x, y, k;
 
int main(){
 
    scanf ("%lld %lld %lld %lld %lld", &l, &r, &x, &y, &k);
    for (long long i = x; i <= y; i++){
    	 if (k * i >= l && k * i <= r){
    	 	 printf ("YES\n");
    	 	 return 0;
    	 }
    }
    
    printf ("NO\n")	;
 
	return 0;
}