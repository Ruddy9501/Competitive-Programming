/*
2017-11-17 06:07:33
https://codeforces.com/contest/178/problem/B3
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
int n, m, t, x, y, q, id[MAX], ran[MAX], td[MAX], low[MAX], ed[MAX], mk[MAX], p[MAX][20], dp[MAX][20], l[MAX], lg[MAX]; 
vector <pair <int, int> > g[MAX], g1[MAX];
 
void dfs (int u) {
	 td[u] = low[u] = ++t;
 
	 for (auto o : g[u]) {
		  int v = o.first;
		  int id = o.second;
 
		  if (!low[v]) {
		 	  ed[id] = 1;
		 	  dfs (v);
 
			  low[u] = min (low[u], low[v]);
 
			  if (low[v] > td[u])
			      mk[id] = true;
		}
 
		else if (!ed[id])
			     low[u] = min (low[u], td[v]);
	}
}
 
void dfs_lca (int u, int lev = 1, int pt = 0, int ok = 0){
     l[u] = lev;
     p[u][0] = pt;
     dp[u][0] = ok;
     //printf ("%d %d\n", u, dp[u][0]);
     for (auto v : g1[u])
           if (v.first != pt)
               dfs_lca (v.first, lev+1, u, v.second);
		   
}
 
void init_lca (){
     dfs_lca (1);
     
     for (int i = 1; i <= n; i++)
          lg[i] = log2 (i);
     
     for (int j = 1; (1 << j) <= n; j++)
          for (int i = 1; i <= n; i++){
               p[i][j] = p[p[i][j - 1]][j - 1];
		       dp[i][j] = dp[i][j - 1] + dp[p[i][j - 1]][j - 1]; 
		  }      
}
 
int lca (int a, int b){
    if (l[a] < l[b])
        swap (a, b);
    
    int sol = 0;    
    for (int i = lg[l[a]]; i >= 0; i--)
         if (l[a] - (1 << i) >= l[b]){
             sol += dp[a][i];
             a = p[a][i];     
		 }
		 
    if (a == b)
        return sol;		 
 	
	for (int i = lg[l[a]]; i >= 0; i--)
	     if (p[a][i] && p[a][i] != p[b][i]){
		     sol = sol + dp[a][i] + dp[b][i];
		     a = p[a][i], b = p[b][i];
		 }
		 
    return sol + dp[a][0] + dp[b][0]; 		 
}
 
int find_set (int x){
     if (x == id[x]) return x;
     return id[x] = find_set (id[x]);
}
 
void joind_set (int x, int y){
     if (ran[x] < ran[y])
         swap (x, y);
     ran[x] += ran[y];
     id[y] = x;    
}
 
int main(){
    
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d%d", &x, &y);
         g[x].push_back ({y, i});	
         g[y].push_back ({x, i});	
	}
	
	for (int i = 1; i <= n; i++)
	     id[i] = i, ran[i] = 1;
	
	dfs (1);
    for (int i = 1; i <= n; i++){
	     for (auto v : g[i]){
	          x = find_set (i);
	          y = find_set (v.first);
	          if (x != y){
			      joind_set (x, y);
			      g1[i].push_back ({v.first, mk[v.second]});
			      g1[v.first].push_back ({i, mk[v.second]});
			    //  printf ("%d %d %d\n", i, v.first, mk[v.second]);
			  }
		  }
	}
	
	init_lca ();
	
	scanf ("%d", &q);
	while (q--){
           scanf ("%d%d", &x, &y);
           printf ("%d\n", lca (x, y));
    }
    
    return 0; 
}