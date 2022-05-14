/*
2015-11-24 20:25:28
https://codeforces.com/contest/602/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int oo = 1<<29;
int n, m, nod, newn, C[10000], C1[10000];
bool M[1000][1000];
vector <int> V1[1000], V[10000];
queue <int> Q;
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
         cin >> nod >> newn;
         V[nod].push_back(newn);
         V[newn].push_back(nod);
         M[nod][newn] = true;
         M[newn][nod] = true;
    }
 
    for (int i = 1; i <= n; i++)
         for (int j = i+1; j <= n; j++)
              if (!M[i][j]) V1[i].push_back(j), V1[j].push_back(i);
 
    fill (C,C+n+1, oo);
    fill (C1,C1+n+1, oo);
 
    C1[1] = C[1] = 0;
    Q.push(1);
    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           int l = V[nod].size();
           for (int i = 0; i < l; i++){
                newn = V[nod][i];
                if (C[newn] > C[nod]+1){
                    C[newn] = C[nod]+1;
                    Q.push(newn);
                }
           }
    }
 
    Q.push(1);
    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           int l = V1[nod].size();
           for (int i = 0; i < l; i++){
                newn = V1[nod][i];
                if (C1[newn] > C1[nod]+1){
                    C1[newn] = C1[nod]+1;
                    Q.push(newn);
                }
           }
    }
 
    if (C[n]==oo||C1[n]==oo) cout << "-1"<<endl;
     else cout << max(C1[n],C[n])<<endl;
 
    return 0;
}