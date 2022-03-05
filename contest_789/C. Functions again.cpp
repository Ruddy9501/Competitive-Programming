/*
2017-03-29 19:36:16
https://codeforces.com/contest/789/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5 + 5;
long long sol, A[RAN], B[RAN];
int n;
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++)
    	 cin >> A[i];
 
    for (int i = 1; i < n; i++) B[i] = abs(A[i]-A[i+1]);	
    
    long long ma = 0;
    for (int i = 1; i <= n; i++){
    	 if (i%2 == 0) ma -=  B[i];
    	  else ma += B[i];
         
         //cout << ma << " ";
         sol = max (sol, ma);
    	 if (ma < 0)
    	 	 ma = 0;
         
 
    } //cout << "\n";
    
    ma = 0;
	for (int i = 1; i <= n; i++){
    	 if (i%2 == 1) ma -=  B[i];
    	  else ma += B[i];
         
         sol = max (sol, ma);
    	 if (ma < 0)
    	 	 ma = 0;
    } 
 
    cout << sol << "\n";
 
	return 0;
}