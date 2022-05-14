/*
2016-10-03 14:39:53
https://codeforces.com/contest/723/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int sol, t, A[10], mi = 1e9;
int main(){
 
    cin >> A[1] >> A[2] >> A[0];
 
    for (int i = 1; i <= 100; i++){
         t = abs(A[0]-i)+abs(A[1]-i)+abs(A[2]-i);
         if (t < mi){
             mi = t;
             sol= i;
         }
    }
 
    cout << mi << endl;
 
    return 0;
}