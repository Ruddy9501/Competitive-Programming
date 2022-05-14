/*
2017-05-08 17:09:38
https://codeforces.com/contest/805/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n, m;
string a;
 
int main(){
 
    cin >> n; bool mk = true;
    for (int i = 0; i < n; i+=2){
         if (mk) a += "aa", mk = false;
          else a += "bb", mk = true;
 
    }
 
    for (int i = 0; i < n; i++)
         cout << a[i];
    cout << "\n";
 
 
 
 
    return 0;
}