/*
2017-04-06 19:26:19
https://codeforces.com/contest/792/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2e5 + 5;
 
long long sol = 1ll<<60, n, can, A[RAN];
 
int main(){
    
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++) 
    	 scanf ("%lld", &A[i]);
 
    sort (A, A+n);
    
    for (int i = 1; i < n; i++){
    	 if (A[i] - A[i-1] < sol) sol = A[i] - A[i-1], can = 0;
    	 if (A[i] - A[i-1] == sol) can++; 
    }
    
    printf("%lld %lld\n", sol, can);
 
	return 0;
}