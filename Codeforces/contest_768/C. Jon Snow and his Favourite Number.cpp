/*
2017-02-22 03:55:53
https://codeforces.com/contest/768/problem/C
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n, k, x, A[2<<10+5], B[1<<10+5], a, mi, ma;
 
int main(){
 
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++){
         cin >> a;
         A[a]++;
    }
    while (k--){
           a = 0;
           fill (B, B + (1<<10) + 1, 0);
           for (int i = 0; i <= 1<<10; i++){
                if (a%2==0){
                    B[i^x] += (A[i]+1)/2;
                    B[i] += A[i]/2;
                }
                else{
                    B[i^x] += A[i]/2;
                    B[i]   += (A[i]+1)/2;
                }
                a += A[i];
           }
 
 
           for (int i = 0; i < 1<<10; i++)
                A[i] = B[i];
 
    }
 
    mi = ma = -1;
    for (int i = 0; i < 1<<10; i++){
         if (A[i] && mi == -1) mi = i;
         if (A[i]) ma = i;
    }
 
    cout << ma << " " << mi << "\n";
    return 0;
}