/*
2015-11-16 23:11:37
https://codeforces.com/contest/596/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
long long n, x, p, sol;
int main(){
 
    cin >> n;
    p = 0;
    for (int i = 1; i <= n; i++){
         cin >> x;
         sol += abs(p-x);
         p = x;
    }
 
    cout << sol;
 
    return 0;
}