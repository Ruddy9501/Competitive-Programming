/*
2016-10-03 21:53:18
https://codeforces.com/contest/723/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, m, sol;
bool M[100005];
int A[10005],d,r, C[100005], B[100005];
int buscar(){
    int i;
    for ( i = 1; i <= m; i++){
         if (C[i] < d) break;
    }
    if (m+1 == i) return -1;
    return i;
}
 
int main(){
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    d = n/m;
    //r = n%m;
 
    for (int i = 1; i <= n; i++){
         B[i] = A[i];
         if (A[i] > m){
             M[i] = true;
             continue;
         }
         C[A[i]]++;
         if (C[A[i]] > d){
             M[i] = true;
         }
    }
 
    int sol1 = 0;
    for (int i = 1; i <= n; i++){
         if (M[i]){
             int p = buscar();
             if (p == -1)continue;
             B[i] = p;
             C[p]++;
         }
         if (A[i] != B[i]) sol++;
         //if (A[i] != 1) sol1++;
    }
 
    /*if (C[1] == d && n%m > 0){
        for (int i = 1; i <= n;i++){
             if (!M[i] && C[A[i]] > d && A[i] != 1){
                 sol++;
                 C[1]++;
                 B[i] = 1;
                 break;
             }
        }
    }*/
 
    cout << n/m << " " <<sol << endl;
    for (int i = 1; i <= n; i++)
         if (i == 1) cout << B[i];
         else cout << " " << B[i] ;
 
    return 0;
}