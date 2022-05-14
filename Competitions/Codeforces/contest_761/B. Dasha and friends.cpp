/*
2017-01-31 21:40:46
https://codeforces.com/contest/761/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 1e5+5;
 
int n, m, A[RAN], B[RAN], D1[RAN], D2[RAN];
int solv(int p){
    int pos = 0;
    for (int i = p; i <= n; i++)
         if (D1[i] == D2[pos+1]) pos++;
          else return pos;
 
    for (int i = 1; i < p; i++)
         if (D1[i] == D2[pos+1]) pos++;
          else return pos;
 
    return pos;
}
 
int main() {
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
         cin >> A[i];
    for (int i = 1; i <= n; i++)
         cin >> B[i];
 
 
 
    for (int i = 1; i < n; i++){
            D1[i] = A[i+1]-A[i];
            D2[i] = B[i+1]-B[i];
    }
 
    D1[n] = m-A[n]+A[1];
    D2[n] = m-B[n]+B[1];
 
    string sol = "NO";
    for (int i = 1; i <= n; i++){
         int k = solv(i);
         if (k == n) sol = "YES";
    }
 
    cout << sol << "\n";
 
    return 0;
}