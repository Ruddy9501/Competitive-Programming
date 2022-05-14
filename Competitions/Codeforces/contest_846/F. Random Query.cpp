/*
2017-09-05 21:02:27
https://codeforces.com/contest/846/problem/F
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e6 + 5;
 
int n, a, U[RAN];
long long sol;
 
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 
    	 scanf ("%d", &a);
    	 sol = sol + 2ll * (i - U[a]) * (n - i + 1ll) - 1ll;
    	 U[a] = i;
    }
 
    printf ("%lf\n", 1.0*sol/n/n);
 
	return 0;
}