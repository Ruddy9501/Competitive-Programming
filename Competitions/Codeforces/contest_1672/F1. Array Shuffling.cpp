/*
https://codeforces.com/contest/1672/problem/F1
2022-04-25 11:40:47
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;

int cas, n, a[RAN];
set <int> s;
vector <int> v[RAN];

int main(){
    
    
    cin >> cas;
    while (cas--){
           cin >> n;
           for (int i = 0; i < n; ++i){
                cin >> a[i];
                s.insert(a[i]);
                v[a[i]].push_back(i);
           }
           
           while (!s.empty()){
               
               vector <int> e, v1;
               
               for (auto u : s){
                    v1.push_back (*v[u].rbegin());
                    v[u].pop_back();
                    if (v[u].empty()) e.push_back (u);
               }
               
               for (int i = 0; i < (int)e.size(); ++i) s.erase(s.find(e[i]));
               
               int l = (int)v1.size();
               int aux = a[v1[l - 1]];
               for (int i = 0; i < l; ++i){
                    int aux_ = a[v1[i]];
                    a[v1[i]] = aux;
                    aux = aux_;
               }
           }
           
           for (int i = 0; i < n; ++i){
                cout << a[i] << " ";
                v[a[i]].clear();
           }
    }

    return 0;
}
