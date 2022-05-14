/*
2017-07-18 14:47:03
https://codeforces.com/contest/831/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5;
long long n, m, O, A[RAN], B[RAN], sol = 1ll<<60;
 
int main(){
 
    scanf ("%lld %lld %lld", &n, &m, &O);
    for (int i = 0; i < n; i++)
         scanf ("%lld", &A[i]);
 
    for (int i = 1; i <= m; i++)
         scanf ("%lld", &B[i]);
 
    sort (A, A+n);
    sort (B+1, B+m+1);
 
    for (int i = 1; i <= m-n+1; i++){
    	 long long a = 0;
    	 for (int j = 0; j < n; j++){
              a = max(a, abs(B[i+j]-O) + abs(B[i+j]-A[j]));
    	 }
    	 sol = min(sol, a);
    }
 
    printf ("%lld\n", sol);
 
	return 0;
}