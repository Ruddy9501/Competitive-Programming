/*
2015-11-24 19:45:42
https://codeforces.com/contest/602/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long n, m, A[1000], num1, num2, mul;
 
int main(){
 
    cin >> n >> m;
    mul = 1;
    for (int i = 1;  i <= n; i++)
         cin >> A[i];
 
 
    for (int i = n;  i >= 1; i--){
 
         num1 += mul*A[i];
         mul*=m;
    }
 
    cin >> n >> m;
    mul = 1;
    for (int i = 1;  i <= n; i++){
         cin >> A[i];
    }
 
    for (int i = n;  i >= 1; i--){
         num2 += mul*A[i];
         mul*=m;
    }
 
    if (num1==num2) cout <<"="<<endl;
     else if (num1 > num2) cout << ">" << endl;
          else cout << "<" << endl;
 
    return 0;
}