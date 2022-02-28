/*
2016-11-16 04:07:19
https://codeforces.com/contest/734/problem/D
*/
#include <bits/stdc++.h>
#define ll long long
#define RAN 1000000
using namespace std;
 
struct par{
       ll x;
       char car;
}mx, MX, my, MY, d1, d2, d3, d4;
char Car[RAN];
ll X[RAN], Y[RAN];
int main(){
 
    ll n, Rx, Ry;
    cin >> n;
    cin >> Rx >> Ry;
    Rx += 1000000000ll;
    Ry += 1000000000ll;
    mx.x = MX.x = my.x = MY.x = -1;
    d1.x  = d2.x = d3.x = d4.x = -1;
    for (int i = 0; i < n; i++){
         cin >> Car[i] >> X[i] >> Y[i];
         X[i] += 1000000000ll;
         Y[i] += 1000000000ll;
 
         if (Ry == Y[i]){
             if ((mx.x == -1 || mx.x > abs(X[i]-Rx)) && X[i] > Rx)
                  mx.x = abs(X[i]-Rx), mx.car = Car[i];
             if ((MX.x == -1 || MX.x > abs(X[i]-Rx)) && X[i] < Rx) 
                  MX.x = abs(X[i]-Rx), MX.car = Car[i];
         }
 
         if (Rx == X[i]){
             if ((my.x == -1 || my.x > abs(Y[i]-Ry)) && Y[i] > Ry)
                 my.x = abs(Y[i]-Ry), my.car = Car[i];
             if ((MY.x == -1 || MY.x > abs(Y[i]-Ry)) && Y[i] < Ry) 
                 MY.x = abs(Y[i]-Ry), MY.car = Car[i];
         }
 
         if (abs(X[i]-Rx) == abs(Y[i]-Ry)){
             if (X[i] < Rx && Y[i] < Ry){
                 if (d1.x == -1 || d1.x > abs(X[i]-Rx)) d1.x = abs(X[i]-Rx), d1.car = Car[i];
             }
             if (X[i] > Rx && Y[i] > Ry){
                 if (d2.x == -1 || d2.x > abs(X[i]-Rx)) d2.x = abs(X[i]-Rx), d2.car = Car[i];
             }
             if (X[i] > Rx && Y[i] < Ry){
                 if (d3.x == -1 || d3.x > abs(X[i]-Rx)) d3.x = abs(X[i]-Rx), d3.car = Car[i];
             }
             if (X[i] < Rx && Y[i] > Ry){
                 if (d4.x == -1 || d4.x > abs(X[i]-Rx)) d4.x = abs(X[i]-Rx), d4.car = Car[i];
             }
         }
    }
 
    string sol = "NO";
    if (mx.car == 'R' || mx.car == 'Q') sol = "YES";
    if (MX.car == 'R' || MX.car == 'Q') sol = "YES";
    if (my.car == 'R' || my.car == 'Q') sol = "YES";
    if (MY.car == 'R' || MY.car == 'Q') sol = "YES";
    if (d1.car == 'Q' || d1.car == 'B') sol = "YES";
    if (d2.car == 'Q' || d2.car == 'B') sol = "YES";
    if (d3.car == 'Q' || d3.car == 'B') sol = "YES";
    if (d4.car == 'Q' || d4.car == 'B') sol = "YES";
 
    cout << sol << "\n";
 
    return 0;
}