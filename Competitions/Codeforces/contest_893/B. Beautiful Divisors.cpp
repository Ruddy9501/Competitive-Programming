/*
2017-11-23 18:17:06
https://codeforces.com/contest/893/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, sol;
 
bool ok (int x){
	//(2k - 1) * (2k - 1).
     for (int i = 0; i <= 15; i++){
		 
	      if ( ((1ll<<i)-1) * (1<<(i-1)) == x) return true;
	 }
	 
	 return false;
}
 
int main(){
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
	     if (n % i) continue;
	     if (ok(i)) sol = i; 
	}
	
	printf ("%d\n", sol);
	
    return 0;	
}