/*
2017-08-16 20:02:49
https://codeforces.com/contest/342/problem/E
*/
# include <bits/stdc++.h>
using namespace std;
 
const int oo = 1 << 30;
const int RAN = 1e5 + 5;
 
typedef pair<int, int> par;
 
int subsize[RAN], Ant[RAN], S[RAN], sol[RAN], B[RAN], A[RAN], ref_pos, n, x, y;
vector <int> v[RAN];
bool mk[RAN];
 
 
 struct LCA {
    int T[RAN][20], L[RAN];
 
    void DFS (int np, int prev){
         L[np] = L[prev]+1;
         int l = v[np].size();
         for (int i = 0; i < l; i++){
             int nh = v[np][i];
             if (nh != prev)
                 DFS (nh, np);   
        }
 
        T[np][0] = prev;
     }
 
    void Build(int n){
         DFS (1, 0);
         int lg = log2(n);
         for (int j = 1; j <= lg; j++)
             for (int i = 1; i <= n; i++)
                  if (T[i][j-1])
                      T[i][j] = T[T[i][j-1]][j-1];
    }
 
     int Query (int x, int y){
         int sol = 0;
         if (L[x] < L[y]) swap(x, y);
 
         int lg = (int)log2(L[x]);
         
         for (int i = lg; i >= 0; i--)
             if (L[x] - (1 << i) >= L[y] && T[x][i])
                 x = T[x][i], sol += (1 << i);
        
         if (x == y) return sol;
 
         for (int i = lg; i >= 0; i--)
             if (T[x][i] != T[y][i] && T[x][i])
                 x = T[x][i], y = T[y][i], sol += (1 << (i+1));
 
         return sol+2;
     }
 }Lc;
 
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
 
void DFS3 (int centroid, int np, int ant, int dis){
 
    int l = v[np].size();
    for (int i = 0; i < l; i++){
         int nh = v[np][i];
         if (nh != ant && !mk[nh])
             DFS3 (centroid, nh, np, dis+1);
    }
 
    if (np == 1)
        S[centroid] = dis; 
 
}
 
void Descomposition (int root, int prev){
 
     ref_pos = root;
     DFS1 (root, root);
     int centroid = DFS2 (root, root);
     
     S[centroid] = Lc.Query (centroid, 1); 
 
     Ant[centroid] = prev;
     mk[centroid] = true;
     int l = v[centroid].size();
     for (int i = 0; i < l; i++){
          int nh = v[centroid][i];
          if (!mk[nh])
              Descomposition(nh, centroid);
     }
}
 
 void Update (int x){
     int y = x;
     while (y > 0){
            
            int dis = Lc.Query (x, y);
            S[y] = min (dis, S[y]);
 
            y = Ant[y];
     }
}
 
int Query (int x){
    int y = x;
    int sol = oo;
    while (y > 0){
           
           int dis = Lc.Query (x, y); 
           sol = min (sol, dis + S[y]);
 
           y = Ant[y];
    }   
    return sol;
 }
 
int Q, a, b, id, nd;
 
int main(){
 
    scanf ("%d%d", &n, &Q);
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
    }
    
    Lc.Build (n);
    fill (S+1,S+n+1, oo);
    Descomposition (1, -1);
    
    
    while (Q--){
           scanf ("%d%d", &id, &nd);
           if (id == 1)
               Update (nd);
            else
               printf ("%d\n", Query (nd)); 
    }
 
    return 0;
 }