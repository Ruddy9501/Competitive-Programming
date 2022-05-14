/*
2017-10-26 17:49:26
https://codeforces.com/contest/879/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
 
int main(){
   
    int n; int sol = 0;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 int a, b;scanf ("%d%d", &a, &b);
    	 for (int j = 0; ; j++){
    	 	  if (a+j*b > sol){
    	 	  	  sol = a+j*b;
    	 	  	  break;
    	 	  }
    	 }
    }
 
    printf ("%d\n", sol);
 
	return 0;
}