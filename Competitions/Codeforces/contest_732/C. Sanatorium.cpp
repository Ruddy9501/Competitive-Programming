/*
2016-10-17 18:46:57
https://codeforces.com/contest/732/problem/C
*/
# include <bits/stdc++.h>
using namespace std;
long long A[4],b,c,sol;
 int main(){
 
     cin >> A[0] >> A[1] >> A[2];
 
     sort (A,A+3);
 
     sol = (A[0]+A[1]+2ll)-A[2]-A[2];
 
     if (A[0] == A[1])
         sol = (A[1]+A[0]+2ll)-A[2]-A[2];
     if (A[1] == A[2])
         sol = A[2]-A[0]-1;
 
     if (A[0] == A[1] && A[0] == A[2]) sol = 0;
 
     sol = abs(sol);
     cout << sol <<endl;
 
     return 0;
 }