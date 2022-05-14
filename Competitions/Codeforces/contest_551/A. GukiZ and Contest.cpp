/*
2015-06-12 19:53:54
https://codeforces.com/contest/551/problem/A
*/
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n, S[5000];
 
struct par{
       int v, p;
       bool operator <(const par &R)const{
            return R.v < v;
       }
}A[5000];
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> A[i].v;
         A[i].p = i;
    }
    sort (A+1,A+n+1);
 
 
    S[A[1].p] = 1;
    for (int i = 2; i <= n; i++){
         if (A[i].v == A[i-1].v)
             S[A[i].p] = S[A[i-1].p];
         else S[A[i].p] = i;
    }
 
    cout << S[1];
    for (int i = 2; i<=n; i++) cout << " " << S[i];
    cout << endl;
 
    return 0;
}