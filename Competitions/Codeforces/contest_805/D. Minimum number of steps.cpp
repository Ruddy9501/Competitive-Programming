/*
2017-05-08 18:16:09
https://codeforces.com/contest/805/problem/D
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int RAN = 1e6 + 5;
const ll mod = 1e9 + 7;
ll n, m, S[RAN], sol = 0ll;
char A1[RAN];
 
int main(){
 
    ll res = 1ll;
    for (int i = 1; i < RAN; i++){
        res = (res*2ll)%mod;
        S[i] = (mod+res-1ll)%mod;
    }
 
    scanf ("%s", A1);
    int p = 0, la = strlen (A1);
 
    ll a = 0, b = 0;
    int pos = 0;
    while (p < la){
           if (A1[p] == 'a') a++, p++;
            else
              while (p < la){
                     if (A1[p] == 'b') b++, p++;
                      else{
                         sol += S[a]*b;
                         sol %= mod;
                         b = 0;
                         break;
                      }
              }
    }
    if (b > 0){
        sol += S[a]*b;
        sol %= mod;
    }
 
    printf ("%lld\n", sol);
 
    return 0;
}