/*
2017-08-29 17:15:58
https://codeforces.com/contest/766/problem/E
*/

# include <bits/stdc++.h>
using namespace std;
 
const int oo = 1 << 30;
const int RAN = 1e5 + 5;
 
typedef pair<int, int> par;
 
int subsize[RAN], Ant[RAN], BIT, Dp[RAN][3], Tm[RAN][3], A[RAN], ref_pos, n, x, y;
vector <int> v[RAN];
bool mk[RAN];
long long sol = 0;
 
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
 
int is_ok(int n, int BIT){
    if (n & (1<<BIT)) 
        return 1;
    return 0; 
}
 
void DFS3 (int centroid, int np, int prev, int x){
     int l = v[np].size();
     for (int i = 0; i < l; i++){
          int nh = v[np][i];
 
          if (nh != prev && !mk[nh])
              DFS3 (centroid, nh, np, x ^ A[nh]);    
     }
 
     for (int i = 0; i < 20; i++) {
          if (is_ok(x, i))
              sol += (1<<i);
          Tm[i][is_ok(x, i)]++;
     }    
}
 
void Descomposition (int root, int prev){
 
     ref_pos = root;
     DFS1 (root, root);
     int centroid = DFS2 (root, root);
     
     sol += A[centroid];
     
     Ant[centroid] = prev;
     mk[centroid] = true;
     int l = v[centroid].size();
     for (int j = 0; j < l; j++){
          int nh = v[centroid][j];
 
          if (mk[nh]) continue;
 
          DFS3 (centroid, nh, centroid, A[centroid] ^ A[nh]);
 
          for (int i = 0; i < 20; i++){
               int b = is_ok (A[centroid], i);
               for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                         if (b^j^k){
                             sol = sol + 1ll*(Dp[i][j] * Tm[i][k]) * (1 << i);
                         }
 
              Dp[i][0] += Tm[i][0];
              Dp[i][1] += Tm[i][1];
              Tm[i][0] = 0;
              Tm[i][1] = 0;
          }  
      }
 
     for (int i = 0; i < 20; i++)
          Dp[i][0] = Dp[i][1] = 0;
 
     for (int i = 0; i < l; i++){
          int nh = v[centroid][i];
          if (!mk[nh])
               Descomposition(nh, centroid);
     }
}
 
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);
 
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
    }
    
   
    Descomposition (1, 0);
 
    printf ("%lld\n", sol);
    
    return 0;
 }