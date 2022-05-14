/*
2016-04-05 16:19:23
https://codeforces.com/contest/231/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
int sol,a, C[10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < 4;j++){
             cin >> a;
             C[i] += a;
        }
 
 
    for (int i = 1; i <= n; i++)
        if (C[i] > 1) sol++;
 
    cout << sol << "\n";
 
    return 0;
}