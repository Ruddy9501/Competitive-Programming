/*
2022-03-09 23:37:08
https://codeforces.com/contest/1650/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int cas;
long long l, r, a, b;
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%lld %lld %lld", &l, &r, &a);
           b = r / a * a - 1;
           printf ("%lld\n", max(r / a + r % a, (b / a + b % a) * (b >= l)));
    }
 
 
    return 0;
}