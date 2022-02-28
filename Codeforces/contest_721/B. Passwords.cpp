/*
2016-09-30 17:35:57
https://codeforces.com/contest/721/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
long long n, k, a, sol, con;
string A[10000], pas;
int  S[1000005];
int main (){
    cin >> n >> k; char car;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    cin >> pas;
    int a = pas.size();
     int s1 =0, s2 = 0;
    for (int i = 1; i <= n; i++){
         if (A[i].size() < a) s1++;
         if (A[i].size() <= a) s2++;
    }
 
    cout << s1+1+(s1/k)*5 << " " << s2+((s2-1)/k)*5;
 
    return 0;
}