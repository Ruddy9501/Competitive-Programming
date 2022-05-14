/*
2015-11-04 20:21:11
https://codeforces.com/contest/593/problem/A
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
 
using namespace std;
 
struct par{
       string s;
       int t;
       bool operator <(const par &R)const{
            return s < R.s;
       }
}S[10000];
 
int t, n, sol, con, c, la;
char A[10005];
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%s", A);
         la = strlen (A);
         sort (A,A+la);
         c = 1;
         for (int j = 1; j < la; j++)
              if (A[j-1] != A[j]) c++;
         if (c > 2) continue;
         con++;
         S[con].s = A[0], S[con].t = la;
        // cout << S[con].s[0] << " " << S[con].s[1]<<endl;
         for (int j = 1; j < la; j++)
              if (A[j-1] != A[j])
                  S[con].s+=A[j];
       // cout << S[con].s << " " << S[con].t<<endl;
        // cout << S[con].s[0] << " " << S[con].s[1]<<endl;
   }
 
    sol = 0; t = 0;
    for (int i = 0; i <= 27; i++)
    for (int j = i; j <= 27; j++){
         for (int k = 1; k <= con; k++){
              bool mar = true;
              for (int r = 0; r < S[k].s.size(); r++)
                   if (S[k].s[r] != i+'a' && S[k].s[r] != j+'a') mar = false;
              if (mar) t+=S[k].t;
         }
         sol = max(sol, t);t = 0;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}