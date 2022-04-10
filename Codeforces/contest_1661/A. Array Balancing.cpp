/*
https://codeforces.com/contest/1661/problem/A
2022-04-09 17:51:46
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
 
int cas, n;
long long a[MAX], b[MAX], dp[MAX][2];
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
           for (int i = 1; i <= n; ++i) scanf ("%lld", &b[i]);
 
 
           long long sol = 0;
           for (int i = 2; i <= n; ++i){
                sol += min(abs(a[i] - a[i-1]) +  abs(b[i] - b[i-1]), abs(b[i] - a[i-1]) +  abs(a[i] - b[i-1]));
           }
 
           printf ("%lld\n", sol);
    }
 
 
    return 0;
}