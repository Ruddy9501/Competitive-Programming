/*
2017-05-08 17:20:01
https://codeforces.com/contest/805/problem/C
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n, m;
string a;
 
int main(){
 
    cin >> n;
    if (n == 1 || n == 2) cout << "0\n";
     else cout << (n-1)/2 <<"\n";
    return 0;
}