/*
2017-02-21 20:53:13
https://codeforces.com/contest/768/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n, a, b, sol, l;
bool M[100];
 
ll calc(ll n){
   ll l = log2(n)+1ll;
   return (1ll<<l)-1ll;
}
 
int solve(ll n, ll ini, ll fin, ll a, ll b){
    if (ini > b || fin < a) return 0;
    if (ini >= a && fin <= b) return  n;
    ll piv = (ini+fin-1ll)/2ll;
    return solve(n/2ll, ini, piv, a, b) + solve(n/2ll, piv+2ll, fin, a, b) + solve(n%2ll, piv+1ll, piv+1ll, a, b);
}
 
int main(){
 
    cin >> n >> a >> b;
    printf ("%d\n", solve(n, 1ll, calc(n), a, b));
 
    return 0;
}