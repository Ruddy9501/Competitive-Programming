/*
2017-02-07 20:36:54
https://codeforces.com/contest/766/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
const int MOD = 1e9+7;
 
int la, B[RAN], s2, S3[RAN];
char A[RAN];
long long S[RAN];
 
bool is_ok(int fin, int t){
     for (int i = fin; i > fin-t; i--)
          if (B[A[i]-'a'] < t) return false;
     return true;
}
 
int main(){
 
   cin >> la;
   cin >> A + 1;
   for (int i = 0; i < 26; i++) cin >> B[i];
 
   S[0] = 1;
   fill (S3+1,S3+la+1,1<<30);
   for (int i = 1; i <= la; i++){
        for (int j = 1; j <= i; j++){
             if (is_ok(i, j)){
                 S[i] = (S[i] + S[i-j])%MOD;
                 S3[i] = min(S3[i], S3[i-j]+1);
                 s2 = max(s2, j);
             }
        }
   }
 
   cout << S[la] << "\n";
   cout << s2 << "\n";
   cout << S3[la] << "\n";
 
   return 0;
}