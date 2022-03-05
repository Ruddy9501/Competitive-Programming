/*
2017-06-25 18:19:10
https://codeforces.com/contest/821/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
#define int64 long long
 
int64 m, b, sol;
 
int main(){
 
    scanf ("%lld%lld", &m, &b);
    for (int64 x = 0; x <= m*b; x++){
         int64 y = (int64)(-x/m+b);
         if (x%m != 0) y--;
         y = abs(y);
         sol = max(sol, (x*(x+1ll))/2ll*(y+1ll) + (y*(y+1ll))/2ll*(x+1ll));
    }
 
    printf ("%lld\n", sol);
 
    return 0;
}