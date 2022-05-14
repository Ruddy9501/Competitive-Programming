/*
2016-10-17 19:17:28
https://codeforces.com/contest/732/problem/D
*/
# include <bits/stdc++.h>
 using namespace std;
 
int n, m, A[1000005], B[1000005], ini, fin, piv, sol = -1;
 
 struct par{
        int p, id;
        bool operator <(const par &R)const{
             return p < R.p;
        }
 }S[1000005];
 
 bool solv(int d){
 
      for (int i = 1; i <= m; i++)
           S[i].p = -1;
 
      for (int i = 1; i <= d; i++)
           S[A[i]].p = i, S[A[i]].id = A[i];
      sort (S+1,S+m+1);
 
      if (S[1].p == -1) return false;
 
      for (int i = 1; i <= m; i++){
           if (i == 1)
               d = S[i].p-1;
            else d += (S[i].p-S[i-1].p-1);
 
           if (d < B[S[i].id]) return false;
 
           d -= B[S[i].id];
      }
 
      return true;
 }
 
 int main(){
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    for (int i = 1; i <= m; i++)
         cin >> B[i];
 
    ini = 1; fin = n;
    while (ini <= fin){
           piv = (ini+fin)/2;
           if (solv(piv)) sol = piv, fin = piv-1;
            else ini = piv+1;
    }
 
    cout << sol <<endl;
 
    return 0;
 }