/*
2016-10-17 18:07:56
https://codeforces.com/contest/732/problem/B
*/
 # include <bits/stdc++.h>
 using namespace std;
int n,m,sol,A[10000];
 int main(){
 
     cin >> n >> m;
     for (int i = 1; i <= n; i++){
          cin >> A[i];
     }
 
     for (int i = 2; i <= n; i++){
          if (A[i-1] + A[i] < m){
                sol += (m-A[i]-A[i-1]);
              A[i] += (m-A[i]-A[i-1]);
          }
     }
 
     cout << sol << endl;
     cout << A[1];
     for (int i = 2; i <= n; i++)
          cout <<  " " << A[i];
     cout << endl;
 
     return 0;
 }