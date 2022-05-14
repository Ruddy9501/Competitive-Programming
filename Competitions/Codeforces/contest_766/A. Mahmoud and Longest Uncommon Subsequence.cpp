/*
2017-02-07 20:10:52
https://codeforces.com/contest/766/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
 
string a, b;
 
 
int main(){
 
    cin >> a >> b;
    if (a == b) cout << "-1\n";
     else cout << max(a.size(), b.size()) << "\n";
 
    return 0;
}