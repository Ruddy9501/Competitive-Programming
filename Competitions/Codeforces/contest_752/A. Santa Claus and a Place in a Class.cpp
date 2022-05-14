/*
2017-02-01 19:04:15
https://codeforces.com/contest/752/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a, b, k;
int main() {
 
    cin >> a >> b >> k;int i = 0, j = 0;
    for (i = 1; i <= a; i++)
         for (j = 1; j <= b; j++){
 
               if (k == 1){
                     cout << i << " " << j << " L\n";
                     return 0;
                 }
             k-=2;
 
                 if (k == 0){
                     cout << i << " " << j << " R\n";
                     return 0;
                 }
         }
 
 
    return 0;
}