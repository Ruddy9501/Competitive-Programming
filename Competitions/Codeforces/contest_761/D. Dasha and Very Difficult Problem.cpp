/*
2017-01-31 22:40:04
https://codeforces.com/contest/761/problem/D
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 1e6+5;
 
ll n, l, r, P[RAN], A[RAN], B[RAN];
 
int main() {
 
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    for (int i = 1; i <= n; i++){
         ll p; cin >> p;
         P[p] = i;
    }
 
    ll mi;
    for (int i = 1; i <= n; i++){
         if (i == 1){
             mi = l-A[P[i]];
             B[P[i]] = l;
             continue;
         }
 
         ll b = A[P[i]] + mi + 1;
         if (b > r){
             cout << "-1\n";
             return 0;
         }
 
         if (b < l){
             B[P[i]] = l;
             mi = l - A[P[i]];
             continue;
         }
 
         B[P[i]] = b;
         mi = b - A[P[i]];
 
    }
 
    for (int i = 1; i <= n; i++){
         if (i == 1) cout << B[i];
          else cout << " " << B[i];
    }
    cout << "\n";
 
    return 0;
}