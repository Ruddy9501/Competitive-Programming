/*
2017-02-02 16:39:28
https://codeforces.com/contest/764/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int a, b, c;
    cin >> a >> b >> c;
    a = a*b/__gcd(a, b);
    cout << c / a << "\n";
    return 0;
}