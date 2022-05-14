/*
2017-01-19 18:12:03
https://codeforces.com/contest/758/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, sol, ma, A[10000], tot;
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         ma = max(ma, A[i]);
    }//cout << ma << endl;
    for (int i = 1; i <= n; i++){
         sol += abs(ma-A[i]);
    }
 
    printf ("%d\n", sol);
 
    return 0;
}