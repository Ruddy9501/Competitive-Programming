/*
2017-02-20 19:13:36
https://codeforces.com/contest/768/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int A[100000];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    int sol = 0;
    sort (A+1,A+n+1);
 
    for (int i = 2; i < n; i++)
         if (A[i] > A[1] && A[i] < A[n])
             sol++;
 
    cout << sol << "\n";
    return 0;
}