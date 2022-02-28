/*
2016-04-05
https://codeforces.com/contest/47/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
         if (i*(i+1)/2==n){
             cout << "YES\n";
             return 0;
         }
    }
     cout << "NO\n";
        return 0;
}