/*
2017-06-26 03:46:39
https://codeforces.com/contest/821/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
#define int64 long LONG_LONG_MAX
 
int n, A[100][100];
vector <int> v1, v2;
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
              scanf ("%d", &A[i][j]);
 
 
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++){
              v2.clear();
              v1.clear();
              for (int k = 1; k <= n; k++){
                   v2.push_back(A[k][j]);
                   v1.push_back(A[i][k]);
              }
 
              bool ok = false;
              for (int k = 0; k < v1.size(); k++){
                   for (int l = 0; l < v2.size(); l++)
                        if (A[i][j] == v1[k]+v2[l] || A[i][j] == 1) ok = true;
              }
 
 
              if (!ok){
                  printf ("No\n");
                  return 0;
              }
 
         }
    }
 
    printf ("Yes\n");
 
    return 0;
}