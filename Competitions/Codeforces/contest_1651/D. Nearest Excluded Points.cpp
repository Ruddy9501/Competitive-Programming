/*
2022-03-11 13:27:47
https://codeforces.com/contest/1651/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const long long RAN = 2 * 1e5 + 5;
const int oo = 1<<30;
const int mx[] = {1, 0, -1, 0},
          my[] = {0, -1, 0, 1};
 
int n, pos, x, y, a[RAN], b[RAN], sx[RAN], sy[RAN];
bool mar[RAN];
 
struct tres{
       int x, y, pos;
};
 
typedef pair<int, int> par;
 
queue <tres> q;
map <par, int> m;
vector <int> v[RAN];
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i){
         scanf ("%d%d", &a[i], &b[i]);
         q.push((tres){a[i], b[i], i});
         m[par(a[i], b[i])] = i;
    }
 
    for (int i = 1; i <= n; ++i){
         for (int j = 0; j < 4; ++j){
              int nx = a[i] + mx[j];
              int ny = b[i] + my[j];
              if (!m.count(par(nx, ny))){
                  sx[i] = nx;
                  sy[i] = ny;
                  mar[i] = true;
              }
 
              if (m.count(par(nx, ny)))
                  v[i].push_back (m[par(nx, ny)]);
         }
    }
 
    for (int j = 1; j < 500; ++j)
    for (int i = 1; i <= n; ++i){
           x = a[i];
           y = b[i];
           pos = i;
           for (int k = 0; k < (int)v[i].size(); ++k){
                int n_pos = v[i][k];
                if (mar[n_pos]){
                    int xx = abs (a[i] - sx[i]) + abs(b[i] - sy[i]);
                    int yy = abs (a[i] - sx[n_pos]) + abs(b[i] - sy[n_pos]);
                    if (!mar[pos] || xx > yy){
                        sx[pos] = sx[n_pos];
                        sy[pos] = sy[n_pos];
                    }
                    mar[pos] = true;
                }
           }
    }
 
 
    for (int i = 1; i <= n; ++i)
         printf ("%d %d\n", sx[i], sy[i]);
 
 
    return 0;
}