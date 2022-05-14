/*
2017-02-02 17:25:33
https://codeforces.com/contest/764/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
int n, A[RAN], a, b, C[RAN], S[RAN];
vector <int> v[RAN];
bool M[RAN];
 
void dfs(int nod){
     M[nod] = true;
     for (int i = 0; i < v[nod].size(); i++){
          int newn = v[nod][i];
 
          if (A[newn] == A[nod]){
              if (M[newn]) continue;
              dfs(newn);
          }
           else
              S[newn]++;
     }
}
 
int main(){
 
    cin >> n;
    for (int i = 1; i < n; i++){
         cin >> a >> b;
         v[a].push_back(b);
         v[b].push_back(a);
         C[a]++, C[b]++;
    }
 
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    bool mar = true;
    for (int i = 1; i <= n; i++){
         if (A[i] != A[1]) mar = false;
    }
 
    if (mar){
        cout << "YES\n";
        cout << 1;
        return 0;
    }
 
    int sol = 0, c = 0;
    for (int i = 1; i <= n; i++){
         if (C[i] == 1 && !M[i]){
             dfs(i); c++;
         }
    }
 
    for (int i = 1; i <= n; i++){
         if (!M[i]){
             if (S[i] == c){
                 sol = i;
                 break;
             }
         }
          else{
            if (S[i] == c-1){
                sol = i;
                break;
            }
          }
    }
 
    if (sol == 0){
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    cout << sol << "\n";
 
    return 0;
}