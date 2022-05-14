/*
2017-11-17 17:48:02
https://codeforces.com/contest/892/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e6 + 5;
int n, sol, dp[MAX], a;
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
	     scanf ("%d", &a);
	     dp[max(1, i-a)]++;
	     dp[i]--;
	}
	
	for (int i = 1; i <= n; i++){
	     dp[i] += dp[i-1];
	     if (!dp[i]) sol++;
	}
	
	printf ("%d\n", sol);
    
    return 0;
}