/*
2017-03-18 20:24:53
https://codeforces.com/contest/791/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e6+5;
 
int n, m, a, b, can;
long long nnod, aris;
bool M[RAN];
queue <int> Q;
vector <int> v[RAN];
 
void bfs(int nod){
     Q.push(nod);
     while (!Q.empty()){
            nod = Q.front();
            Q.pop();
            nnod++;
            M[nod] = true;
            for (int i = 0; i < v[nod].size(); i++){
                 int newn = v[nod][i];
                 aris++;
                 if (!M[newn]){
                     Q.push(newn);
                     M[newn] = true;
                 }
            }
     }
}
 
int main(){
 
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
         cin >> a >> b;
         v[a].push_back(b);
         v[b].push_back(a);
    }
 
    for (int i = 1; i <= n; i++){
         if (!M[i]){
             nnod = 0ll;
             aris = 0ll;
             bfs (i);
             if (nnod*(nnod-1ll)  != aris){
                 cout << "NO\n";
                 return 0;
             }
         }
    }
 
    cout << "YES\n";
 
    return 0;
}