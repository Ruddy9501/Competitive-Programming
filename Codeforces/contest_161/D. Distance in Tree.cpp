/*
2017-08-31 18:30:58
https://codeforces.com/contest/161/problem/D
*/
# include <bits/stdc++.h>
using namespace std;
 
const int oo = 1 << 30;
const int RAN = 1e5 + 5;
 
typedef pair<int, int> par;
 
int subsize[RAN], Ant[RAN], C[RAN], k, B[RAN], A[RAN], ref_pos, n, x, y, sol;
vector <int> v[RAN];
bool mk[RAN];
 
 
void DFS1(int np, int prev){
     subsize[np] = 1;
     int l = v[np].size();
     for(int i = 0; i < l; i++){
         int nh = v[np][i];
         if (nh != prev && !mk[nh]){
             DFS1(nh, np);
             subsize[np] += subsize[nh];
        }
    }
 }
 
int DFS2(int np, int prev){
 
    int l = v[np].size();
    for (int i = 0; i < l; i++){
         int nh = v[np][i];
         if (nh != prev && !mk[nh] && subsize[nh] > subsize[ref_pos]/2)
             return DFS2(nh, np);
    }
 
    return np;
}
 
void DFS3 (int nd, int np, int dis){
     sol += C[k-dis];
     int l = v[nd].size();
     for (int i = 0; i < l; i++){
          int nh = v[nd][i];
          if (nh != np && dis < k && !mk[nh])
              DFS3 (nh, nd, dis+1);
     }
}
 
void DFS4 (int nd, int np, int dis){
     C[dis]++;
     int l = v[nd].size();
     for (int i = 0; i < l; i++){
          int nh = v[nd][i];
          if (nh != np && dis < k && !mk[nh])
              DFS4 (nh, nd, dis+1);
     }
}
 
 
void Descomposition (int root, int prev){
 
     ref_pos = root;
     DFS1 (root, root);
     int centroid = DFS2 (root, root);
 
 
     Ant[centroid] = prev;
     mk[centroid] = true;
     int l = v[centroid].size();
     fill (C, C+k+1, 0);
     C[0] = 1;
     for (int i = 0; i < l; i++){
          int nh = v[centroid][i];
          if (!mk[nh]){
              DFS3 (nh, centroid, 1);
              DFS4 (nh, centroid, 1);
 
          }
     }
 
     for (int i = 0; i < l; i++){
          int nh = v[centroid][i];
          if (!mk[nh])
              Descomposition(nh, centroid);
     }
}
 
 
int main(){
 
    scanf ("%d%d", &n, &k);
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
    }
 
    Descomposition (1, 0);
 
    printf ("%d\n", sol);
 
 
    return 0;
 }