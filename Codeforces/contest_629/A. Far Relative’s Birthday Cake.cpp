/*
2016-03-24 18:08:02
https://codeforces.com/contest/629/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int n;
char A[1000][1000];
long long sol;
int main(){
 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
 
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
         if (A[i][j]=='C')
             for (int k = 1; min(i, j)+k < n; k++){
                  if (A[i+k][j] == 'C')sol++;
                  if (A[i][j+k] == 'C')sol++;
             }
    }
 
    cout << sol << endl;
    return 0;
}