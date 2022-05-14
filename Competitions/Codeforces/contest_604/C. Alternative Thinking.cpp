/*
2015-12-01 20:04:59
https://codeforces.com/contest/604/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, a, m, sol, con, con1, S[2][1000000], R[2][1000000];
char A[1000000];
priority_queue <int,vector<int>, greater<int> >Q;
 
int main(){
 
    cin >> n;
    cin >> A+1;
 
 
    con = 1;
    con1 = 0;
    for (int i = 1; i <= n; i++){
         S[0][i] = S[0][i-1];
         S[1][i] = S[1][i-1];
         if (A[i]=='0') S[0][i] = S[1][i-1]+1;
          else S[1][i] = S[0][i-1]+1;
    }
 
    con = 1;
    con1 = 0;
    for (int i = n; i >= 1; i--){
         R[0][i] = R[0][i+1];
         R[1][i] = R[1][i+1];
         if (A[i]=='0') R[0][i]=R[1][i+1]+1;
          else R[1][i] = R[0][i+1]+1;
    }
 
    sol = max (S[0][n],S[1][n]);
    int ini = 0;
    A[0] = A[n+1] = '0';
    for (int i = 1; i <= n; i++){
         if (A[i]==A[i+1] || i == n){
             sol = max (sol, S[A[ini]-'0'][ini]+i-ini+R[A[i]-'0'][i+1]);
             ini = i;
         }
    }
 
    cout << sol << endl;
    return 0;
}