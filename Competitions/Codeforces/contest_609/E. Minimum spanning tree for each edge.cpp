/*
2017-11-17 16:59:28
https://codeforces.com/contest/609/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
const int MAX = 2e5 + 5;
int n, m, x, y, id[MAX], ran[MAX], p[MAX][20], l[MAX], lg[MAX];
int64 z, tot, may[MAX][20];
map <pair<int, int>, bool > M;
vector <pair<int, int64> > g[MAX];
 
struct tre{
       int x, y;
       int64 z;
       bool operator <(const tre &r)const{
	        return z < r.z;
	   }
};
 
vector <tre> a, b;
 
int find_set (int x){
    if (id[x] == x) return x;
    return id[x] = find_set (id[x]); 
}
 
void joind_set (int x, int y){
     if (ran[x] < ran[y])
         swap (x, y);
         
     ran[x] += ran[y];
     id[y] = x;   
}
 
void dfs_lca (int u, int lev = 1, int pt = 0, int cost = 0){
     p[u][0] = pt;
     l[u] = lev;
     may[u][0] = cost;
     
     for (auto v : g[u])
          if (v.first != pt)
              dfs_lca (v.first, lev + 1, u, v.second);     
}
 
void init_lca (){
     dfs_lca (1);
     
     for (int i = 1; i <= n; i++)
          lg[i] = log2 (l[i]);
          
     for (int j = 1; (1 << j) <= n; j++)
          for (int i = 1; i <= n; i++){
               p[i][j] = p[p[i][j - 1]][j - 1];
		       may[i][j] = max (may[i][j - 1], may[p[i][j - 1]][j - 1]);
		  }      
}
 
int64 lca (int a, int b){
    if (l[a] < l[b])
        swap (a, b);
    
    int64 sol = 0;
    for (int i = lg[a]; i >= 0; i--)
         if (l[a] - (1 << i) >= l[b]){
		     sol = max (sol, may[a][i]);
		     a = p[a][i];
		 }          
		 
    if (a == b) 
        return sol;		 
    
    for (int i = lg[a]; i >= 0; i--)
         if (p[a][i] && p[a][i] != p[b][i]){
		     sol = max (sol, max (may[a][i], may[b][i]));
		     a = p[a][i], b = p[b][i]; 
		 } 
		 
     return max (sol, max (may[a][0], may[b][0]));		 
}
 
int main(){
    
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
         scanf ("%d %d %lld", &x, &y, &z);
         a.push_back ((tre){x, y, z});
         b.push_back ((tre){x, y, z});
    }
    
    for (int i = 1; i <= n; i++)
         id[i] = i, ran[i] = 1;
    
    sort (a.begin(), a.end());
    for (auto v : a){
         x = find_set (v.x);
         y = find_set (v.y);
         if (x != y){
		     joind_set (x, y);
		     tot += v.z;
		     M[{v.x, v.y}] = true; 
		     M[{v.y, v.x}] = true; 
		     g[v.x].push_back ({v.y, v.z});
		     g[v.y].push_back ({v.x, v.z});
		 }
    }
    
    init_lca ();
    for (auto v : b){
	     x = v.x;
	     y = v.y;
	     z = v.z;
	     if (M.count ({x, y})) 
	         printf ("%lld\n", tot); 
	      else{
		     int64 s = lca (x, y);
		     printf ("%lld\n", tot - s + z);
		  }
	}
    
    return 0;
 }