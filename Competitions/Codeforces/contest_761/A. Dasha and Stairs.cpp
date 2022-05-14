/*
2017-01-31 21:27:31
https://codeforces.com/contest/761/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 1e5+5;
 
int main() {
 
    int a, b;
    cin >> a >> b;
    string sol = "NO";
    if (a == b && a != 0) sol = "YES";
    if (a+1 == b) sol = "YES";
    if (a == b+1) sol = "YES";
 
    cout << sol  << "\n";
 
    return 0;
}