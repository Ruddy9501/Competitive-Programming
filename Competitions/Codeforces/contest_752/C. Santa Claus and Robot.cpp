/*
2017-02-01 19:49:40
https://codeforces.com/contest/752/problem/C
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 2*1e5+5;
int sol;
char A[RAN];
 
int main() {
    int l;
    cin >> l;
    cin >> A;
    int x = RAN, y = RAN;
    int xx = RAN, yy = RAN;
    int ax, ay, dd = 0;
    int i = 0;
    for (; i < l; i++){
         //cout << A[i]<<"\n";
         if (A[i] == 'L') x-=1;
         if (A[i] == 'R') x+=1;
         if (A[i] == 'D') y-=1;
         if (A[i] == 'U') y+=1;
         int d = abs(x-xx) + abs(y-yy);
         if (d <= dd){
             xx = ax;
             yy = ay;
             sol++;
             dd = 0;
             ax = x;
             ay = y;
             continue;
         }
 
         ax = x;
         ay = y;
         dd = d;
    }
 
    cout << sol+1 << "\n";
 
    return 0;
}