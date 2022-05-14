/*
2017-08-16 20:14:57
https://codeforces.com/contest/321/problem/C
*/
# include <bits/stdc++.h>
using namespace std;
 
const int oo = 1 << 30;
const int RAN = 1e5 + 5;
 
typedef pair<int, int> par;
 
int subsize[RAN], Ant[RAN], S[RAN], sol[RAN], B[RAN], A[RAN], ref_pos, n, x, y;
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
 
void Descomposition (int root, int prev){
 
     ref_pos = root;
     DFS1 (root, root);
     int centroid = DFS2 (root, root);
 
     Ant[centroid] = prev;
     S[centroid] = S[prev] + 1;
     mk[centroid] = true;
     int l = v[centroid].size();
     for (int i = 0; i < l; i++){
          int nh = v[centroid][i];
          if (!mk[nh])
              Descomposition(nh, centroid);
     }
}
 
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
    }
    
    S[0] = -1;
    Descomposition (1, 0);
 
    for (int i = 1; i <= n; i++)
         if (i == n) printf ("%c\n", S[i]+'A');
          else printf ("%c ", S[i]+'A');
    
    return 0;
 }