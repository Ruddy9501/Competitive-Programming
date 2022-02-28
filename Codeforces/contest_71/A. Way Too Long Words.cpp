/*
2016-04-05 16:48:35
https://codeforces.com/contest/71/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
int n;
char A[10000];
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> A;
         int la = strlen (A);
         if (la <= 10) cout << A << "\n";
         else cout << A[0]<<la-2<<A[la-1]<< "\n";
    }
 
 
    return 0;
}