/*
2017-02-01 20:17:13
https://codeforces.com/contest/752/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 1e5+5;
 
int  sol,  M[RAN];
char y[RAN], x[RAN], A[RAN], B[RAN];
 
int main() {
 
    cin >> A >> B;
 
    int l = strlen (A);
 
    for (int i = 0 ; i < l; i++){
         if (A[i] != B[i]){
             if (M[A[i]] == 0 && M[B[i]] == 0){
                 M[A[i]] = B[i];
                 M[B[i]] = A[i];
                 sol++;
                 x[sol] = A[i];
                 y[sol] = B[i];
             }
         }
    }
 
    for (int i = 0; i < l; i++){
         if (M[A[i]] != 0 || M[B[i]] != 0){
             if (M[A[i]] != B[i]){
                 cout << "-1\n";
                 return 0;
             }
         }
    }
 
    cout << sol << "\n";
    for (int i = 1; i <= sol; i++)
         cout << x[i] << " " << y[i] << "\n";
    return 0;
}