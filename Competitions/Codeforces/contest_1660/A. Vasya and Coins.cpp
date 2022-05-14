/*
https://codeforces.com/contest/1660/problem/A
2022-03-31 17:42:28
*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int n, cas;
 
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        
           long long x, y; scanf ("%lld%lld", &x, &y);
           if (x == 0) printf ("1\n");
           else
           printf ("%lld\n", 2ll*y + x + 1);
    }
    
 
    return 0;
}