/*
2017-01-31 22:00:30
https://codeforces.com/contest/761/problem/C
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int RAN = 100;
 
int n, m, D[RAN][5];
char A[RAN][RAN];
 
int id(char car){
    if (car >= '0' && car <= '9') return 1;
    if (car >= 'a' && car <= 'z') return 2;
    return 3;
}
 
int main() {
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
         cin >> A[i];
 
    for (int i = 0; i < n; i++)
         D[i][1] = D[i][2] = D[i][3] = 1000;
 
    for (int i = 0; i < n; i++){
         for (int j = 0; j < m; j++){
              int pos = id(A[i][j]);
              D[i][pos] = min(D[i][pos], min(m-j, j));
         }
    }
 
   /* for (int i = 0; i < n; i++)
         cout << D[i][1] << " " << D[i][2] << " " << D[i][3] << "\n";*/
 
    int sol = 1000;
    for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
              for (int k = 0; k < n; k++){
                    if (i == j || i == k || j == k) continue;
                    sol = min (sol, D[i][1] + D[j][2]+D[k][3]);
              }
 
    cout << sol << "\n";
 
    return 0;
}