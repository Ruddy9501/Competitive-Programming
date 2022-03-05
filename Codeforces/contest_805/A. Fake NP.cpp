/*
2017-05-08 17:02:57
https://codeforces.com/contest/805/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n, m;
 
int main(){
 
    scanf ("%lld%lld", &n, &m);
 
    if (m-n >= 1){
        printf ("2\n");
    }
    else
        printf ("%lld\n", n);
 
 
 
 
    return 0;
}