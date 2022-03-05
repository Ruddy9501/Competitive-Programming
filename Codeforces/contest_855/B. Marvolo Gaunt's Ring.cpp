/*
2018-02-28 17:35:51
https://codeforces.com/contest/855/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
const int MAX = 1e5 + 5;
int n;
int64 a, b, c, x[MAX], dp[3][MAX];
 
int main(){
 
    scanf ("%d %lld %lld %lld", &n, &a, &b, &c);
    for (int i = 1; i <= n; i++)
    	 scanf ("%lld", &x[i]);
    
    dp[0][0] = dp[1][0] = dp[2][0] = LLONG_MIN; 
    for (int i = 1; i <= n; i++)
    	 dp[0][i] = max (dp[0][i-1], a*x[i]);
    for (int i = 1; i <= n; i++)
    	 dp[1][i] = max (dp[1][i-1], dp[0][i] + b*x[i]); 	
    for (int i = 1; i <= n; i++)
    	 dp[2][i] = max (dp[2][i-1], dp[1][i] + c*x[i]); 	
    
 
    printf ("%lld\n", dp[2][n]);
 
	return 0;
}