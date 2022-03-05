/*
2017-02-13 16:22:11
https://codeforces.com/contest/766/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
 
int n;
long long A[RAN];
 
 
int main(){
 
   cin >> n;
   for (int i  = 1; i <= n; i++) cin >> A[i];
 
   sort (A+1, A+n+1);
   string sol = "NO";
   for (int i = 1; i <= n-2; i++){
        if (A[i] + A[i+1] > A[i+2]) sol = "YES";
   }
 
   cout << sol << "\n";
 
    return 0;
}